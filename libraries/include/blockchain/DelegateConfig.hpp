#pragma once

#include <blockchain/Config.hpp>
#include <blockchain/Types.hpp>
#include <fc/time.hpp>

#ifdef GOP_TEST_NETWORK
#define NETWORK_MIN_CONNECTION_COUNT_DEFAULT 0
#else
#define NETWORK_MIN_CONNECTION_COUNT_DEFAULT 4
#endif

#define GOP_BLOCKCHAIN_AVERAGE_TRX_SIZE 512 // just a random assumption used to calibrate TRX per SEC
/** defines the maximum block size allowed, 2 MB per hour */
#define GOP_BLOCKCHAIN_MAX_BLOCK_SIZE (10 * GOP_BLOCKCHAIN_AVERAGE_TRX_SIZE * GOP_BLOCKCHAIN_MAX_PENDING_QUEUE_SIZE )

namespace goopal { namespace blockchain {

struct DelegateConfig
{
    uint32_t            network_min_connection_count = NETWORK_MIN_CONNECTION_COUNT_DEFAULT;

    uint32_t            block_max_transaction_count = -1;
    uint32_t            block_max_size = GOP_BLOCKCHAIN_MAX_BLOCK_SIZE;
    fc::microseconds    block_max_production_time = fc::seconds( 3 );

    uint32_t            transaction_max_size = GOP_BLOCKCHAIN_MAX_BLOCK_SIZE;
    bool                transaction_canonical_signatures_required = false;
    ShareType          transaction_min_fee = GOP_BLOCKCHAIN_PRECISION / 100;

    set<TransactionIdType>    transaction_blacklist;
    set<OperationTypeEnum>    operation_blacklist;

    void validate()const
    { try {
        FC_ASSERT( block_max_size <= GOP_BLOCKCHAIN_MAX_BLOCK_SIZE );
        FC_ASSERT( block_max_production_time.count() >= 0 );
        FC_ASSERT( block_max_production_time.to_seconds() <= GOP_BLOCKCHAIN_BLOCK_INTERVAL_SEC );
        FC_ASSERT( transaction_max_size <= block_max_size );
        FC_ASSERT( transaction_min_fee >= 0 );
        FC_ASSERT( transaction_min_fee <= GOP_BLOCKCHAIN_MAX_SHARES );
    } FC_CAPTURE_AND_RETHROW() }
};

} } // goopal::blockchain

FC_REFLECT( goopal::blockchain::DelegateConfig,
        (network_min_connection_count)
        (block_max_transaction_count)
        (block_max_size)
        (block_max_production_time)
        (transaction_max_size)
        (transaction_canonical_signatures_required)
        (transaction_min_fee)
        (transaction_blacklist)
        (operation_blacklist)
        )
