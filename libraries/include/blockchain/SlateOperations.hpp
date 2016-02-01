#pragma once

#include <blockchain/Operations.hpp>

namespace goopal { namespace blockchain {

struct DefineSlateOperation
{
    static const OperationTypeEnum type;

    vector<signed_int> slate;

    void evaluate( TransactionEvaluationState& eval_state )const;
};

} } // goopal::blockchain

FC_REFLECT( goopal::blockchain::DefineSlateOperation, (slate) )
