#include <blockchain/ChainDatabaseImpl.hpp>
#include <blockchain/ForkBlocks.hpp>

namespace goopal { namespace blockchain { namespace detail {

void ChainDatabaseImpl::pay_delegate_v2( const BlockIdType& block_id,
                                           const PublicKeyType& block_signee,
                                           const PendingChainStatePtr& pending_state,
                                           oBlockEntry& entry )const
{ try {
      if( pending_state->get_head_block_num() < GOP_V0_4_24_FORK_BLOCK_NUM )
          return pay_delegate_v1( block_id, block_signee, pending_state, entry );

      oAccountEntry delegate_entry = self->get_account_entry( Address( block_signee ) );
      FC_ASSERT( delegate_entry.valid() );
      delegate_entry = pending_state->get_account_entry( delegate_entry->id );
      FC_ASSERT( delegate_entry.valid() && delegate_entry->is_delegate() && delegate_entry->delegate_info.valid() );

      const uint8_t pay_rate_percent = delegate_entry->delegate_info->pay_rate;
      FC_ASSERT( pay_rate_percent >= 0 && pay_rate_percent <= 100 );
      const ShareType accepted_paycheck = (self->get_max_delegate_pay_issued_per_block() * pay_rate_percent) / 100;
      FC_ASSERT( accepted_paycheck >= 0 );

      delegate_entry->delegate_info->votes_for += accepted_paycheck;
      delegate_entry->delegate_info->pay_balance += accepted_paycheck;
      delegate_entry->delegate_info->total_paid += accepted_paycheck;
      pending_state->store_account_entry( *delegate_entry );

      oAssetEntry base_asset_entry = pending_state->get_asset_entry( AssetIdType( 0 ) );
      FC_ASSERT( base_asset_entry.valid() );
      const ShareType destroyed_collected_fees = base_asset_entry->collected_fees;
      base_asset_entry->current_share_supply += accepted_paycheck;
      base_asset_entry->current_share_supply -= destroyed_collected_fees;
      base_asset_entry->collected_fees = 0;
      pending_state->store_asset_entry( *base_asset_entry );

      if( entry.valid() )
      {
          entry->signee_shares_issued = accepted_paycheck;
          entry->signee_fees_collected = 0;
          entry->signee_fees_destroyed = destroyed_collected_fees;
      }
} FC_CAPTURE_AND_RETHROW( (block_id)(block_signee)(entry) ) }

} } } // goopal::blockchain::detail
