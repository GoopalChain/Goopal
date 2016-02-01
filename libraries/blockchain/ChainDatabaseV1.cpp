#include <blockchain/ChainDatabaseImpl.hpp>
#include <blockchain/ForkBlocks.hpp>


using namespace goopal::blockchain;
namespace goopal {
	namespace blockchain {
		namespace detail {

			void ChainDatabaseImpl::pay_delegate_v1(const BlockIdType& block_id,
				const PublicKeyType& block_signee,
				const PendingChainStatePtr& pending_state,
				oBlockEntry& entry)const
			{
				try {
					oAccountEntry delegate_entry = self->get_account_entry(Address(block_signee));
					FC_ASSERT(delegate_entry.valid());
					delegate_entry = pending_state->get_account_entry(delegate_entry->id);
					FC_ASSERT(delegate_entry.valid() && delegate_entry->is_delegate() && delegate_entry->delegate_info.valid());

					const uint8_t pay_rate_percent = delegate_entry->delegate_info->pay_rate;
					FC_ASSERT(pay_rate_percent >= 0 && pay_rate_percent <= 100);

					const ShareType max_available_paycheck = pending_state->get_delegate_pay_rate_v1();
					const ShareType accepted_paycheck = (max_available_paycheck * pay_rate_percent) / 100;
					const ShareType burned_paycheck = max_available_paycheck - accepted_paycheck;
					FC_ASSERT(max_available_paycheck >= accepted_paycheck);
					FC_ASSERT(accepted_paycheck >= 0);

					oAssetEntry base_asset_entry = pending_state->get_asset_entry(AssetIdType(0));
					FC_ASSERT(base_asset_entry.valid());
					base_asset_entry->current_share_supply -= burned_paycheck;
					if (pending_state->get_head_block_num() >= GOP_V0_4_16_FORK_BLOCK_NUM)
					{
						base_asset_entry->collected_fees -= max_available_paycheck;
						delegate_entry->delegate_info->total_burned += burned_paycheck;
					}
					else
					{
						base_asset_entry->collected_fees -= accepted_paycheck;
					}
					pending_state->store_asset_entry(*base_asset_entry);

					delegate_entry->delegate_info->votes_for += accepted_paycheck;
					delegate_entry->delegate_info->pay_balance += accepted_paycheck;
					delegate_entry->delegate_info->total_paid += accepted_paycheck;
					pending_state->store_account_entry(*delegate_entry);

					if (entry.valid())
					{
						entry->signee_shares_issued = 0;
						entry->signee_fees_collected = accepted_paycheck;
						entry->signee_fees_destroyed = burned_paycheck;
					}
				} FC_CAPTURE_AND_RETHROW((block_id)(block_signee)(entry))
			}

		}
	}
}
