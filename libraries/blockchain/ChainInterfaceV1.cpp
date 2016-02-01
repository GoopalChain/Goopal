#include <blockchain/ChainInterface.hpp>
#include <blockchain/Exceptions.hpp>
#include <locale>

#define ASSET_MAX_SYMBOL_SIZE 8
#define ASSET_MIN_SYMBOL_SIZE 3

#define GOP_BLOCKCHAIN_DELEGATE_REGISTRATION_FEE    (GOP_BLOCKCHAIN_BLOCKS_PER_DAY / 12)
#define GOP_BLOCKCHAIN_ASSET_REGISTRATION_FEE       (GOP_BLOCKCHAIN_BLOCKS_PER_DAY * 14)

namespace goopal { namespace blockchain {

bool ChainInterface::is_valid_symbol_name_v1( const string& symbol )const
{ try {
    FC_ASSERT( symbol != "GOP" );

    if( symbol.size() < ASSET_MIN_SYMBOL_SIZE || symbol.size() > ASSET_MAX_SYMBOL_SIZE )
        return false;

    int dots = 0;
    for( const char c : symbol )
    {
        if( c == '.' )
        {
           if( ++dots > 1 )
            return false;
        }
        else if( !std::isalnum( c, std::locale::classic() ) || !std::isupper( c, std::locale::classic() ) )
            return false;
    }
    if( symbol.back() == '.' ) return false;
    if( symbol.front() == '.' ) return false;

    return true;
} FC_CAPTURE_AND_RETHROW( (symbol) ) }

ShareType ChainInterface::get_delegate_registration_fee_v1( uint8_t pay_rate )const
{
   if( pay_rate == 0 ) return 0;
   const ShareType unscaled_fee = (get_delegate_pay_rate_v1() * GOP_BLOCKCHAIN_DELEGATE_REGISTRATION_FEE)/GOP_BLOCKCHAIN_NUM_DELEGATES;
   return (unscaled_fee * pay_rate) / 100;
}

ShareType ChainInterface::get_asset_registration_fee_v1()const
{
   return (get_delegate_pay_rate_v1() * GOP_BLOCKCHAIN_ASSET_REGISTRATION_FEE);
}

ShareType ChainInterface::get_delegate_pay_rate_v1()const
{
    const auto base_entry = get_asset_entry( AssetIdType( 0 ) );
    FC_ASSERT( base_entry.valid() );
    return base_entry->collected_fees / (GOP_BLOCKCHAIN_BLOCKS_PER_DAY * 14);
}

bool ChainInterface::is_fraudulent_asset( const AssetEntry& suspect_entry )const
{ try {
    if( !suspect_entry.is_user_issued() ) return false;

    const string& symbol = suspect_entry.symbol;
    if( symbol.size() <= 3 || symbol.find( "GOP" ) != 0 ) return false;

    const oAssetEntry victim_entry = get_asset_entry( symbol.substr( 3 ) );
    return victim_entry.valid() ; 
} FC_CAPTURE_AND_RETHROW( (suspect_entry) ) }

} } // goopal::blockchain
