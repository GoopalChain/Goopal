#include <blockchain/AccountOperations.hpp>
#include <blockchain/AssetOperations.hpp>
#include <blockchain/BalanceOperations.hpp>

#include <blockchain/SlateOperations.hpp>
#include <blockchain/Time.hpp>
#include <blockchain/Transaction.hpp>
#include <blockchain/ImessageOperations.hpp>
#include <fc/io/raw_variant.hpp>


namespace goopal { namespace blockchain {

   DigestType Transaction::digest( const DigestType& chain_id )const
   {
      fc::sha256::encoder enc;
      fc::raw::pack(enc,*this);
      fc::raw::pack(enc,chain_id);
      return enc.result();
   }

   TransactionIdType SignedTransaction::id()const
   {
      fc::sha512::encoder enc;
      fc::raw::pack( enc, *this );
      return fc::ripemd160::hash( enc.result() );
   }

   size_t SignedTransaction::data_size()const
   {
      fc::datastream<size_t> ds;
      fc::raw::pack(ds,*this);
      return ds.tellp();
   }

   void SignedTransaction::sign( const fc::ecc::private_key& signer, const DigestType& chain_id )
   {
      signatures.push_back( signer.sign_compact( digest( chain_id ) ) );
   }

   PublicKeyType SignedTransaction::get_signing_key( const size_t sig_index, const DigestType& chain_id )const
   { try {
       return fc::ecc::public_key( signatures.at( sig_index ), this->digest( chain_id ), false );
   } FC_CAPTURE_AND_RETHROW( (sig_index)(chain_id) ) }

   void Transaction::define_slate( const set<AccountIdType>& slate )
   { try {
       DefineSlateOperation op;
       for( const AccountIdType id : slate ) op.slate.push_back( id );
       // Insert at head because subsequent evaluation may depend on the pending slate entry
       operations.insert( operations.begin(), std::move( op ) );
   } FC_CAPTURE_AND_RETHROW( (slate) ) }


   void Transaction::withdraw( const BalanceIdType& account,
                               ShareType             amount )
   { try {
      FC_ASSERT( amount > 0, "amount: ${amount}", ("amount",amount) );
      operations.emplace_back( WithdrawOperation( account, amount ) );
   } FC_RETHROW_EXCEPTIONS( warn, "", ("account",account)("amount",amount) ) }

   void Transaction::withdraw_pay( const AccountIdType account,
                                   ShareType             amount )
   {
      FC_ASSERT( amount > 0, "amount: ${amount}", ("amount",amount) );
      operations.emplace_back( WithdrawPayOperation( amount, account ) );
   }

   void Transaction::deposit( const Address& owner, const Asset& amount )
   {
      FC_ASSERT( amount.amount > 0, "amount: ${amount}", ("amount",amount) );
      operations.emplace_back( DepositOperation( owner, amount ) );
   }

   void Transaction::deposit_multisig( const MultisigMetaInfo& multsig_info, const Asset& amount )
   {
      FC_ASSERT( amount.amount > 0, "amount: ${amount}", ("amount",amount) );
      DepositOperation op;
      op.amount = amount.amount;
      op.condition = WithdrawCondition( WithdrawWithMultisig{multsig_info.required,multsig_info.owners}, amount.asset_id );
      operations.emplace_back( std::move( op ) );
   }


   PublicKeyType Transaction::deposit_to_account( fc::ecc::public_key receiver_key,
                                                    Asset amount,
                                                    fc::ecc::private_key from_key,
                                                    const std::string& memo_message,
                                                    const fc::ecc::public_key& memo_pub_key,
                                                    fc::ecc::private_key one_time_private_key,
                                                    MemoFlagsEnum memo_type,
                                                    bool use_stealth_address )
   {
      WithdrawWithSignature by_account;
      auto receiver_address_key = by_account.encrypt_memo_data( one_time_private_key,
                                                                receiver_key,
                                                                from_key,
                                                                memo_message,
                                                                memo_pub_key,
                                                                memo_type,
                                                                use_stealth_address );

      DepositOperation op;
      op.amount = amount.amount;
      op.condition = WithdrawCondition( by_account, amount.asset_id );
      operations.emplace_back( std::move( op ) );
      return receiver_address_key;
   }
   void Transaction::release_escrow( const Address& escrow_account,
                                     const Address& released_by,
                                     ShareType amount_to_sender,
                                     ShareType amount_to_receiver )
   {
       ReleaseEscrowOperation op;
       op.escrow_id          = escrow_account;
       op.released_by        = released_by;
       op.amount_to_receiver = amount_to_receiver;
       op.amount_to_sender   = amount_to_sender;
       operations.emplace_back( std::move( op ) );
   }

   PublicKeyType Transaction::deposit_to_escrow(
                                        fc::ecc::public_key receiver_key,
                                        fc::ecc::public_key escrow_key,
                                        DigestType agreement,
                                        Asset amount,
                                        fc::ecc::private_key from_key,
                                        const std::string& memo_message,
                                        const fc::ecc::public_key& memo_pub_key,
                                        fc::ecc::private_key one_time_private_key,
                                        MemoFlagsEnum memo_type
                                      )
   {
      withdraw_with_escrow by_escrow;
      auto receiver_pub_key = by_escrow.encrypt_memo_data( one_time_private_key,
                                 receiver_key,
                                 from_key,
                                 memo_message,
                                 memo_pub_key,
                                 memo_type );
      by_escrow.escrow = escrow_key;
      by_escrow.agreement_digest = agreement;

      DepositOperation op;
      op.amount = amount.amount;
      op.condition = WithdrawCondition( by_escrow, amount.asset_id );

      operations.emplace_back( std::move( op ) );
      return receiver_pub_key;
   }


   void Transaction::register_account( const std::string& name,
                                       const fc::variant& public_data,
                                       const PublicKeyType& master,
                                       const PublicKeyType& active,
                                       uint8_t pay_rate,
                                       optional<AccountMetaInfo> info )
   {
      RegisterAccountOperation op( name, public_data, master, active, pay_rate );
      op.meta_data = info;
      operations.emplace_back( std::move( op ) );
   }

   void Transaction::update_account( AccountIdType account_id,
                                  uint8_t delegate_pay_rate,
                                  const fc::optional<fc::variant>& public_data,
                                  const fc::optional<PublicKeyType>& active   )
   {
      UpdateAccountOperation op;
      op.account_id = account_id;
      op.public_data = public_data;
      op.active_key = active;
      op.delegate_pay_rate = delegate_pay_rate;
      operations.emplace_back( std::move( op ) );
   }

   void Transaction::create_asset( const std::string& symbol,
                                   const std::string& name,
                                   const std::string& description,
                                   const fc::variant& data,
                                   AccountIdType issuer_id,
                                   ShareType max_share_supply,
                                   uint64_t precision )
   {
      FC_ASSERT( max_share_supply > 0 ,"Max_share_supply must be bigger than 0");
      FC_ASSERT( max_share_supply <= GOP_BLOCKCHAIN_MAX_SHARES,"Max_share_supply must not be bigger than GOP_BLOCKCHAIN_MAX_SHARES!" );
      CreateAssetOperation op;
      op.symbol = symbol;
      op.name = name;
      op.description = description;
      op.public_data = data;
      op.issuer_account_id = issuer_id;
      op.maximum_share_supply = max_share_supply;
      op.precision = precision;
      operations.emplace_back( std::move( op ) );
   }

   void Transaction::update_asset( const AssetIdType asset_id,
                                   const optional<string>& name,
                                   const optional<string>& description,
                                   const optional<variant>& public_data,
                                   const optional<double>& maximum_share_supply,
                                   const optional<uint64_t>& precision )
   {
       operations.emplace_back( UpdateAssetOperation{ asset_id, name, description, public_data, maximum_share_supply, precision } );
   }
   void Transaction::update_asset_ext( const AssetIdType asset_id,
                                   const optional<string>& name,
                                   const optional<string>& description,
                                   const optional<variant>& public_data,
                                   const optional<double>& maximum_share_supply,
                                   const optional<uint64_t>& precision,
                                   const ShareType issuer_fee,
                                   uint16_t market_fee,
                                   uint32_t  flags,
                                   uint32_t issuer_permissions,
                                   AccountIdType issuer_account_id,
                                   uint32_t required_sigs,
                                   const vector<Address>& authority
                                   )
   {
       MultisigMetaInfo auth_info;
       auth_info.required = required_sigs;
       auth_info.owners.insert( authority.begin(), authority.end() );
       UpdateAssetExtOperation op( UpdateAssetOperation{asset_id, name, description, public_data, maximum_share_supply, precision} );
       op.flags = flags;
       op.issuer_permissions = issuer_permissions;
       op.issuer_account_id = issuer_account_id;
       op.transaction_fee = issuer_fee,
       op.market_fee = market_fee;
       op.authority = auth_info;
       operations.emplace_back( std::move( op ) );
   }

   void Transaction::issue( const Asset& amount_to_issue )
   {
      operations.emplace_back( IssueAssetOperation( amount_to_issue ) );
   }


   void Transaction::update_signing_key( const AccountIdType account_id, const PublicKeyType& signing_key )
   {
       operations.emplace_back( UpdateSigningKeyOperation{ account_id, signing_key } );
   }

   void Transaction::update_balance_vote( const BalanceIdType& balance_id, const optional<Address>& new_restricted_owner )
   {
       operations.emplace_back( UpdateBalanceVoteOperation{ balance_id, new_restricted_owner } );
   }

   void Transaction::set_slates( const SlateIdType slate_id )
   {
       for( size_t i = 0; i < operations.size(); ++i )
       {
           const Operation& op = operations.at( i );
           switch( OperationTypeEnum( op.type ) )
           {
               case deposit_op_type:
               {
                   DepositOperation deposit_op = op.as<DepositOperation>();
                   if( deposit_op.condition.asset_id == 0 )
                   {
                       deposit_op.condition.slate_id = slate_id;
                       operations[ i ] = deposit_op;
                   }
                   break;
               }
               case update_balance_vote_op_type:
               {
                   UpdateBalanceVoteOperation update_balance_vote_op = op.as<UpdateBalanceVoteOperation>();
                   update_balance_vote_op.new_slate = slate_id;
                   operations[ i ] = update_balance_vote_op;
                   break;
               }
               default:
               {
                   break;
               }
           }
       }
   }
   void Transaction::AddtionImessage(const string imessage)
   {
	   operations.emplace_back(ImessageMemoOperation{imessage});
   }
   bool Transaction::is_cancel()const
   {
      return false;
   }
  /*  void transaction::authorize_key( asset_id_type asset_id, const address& owner, object_id_type meta )
    {
       authorize_operation op;
       op.asset_id = asset_id;
       op.owner = owner;
       op.meta_id = meta;
       operations.emplace_back( std::move( op ) );
    }*/    //check????

} } // goopal::blockchain
