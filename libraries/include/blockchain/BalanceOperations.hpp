#pragma once

#include <blockchain/Asset.hpp>
#include <blockchain/Operations.hpp>
#include <blockchain/WithdrawTypes.hpp>

namespace goopal { namespace blockchain {

   /** withdraws funds and moves them into the transaction
    * balance making them available for deposit
    */
   struct WithdrawOperation
   {
       static const OperationTypeEnum type;

       WithdrawOperation():amount(0){}

       WithdrawOperation( const BalanceIdType& id, ShareType amount_arg )
          :balance_id(id),amount(amount_arg){ FC_ASSERT( amount_arg > 0 ); }

       /** the account to withdraw from */
       BalanceIdType    balance_id;
       /** that amount to withdraw from the account*/
       ShareType         amount;
       /** any data required by the claim_condition */
       std::vector<char>  claim_input_data;

       void evaluate( TransactionEvaluationState& eval_state )const;
   };

   /**
    *  The first time a deposit is made to a new address
    *  the condition under which it may be spent must be
    *  defined.  After the first deposit then future
    *  deposits merely reference the address.
    */
   struct DepositOperation
   {
       static const OperationTypeEnum type;
       /** owner is just the hash of the condition */
       BalanceIdType                balance_id()const;

       DepositOperation():amount(0){}
       DepositOperation( const Address& owner, const Asset& amnt, SlateIdType slate_id = 0 );

       /** the condition that the funds may be withdrawn,
        *  this is only necessary if the address is new.
        */
       ShareType                       amount;
       WithdrawCondition               condition;

       void evaluate( TransactionEvaluationState& eval_state )const;
   };

   /**
    *  Burn operations takes shares out of circulation unless they
    *  are BitAssets in which case it goes to collected fees and is
    *  distributed as yield.
    */

   struct ReleaseEscrowOperation
   {
      static const OperationTypeEnum type;

      BalanceIdType  escrow_id;
      Address          released_by;
      ShareType       amount_to_receiver = 0;
      ShareType       amount_to_sender   = 0;

      void evaluate( TransactionEvaluationState& eval_state )const;
   };

   /* Moves funds to a new balance with the same owner key but different votes
    * and restricted owner key.
    */
   struct UpdateBalanceVoteOperation
   {
      static const OperationTypeEnum type;

      BalanceIdType     balance_id;
      optional<Address>   new_restricted_owner;
      SlateIdType       new_slate;

      void evaluate( TransactionEvaluationState& eval_state )const;
   };

   /**
    *  This operation enforces the expected fee for a
    *  transaction.  If the transaction evaluation shows
    *  that more than the expected fee would be paid then
    *  it fails.   
    *
    *  The purpose of this is to handle cases where the
    *  fee is not entirely deterministic from the withdraws
    *  and deposits. This happens if there is interest,
    *  yield, or market operations that effect the
    *  result.  It is also a way for the creator of a
    *  transaction to protect against malformed transactions
    *  that pay excessively high fees.
    */

} } // goopal::blockchain

FC_REFLECT( goopal::blockchain::WithdrawOperation, (balance_id)(amount)(claim_input_data) )
FC_REFLECT( goopal::blockchain::DepositOperation, (amount)(condition) )
FC_REFLECT( goopal::blockchain::ReleaseEscrowOperation, (escrow_id)(released_by)(amount_to_receiver)(amount_to_sender) )
FC_REFLECT( goopal::blockchain::UpdateBalanceVoteOperation, (balance_id)(new_restricted_owner)(new_slate) )
