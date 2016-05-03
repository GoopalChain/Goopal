#include <blockchain/ChainInterface.hpp>
#include <blockchain/Exceptions.hpp>
#include <fc/io/raw_variant.hpp>

#include <algorithm>
#include <locale>

#include <blockchain/ForkBlocks.hpp>

namespace goopal { namespace blockchain {

   bool ChainInterface::is_valid_account_name( const string& name )
   { try {
      if( name.size() < GOP_BLOCKCHAIN_MIN_NAME_SIZE ) return false;
      if( name.size() > GOP_BLOCKCHAIN_MAX_NAME_SIZE ) return false;
      if( !isalpha(name[0]) ) return false;
      if ( !isalnum(name[name.size()-1]) || isupper(name[name.size()-1]) ) return false;

      string subname(name);
      string supername;
      int dot = name.find('.');
      if( dot != string::npos )
      {
        subname = name.substr(0, dot);
        //There is definitely a remainder; we checked above that the last character is not a dot
        supername = name.substr(dot+1);
      }

      if ( !isalnum(subname[subname.size()-1]) || isupper(subname[subname.size()-1]) ) return false;
      for( const auto& c : subname )
      {
          if( isalnum(c) && !isupper(c) ) continue;
          else if( c == '-' ) continue;
          else return false;
      }

      if( supername.empty() )
        return true;
      return is_valid_account_name(supername);
   } FC_CAPTURE_AND_RETHROW( (name) ) }

   /**
    * Symbol names can be hierarchical: for example a primary symbol name, a '.', and a sub-symbol name.
    * A primary symbol name must be a minimum of 3 and a maximum of 8 characters in length.
    * Primary names can only contain uppercase letters (digits are not allowed to avoid 0 and 1 spoofing).
    * A hierarchical symbol name (consisting of a primary symbol name, a dot, and a sub-symbol name) can be up to 12 chars
    * in total length (including the dot).
    * Sub-symbol names can contain uppercase letters or digits (digits are allowed in sub-symbols because the namespace is
    * overseen by the owner of the primary symbol and is therefore not subject to spoofing).
    *
    * To fit under the 12 character limit, it is likely that users planning to register hierarchical names will
    * choose shorter (more expensive) symbol names for their primary symbol, so that they can mirror more primary symbol names.
    * The max of 12 for hierarchical symbol names will allow hierarchical mirroring of long primary symbol characters
    * as long as the primary symbol buyer purchases a symbol of 3 in size. For example, if CRY was chosen as the primary symbol,
    * CRY.ABCDEFGH could be registered. But if a longer name was chosen as a primary symbol, such as CRYPTO,
    * then only symbols up to 5 in length can be mirrored (i.e CRYPTO.ABCDEFGH would be too long).
    */
   bool ChainInterface::is_valid_symbol_name( const string& symbol )const
   { try {
      // if( get_head_block_num() < GOP_V0_5_0_FORK_BLOCK_NUM )
          // return is_valid_symbol_name_v1( symbol );

       FC_ASSERT( symbol != "GOP" ,"Symbol must  not be GOP ");

       if( symbol.size() < GOP_BLOCKCHAIN_MIN_SYMBOL_SIZE)
         FC_ASSERT(false, "Symbol name too small");

       int dots = 0;
       int dot_position = 0;
       int position = 0;
       for( const char c : symbol )
       {
          if( c == '.' ) //if we have hierarchical name
          {
            dot_position =  position;
            if ( ++dots > 1 )
              FC_ASSERT(false, "Symbol names can have at most one dot");
          }
          else if (dots == 0 && !std::isupper( c, std::locale::classic() ) )
              FC_ASSERT(false, "Primary symbol names can only contain uppercase letters");
          else if (!std::isupper( c, std::locale::classic() ) &&
                  !std::isdigit( c, std::locale::classic() )     )
            FC_ASSERT(false, "Sub-symbol names can only contain uppercase letters or digits");
          ++position;
       }

       if( symbol.back() == '.' ) return false;
       if( symbol.front() == '.' ) return false;

       if (dots == 0)
       {
         if (position > GOP_BLOCKCHAIN_MAX_SUB_SYMBOL_SIZE)
           FC_ASSERT(false, "Symbol name too large");
       }
       else //dots == 1 means hierarchial asset name
       {
         if (position - dot_position - 1> GOP_BLOCKCHAIN_MAX_SUB_SYMBOL_SIZE)
           FC_ASSERT(false, "Sub-symbol name too large");
         if( symbol.size() > GOP_BLOCKCHAIN_MAX_SYMBOL_SIZE)
           FC_ASSERT(false, "Symbol name too large");
       }

       if( symbol.find( "GOP" ) == 0 )
         FC_ASSERT(false, "Symbol names cannot be prefixed with GOP");

       return true;
   } FC_CAPTURE_AND_RETHROW( (symbol) ) }

   time_point_sec ChainInterface::get_genesis_timestamp()const
   {
       return get_asset_entry( AssetIdType() )->registration_date;
   }

   // Starting at genesis, delegates are issued max 50 shares per block produced, and this value is halved every 4 years
   // just like in Bitcoin
   ShareType ChainInterface::get_max_delegate_pay_issued_per_block()const
   {
       ShareType pay_per_block = GOP_MAX_DELEGATE_PAY_PER_BLOCK;
//        static const time_point_sec start_timestamp = get_genesis_timestamp();
//        static const uint32_t seconds_per_period = fc::days( 4 * 365 ).to_seconds(); // Ignore leap years, leap seconds, etc.
// 
//        const time_point_sec now = this->now();
//        if( now >= start_timestamp )
//        {
//            const uint32_t elapsed_time = (now - start_timestamp).to_seconds();
//            const uint32_t num_full_periods = elapsed_time / seconds_per_period;
//            for( uint32_t i = 0; i < num_full_periods; ++i )
//                pay_per_block /= 2;
//        }

       return pay_per_block;
   }

   ShareType ChainInterface::get_delegate_registration_fee( uint8_t pay_rate )const
   {
      // if( get_head_block_num() < GOP_V0_4_24_FORK_BLOCK_NUM )
          // return get_delegate_registration_fee_v1( pay_rate );

       if( pay_rate == 0 ) return 0;
       static const uint32_t blocks_per_two_weeks = 14 * GOP_BLOCKCHAIN_BLOCKS_PER_DAY;
       const ShareType max_total_pay_per_two_weeks = blocks_per_two_weeks * get_max_delegate_pay_issued_per_block();
       const ShareType max_pay_per_two_weeks = max_total_pay_per_two_weeks / GOP_BLOCKCHAIN_NUM_DELEGATES;
       const ShareType registration_fee = (max_pay_per_two_weeks * pay_rate) / 100;
       FC_ASSERT( registration_fee > 0,"Registration_fee must be bigger than 0"  );
       return registration_fee;
   }
   ShareType ChainInterface::get_imessage_need_fee(const string & imessage)const
   {
       if (imessage.size() < GOP_BLOCKCHAIN_MAX_FREE_MESSAGE_SIZE)
       {
           return 0;
       }
       ImessageIdType fee_coe = GOP_BLOCKCHAIN_MIN_MESSAGE_FEE_COE;
       ShareType fee = 0;
       fee = fee_coe * (imessage.size() - GOP_BLOCKCHAIN_MAX_FREE_MESSAGE_SIZE);
       return fee;
   }
   ShareType ChainInterface::get_asset_registration_fee( uint8_t symbol_length )const
   {
      // if( get_head_block_num() < GOP_V0_4_24_FORK_BLOCK_NUM )
           //return get_asset_registration_fee_v1();

       // TODO: Add #define's for these fixed prices
       static const ShareType long_symbol_price = 500 * GOP_BLOCKCHAIN_PRECISION; // $10 at $0.02/XTS
       static const ShareType short_symbol_price = 1000 * long_symbol_price;
       FC_ASSERT( long_symbol_price > 0 ,"Price of long symbol must bigger than 0");
       FC_ASSERT( short_symbol_price > long_symbol_price,"Price of short symbol must bigger than the price of long symbol" );
       return symbol_length <= 5 ? short_symbol_price : long_symbol_price;
   }

   AssetIdType ChainInterface::last_asset_id()const
   { try {
       const oPropertyEntry entry = get_property_entry( PropertyIdType::last_asset_id );
       FC_ASSERT( entry.valid() ,"Invalid asset entry");
       return entry->value.as<AssetIdType>();
   } FC_CAPTURE_AND_RETHROW() }

   AssetIdType ChainInterface::new_asset_id()
   { try {
       const AssetIdType next_id = last_asset_id() + 1;
       store_property_entry( PropertyIdType::last_asset_id, variant( next_id ) );
       return next_id;
   } FC_CAPTURE_AND_RETHROW() }

   AccountIdType ChainInterface::last_account_id()const
   { try {
       const oPropertyEntry entry = get_property_entry( PropertyIdType::last_account_id );
       FC_ASSERT( entry.valid() ,"Invalid account entry");
       return entry->value.as<AccountIdType>();
   } FC_CAPTURE_AND_RETHROW() }

   AccountIdType ChainInterface::new_account_id()
   { try {
       const AccountIdType next_id = last_account_id() + 1;
       store_property_entry( PropertyIdType::last_account_id, variant( next_id ) );
       return next_id;
   } FC_CAPTURE_AND_RETHROW() }

   vector<AccountIdType> ChainInterface::get_active_delegates()const
   { try {
       const oPropertyEntry entry = get_property_entry( PropertyIdType::active_delegate_list_id );
       FC_ASSERT( entry.valid(),"Get active delegates failed!No property enrty with id active_delegate_list_id");
       return entry->value.as<vector<AccountIdType>>();
   } FC_CAPTURE_AND_RETHROW() }

   void ChainInterface::set_active_delegates( const std::vector<AccountIdType>& active_delegates )
   { try {
       store_property_entry( PropertyIdType::active_delegate_list_id, variant( active_delegates ) );
   } FC_CAPTURE_AND_RETHROW( (active_delegates) ) }

   bool ChainInterface::is_active_delegate( const AccountIdType id )const
   { try {
       const auto active_delegates = get_active_delegates();
       return std::count( active_delegates.begin(), active_delegates.end(), id ) > 0;
   } FC_CAPTURE_AND_RETHROW( (id) ) }

   double ChainInterface::to_pretty_price_double( const Price& price_to_pretty_print )const
   {
      auto obase_asset = get_asset_entry( price_to_pretty_print.base_asset_id );
      if( !obase_asset ) FC_CAPTURE_AND_THROW( unknown_asset_id, (price_to_pretty_print.base_asset_id) );

      auto oquote_asset = get_asset_entry( price_to_pretty_print.quote_asset_id );
      if( !oquote_asset ) FC_CAPTURE_AND_THROW( unknown_asset_id, (price_to_pretty_print.quote_asset_id) );

      return fc::variant(string(price_to_pretty_print.ratio * obase_asset->precision / oquote_asset->precision)).as_double() / (GOP_BLOCKCHAIN_MAX_SHARES*1000);
   }

   string ChainInterface::to_pretty_price( const Price& price_to_pretty_print )const
   { try {
      auto obase_asset = get_asset_entry( price_to_pretty_print.base_asset_id );
      if( !obase_asset ) FC_CAPTURE_AND_THROW( unknown_asset_id, (price_to_pretty_print.base_asset_id) );

      auto oquote_asset = get_asset_entry( price_to_pretty_print.quote_asset_id );
      if( !oquote_asset ) FC_CAPTURE_AND_THROW( unknown_asset_id, (price_to_pretty_print.quote_asset_id) );

      auto tmp = price_to_pretty_print;
      tmp.ratio *= obase_asset->precision;
      tmp.ratio /= oquote_asset->precision;

      return tmp.ratio_string() + " " + oquote_asset->symbol + " / " + obase_asset->symbol;
   } FC_CAPTURE_AND_RETHROW( (price_to_pretty_print) ) }

   Asset ChainInterface::to_ugly_asset(const std::string& amount, const std::string& symbol) const
   { try {
      const auto entry = get_asset_entry( symbol );
      if( !entry ) FC_CAPTURE_AND_THROW( unknown_asset_symbol, (symbol) );
      return entry->asset_from_string(amount);
   } FC_CAPTURE_AND_RETHROW( (amount)(symbol) ) }

   Price ChainInterface::to_ugly_price(const std::string& price_string,
                                        const std::string& base_symbol,
                                        const std::string& quote_symbol,
                                        bool do_precision_dance) const
   { try {
      auto base_entry = get_asset_entry(base_symbol);
      auto quote_entry = get_asset_entry(quote_symbol);
      if( !base_entry ) FC_CAPTURE_AND_THROW( unknown_asset_symbol, (base_symbol) );
      if( !quote_entry ) FC_CAPTURE_AND_THROW( unknown_asset_symbol, (quote_symbol) );

      Price ugly_price(price_string + " " + std::to_string(quote_entry->id) + " / " + std::to_string(base_entry->id));
      if( do_precision_dance )
      {
         ugly_price.ratio *= quote_entry->precision;
         ugly_price.ratio /= base_entry->precision;
      }
      return ugly_price;
   } FC_CAPTURE_AND_RETHROW( (price_string)(base_symbol)(quote_symbol)(do_precision_dance) ) }

   string ChainInterface::to_pretty_asset( const Asset& a )const
   { try {
      const auto oasset = get_asset_entry( a.asset_id );
      if( oasset.valid() ) return oasset->amount_to_string(a.amount);
      return fc::to_pretty_string( a.amount ) + " ???";
   } FC_CAPTURE_AND_RETHROW( (a) ) }

   void ChainInterface::set_chain_id( const DigestType& id )
   { try {
       store_property_entry( PropertyIdType::chain_id, variant( id ) );
   } FC_CAPTURE_AND_RETHROW( (id) ) }

   DigestType ChainInterface::get_chain_id()const
   { try {
       static optional<DigestType> value;
       if( value.valid() ) return *value;
       const oPropertyEntry entry = get_property_entry( PropertyIdType::chain_id );
       FC_ASSERT( entry.valid() ,"Getting chain id from property db failed!");
       value = entry->value.as<DigestType>();
       return *value;
   } FC_CAPTURE_AND_RETHROW() }

   fc::ripemd160 ChainInterface::get_current_random_seed()const
   { try {
       const oPropertyEntry entry = get_property_entry( PropertyIdType::last_random_seed_id );
       if( entry.valid() ) return entry->value.as<fc::ripemd160>();
       return fc::ripemd160();
   } FC_CAPTURE_AND_RETHROW() }

   void ChainInterface::set_statistics_enabled( const bool enabled )
   { try {
       store_property_entry( PropertyIdType::statistics_enabled, variant( enabled ) );
   } FC_CAPTURE_AND_RETHROW( (enabled) ) }

   bool ChainInterface::get_statistics_enabled()const
   { try {
       static optional<bool> value;
       if( value.valid() ) return *value;
       const oPropertyEntry entry = get_property_entry( PropertyIdType::statistics_enabled );
       FC_ASSERT(entry.valid(), "Getting statistics property from property db failed!");
       value = entry->value.as<bool>();
       return *value;
   } FC_CAPTURE_AND_RETHROW() }

   void ChainInterface::set_required_confirmations( uint64_t count )
   { try {
       store_property_entry( PropertyIdType::confirmation_requirement, variant( count ) );
   } FC_CAPTURE_AND_RETHROW( (count) ) }

   uint64_t ChainInterface::get_required_confirmations()const
   { try {
       const oPropertyEntry entry = get_property_entry( PropertyIdType::confirmation_requirement );
       if( entry.valid() ) return entry->value.as_uint64();
       return GOP_BLOCKCHAIN_NUM_DELEGATES * 3;
   } FC_CAPTURE_AND_RETHROW() }

 
   oPropertyEntry ChainInterface::get_property_entry( const PropertyIdType id )const
   { try {
       return lookup<PropertyEntry>( id );
   } FC_CAPTURE_AND_RETHROW( (id) ) }

   void ChainInterface::store_property_entry( const PropertyIdType id, const variant& value)
   { try {
       store( id, PropertyEntry{ id, value } );
   } FC_CAPTURE_AND_RETHROW( (id)(value) ) }

   oAccountEntry ChainInterface::get_account_entry( const AccountIdType id )const
   { try {
       return lookup<AccountEntry>( id );
   } FC_CAPTURE_AND_RETHROW( (id) ) }

   oAccountEntry ChainInterface::get_account_entry( const string& name )const
   { try {
       return lookup<AccountEntry>( name );
   } FC_CAPTURE_AND_RETHROW( (name) ) }

   oAccountEntry ChainInterface::get_account_entry( const Address& addr )const
   { try {
       return lookup<AccountEntry>( addr );
   } FC_CAPTURE_AND_RETHROW( (addr) ) }

   void ChainInterface::store_account_entry( const AccountEntry& entry )
   { try {
       store( entry.id, entry );
   } FC_CAPTURE_AND_RETHROW( (entry) ) }

   oAssetEntry ChainInterface::get_asset_entry( const AssetIdType id )const
   { try {
       return lookup<AssetEntry>( id );
   } FC_CAPTURE_AND_RETHROW( (id) ) }

   oAssetEntry ChainInterface::get_asset_entry( const string& symbol )const
   { try {
       return lookup<AssetEntry>( symbol );
   } FC_CAPTURE_AND_RETHROW( (symbol) ) }

   void ChainInterface::store_asset_entry( const AssetEntry& entry )
   { try {
       store( entry.id, entry );
   } FC_CAPTURE_AND_RETHROW( (entry) ) }

   oSlateEntry ChainInterface::get_slate_entry( const SlateIdType id )const
   { try {
       return lookup<SlateEntry>( id );
   } FC_CAPTURE_AND_RETHROW( (id) ) }

   void ChainInterface::store_slate_entry( const SlateEntry& entry )
   { try {
       store( entry.id(), entry );
   } FC_CAPTURE_AND_RETHROW( (entry) ) }

   oBalanceEntry ChainInterface::get_balance_entry( const BalanceIdType& id )const
   { try {
       return lookup<BalanceEntry>( id );
   } FC_CAPTURE_AND_RETHROW( (id) ) }

   void ChainInterface::store_balance_entry( const BalanceEntry& entry )
   { try {
       store( entry.id(), entry );
   } FC_CAPTURE_AND_RETHROW( (entry) ) }

  


   oSlotEntry ChainInterface::get_slot_entry( const SlotIndex index )const
   { try {
       return lookup<SlotEntry>( index );
   } FC_CAPTURE_AND_RETHROW( (index) ) }

   oSlotEntry ChainInterface::get_slot_entry( const time_point_sec timestamp )const
   { try {
       return lookup<SlotEntry>( timestamp );
   } FC_CAPTURE_AND_RETHROW( (timestamp) ) }

   void ChainInterface::store_slot_entry( const SlotEntry& entry )
   { try {
       store( entry.index, entry );
   } FC_CAPTURE_AND_RETHROW( (entry) ) }

} } // goopal::blockchain
