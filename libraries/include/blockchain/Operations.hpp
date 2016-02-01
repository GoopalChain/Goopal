#pragma once

#include <fc/io/enum_type.hpp>
#include <fc/io/raw.hpp>
#include <fc/reflect/reflect.hpp>

/**
 *  The C keyword 'not' is NOT friendly on VC++ but we still want to use
 *  it for readability, so we will have the pre-processor convert it to the
 *  more traditional form.  The goal here is to make the understanding of
 *  the validation logic as english-like as possible.
 */
#define NOT !

namespace goopal { namespace blockchain {

   class TransactionEvaluationState;

   enum OperationTypeEnum
   {
      null_op_type                  = 0,

      // balances
      withdraw_op_type              = 1,
      deposit_op_type               = 2,

      // accounts
      register_account_op_type      = 3,
      update_account_op_type        = 4,
      withdraw_pay_op_type          = 5,

      // assets
      create_asset_op_type          = 6,
      update_asset_op_type          = 7,
      issue_asset_op_type           = 8,

      // reserved
      // reserved_op_1_type         = 10, // Skip; see below
      reserved_op_2_type            = 11,
      reserved_op_3_type            = 17,
      define_slate_op_type          = 18,

      // reserved
      reserved_op_4_type            = 21,
      reserved_op_5_type            = 22,
      release_escrow_op_type        = 23,
      update_signing_key_op_type    = 24,
      update_balance_vote_op_type   = 27,

      // assets
      update_asset_ext_op_type      = 30,
   };

   /**
    *  A poly-morphic operator that modifies the blockchain database
    *  is some manner.
    */
   struct Operation
   {
      Operation():type(null_op_type){}

      Operation( const Operation& o )
      :type(o.type),data(o.data){}

      Operation( Operation&& o )
      :type(o.type),data(std::move(o.data)){}

      template<typename OperationType>
      Operation( const OperationType& t )
      {
         type = OperationType::type;
         data = fc::raw::pack( t );
      }

      template<typename OperationType>
      OperationType as()const
      {
         FC_ASSERT( (OperationTypeEnum)type == OperationType::type, "", ("type",type)("OperationType",OperationType::type) );
         return fc::raw::unpack<OperationType>(data);
      }

      Operation& operator=( const Operation& o )
      {
         if( this == &o ) return *this;
         type = o.type;
         data = o.data;
         return *this;
      }

      Operation& operator=( Operation&& o )
      {
         if( this == &o ) return *this;
         type = o.type;
         data = std::move(o.data);
         return *this;
      }

      fc::enum_type<uint8_t,OperationTypeEnum> type;
      std::vector<char> data;
   };

} } // goopal::blockchain

FC_REFLECT_ENUM( goopal::blockchain::OperationTypeEnum,
                 (null_op_type)
                 (withdraw_op_type)
                 (deposit_op_type)
                 (register_account_op_type)
                 (update_account_op_type)
                 (withdraw_pay_op_type)
                 (create_asset_op_type)
                 (update_asset_op_type)
                 (issue_asset_op_type)
                 (reserved_op_2_type)          
                 (reserved_op_3_type)
                 (define_slate_op_type)
                 (reserved_op_4_type)
                 (reserved_op_5_type)
                 (release_escrow_op_type)
                 (update_signing_key_op_type)
                 (update_balance_vote_op_type)
                 (update_asset_ext_op_type)
                 )

FC_REFLECT( goopal::blockchain::Operation, (type)(data) )

namespace fc {
   void to_variant( const goopal::blockchain::Operation& var,  variant& vo );
   void from_variant( const variant& var,  goopal::blockchain::Operation& vo );
}
