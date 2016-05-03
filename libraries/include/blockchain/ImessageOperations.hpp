#pragma once


#include <blockchain/Operations.hpp>
#include <blockchain/Types.hpp>

namespace goopal {
    namespace blockchain {
		struct ImessageMemoOperation
		{
			static const OperationTypeEnum type;
			string imessage;
			ImessageMemoOperation(){}
			ImessageMemoOperation(std::string imess) :imessage(imess){}
			void evaluate(TransactionEvaluationState& eval_state)const;
		};
    }
}
FC_REFLECT(goopal::blockchain::ImessageMemoOperation, (imessage))