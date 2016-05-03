#pragma once

#include <blockchain/AccountEntry.hpp>
#include <blockchain/Operations.hpp>
#include <blockchain/SlateEntry.hpp>
#include <blockchain/WithdrawTypes.hpp>
#include <map>
#include <fc/reflect/variant.hpp>

namespace goopal { namespace blockchain {

   struct market_index_key;

   struct Transaction
   {
      fc::time_point_sec    expiration;
      optional<uint64_t>    reserved;
	  string gop_account;
	  //string from_account;
	  Asset gop_inport_asset;
      vector<Operation>     operations;
	  
      DigestType digest( const DigestType& chain_id )const;

      void issue( const Asset& amount_to_issue );

      void define_slate( const set<AccountIdType>& slate );

      void withdraw( const BalanceIdType& account, ShareType amount );

      void withdraw_pay( const AccountIdType account, ShareType amount );

      void deposit( const Address& addr, const Asset& amount );

			//void authorize_key( asset_id_type asset_id, const address& owner, object_id_type meta );

      void deposit_multisig( const MultisigMetaInfo& info, const Asset& amount );

      void release_escrow( const Address& escrow_account,
                           const Address& released_by,
                           ShareType amount_to_sender,
                           ShareType amount_to_receiver );

      PublicKeyType deposit_to_escrow( fc::ecc::public_key receiver_key,
                              fc::ecc::public_key escrow_key,
                              DigestType agreement,
                              Asset amount,
                              fc::ecc::private_key from_key,
                              const string& memo_message,
                              const fc::ecc::public_key& memo_public_key,
                              fc::ecc::private_key one_time_private_key,
                              MemoFlagsEnum memo_type = from_memo );

      PublicKeyType deposit_to_account(fc::ecc::public_key receiver_key,
                                         Asset amount,
                                         fc::ecc::private_key from_key,
                                         const string& memo_message,
                                         const fc::ecc::public_key& memo_public_key,
                                         fc::ecc::private_key one_time_private_key,
                                         MemoFlagsEnum memo_type = from_memo,
                                         bool use_stealth_address = true);


      void register_account( const string& name,
                             const variant& public_data,
                             const PublicKeyType& master,
                             const PublicKeyType& active,
                             uint8_t pay_rate = -1,
                             optional<AccountMetaInfo> info = optional<AccountMetaInfo>() );

      void update_account( AccountIdType account_id,
                        uint8_t delegate_pay_rate,
                        const optional<variant>& public_data,
                        const optional<PublicKeyType>& active );

      void create_asset( const string& symbol,
                         const string& name,
                         const string& description,
                         const variant& data,
                         AccountIdType issuer_id,
                         ShareType max_share_supply,
                         uint64_t precision );

      void update_asset( const AssetIdType asset_id,
                         const optional<string>& name,
                         const optional<string>& description,
                         const optional<variant>& public_data,
                         const optional<double>& maximum_share_supply,
                         const optional<uint64_t>& precision );

      void update_asset_ext( const AssetIdType asset_id,
                         const optional<string>& name,
                         const optional<string>& description,
                         const optional<variant>& public_data,
                         const optional<double>& maximum_share_supply,
                         const optional<uint64_t>& precision,
                         const ShareType issuer_fee,
                         uint16_t market_fee,
                         uint32_t flags,
                         uint32_t issuer_permissions,
                         AccountIdType issuer_account_id,
                         uint32_t required_sigs,
                         const vector<Address>& authority
                         );



      void update_signing_key( const AccountIdType account_id, const PublicKeyType& signing_key );

      void update_balance_vote( const BalanceIdType& balance_id, const optional<Address>& new_restricted_owner );

      void set_slates( const SlateIdType slate_id );
      void AddtionImessage(const string imessage);
			bool is_cancel()const;
		}; // transaction

   struct SignedTransaction : public Transaction
   {
      TransactionIdType   id()const;
      size_t                data_size()const;
      void                  sign( const fc::ecc::private_key& signer, const DigestType& chain_id );
      PublicKeyType       get_signing_key( const size_t sig_index, const DigestType& chain_id )const;
      vector<fc::ecc::compact_signature> signatures;
   };
   typedef vector<SignedTransaction> signed_transactions;
   typedef optional<SignedTransaction> osigned_transaction;
   struct GopTrxidBalance
   {
	   GopTrxidBalance(){};
	   GopTrxidBalance(string gop_account, TransactionIdType trx_id, Asset asset_trx, uint32_t 
	   block_num,string from_account,fc::time_point_sec create_time) :
	       gop_account(gop_account),
		   trx_id(trx_id),
		   asset_trx(asset_trx),
		   block_num(block_num),
		   from_account(from_account),
		   create_time(create_time){};
	   string gop_account;
	   uint32_t block_num;
	   TransactionIdType trx_id;
	   Asset asset_trx;
	   string from_account;
	   fc::time_point_sec create_time;
	   friend bool operator > (const GopTrxidBalance& gopa, const GopTrxidBalance& gopb){
		   return gopa.block_num > gopb.block_num;
	   }
	   friend bool operator < (const GopTrxidBalance& gopa, const GopTrxidBalance& gopb){
		   return gopa.block_num < gopb.block_num;
	   }
	   friend bool operator == (const GopTrxidBalance& gopa, const GopTrxidBalance& gopb){
		   return gopa.block_num == gopb.block_num;
	   }
	   friend bool operator != (const GopTrxidBalance& gopa, const GopTrxidBalance& gopb){
		   return gopa.block_num != gopb.block_num;
	   }
   };
   struct GopBalanceEntry
   {
	   std::set<TransactionIdType> gop_trxid_sort;
	   std::multimap<uint32_t, GopTrxidBalance> gop_block_sort;
   };
   struct TransactionLocation
   {
      TransactionLocation( uint32_t block_num = 0, uint32_t trx_num = 0 )
      :block_num(block_num),trx_num(trx_num){}

      uint32_t block_num;
      uint32_t trx_num;
   };
   typedef optional<TransactionLocation> oTransactionLocation;

} } // goopal::blockchain
FC_REFLECT(goopal::blockchain::GopTrxidBalance,(gop_account)(trx_id)(asset_trx)(block_num)(from_account)(create_time))
FC_REFLECT(goopal::blockchain::GopBalanceEntry, (gop_trxid_sort)(gop_block_sort))
FC_REFLECT(goopal::blockchain::Transaction, (expiration)(reserved)(gop_account)(gop_inport_asset)(operations))
FC_REFLECT_DERIVED(goopal::blockchain::SignedTransaction, (goopal::blockchain::Transaction), (signatures))
FC_REFLECT( goopal::blockchain::TransactionLocation, (block_num)(trx_num) )
