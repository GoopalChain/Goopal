#include <blockchain/AccountOperations.hpp>
#include <blockchain/AssetOperations.hpp>
#include <blockchain/BalanceOperations.hpp>
#include <blockchain/OperationFactory.hpp>
#include <blockchain/Operations.hpp>
#include <blockchain/SlateOperations.hpp>

#include <fc/io/raw_variant.hpp>
#include <fc/reflect/variant.hpp>

namespace goopal { namespace blockchain {
   const OperationTypeEnum WithdrawOperation::type               = withdraw_op_type;
   const OperationTypeEnum DepositOperation::type                = deposit_op_type;
   const OperationTypeEnum RegisterAccountOperation::type       = register_account_op_type;
   const OperationTypeEnum UpdateAccountOperation::type         = update_account_op_type;
   const OperationTypeEnum WithdrawPayOperation::type           = withdraw_pay_op_type;
   const OperationTypeEnum CreateAssetOperation::type           = create_asset_op_type;
   const OperationTypeEnum UpdateAssetOperation::type           = update_asset_op_type;
   const OperationTypeEnum IssueAssetOperation::type            = issue_asset_op_type;
   const OperationTypeEnum DefineSlateOperation::type = define_slate_op_type;
   const OperationTypeEnum ReleaseEscrowOperation::type = release_escrow_op_type;
   const OperationTypeEnum UpdateSigningKeyOperation::type     = update_signing_key_op_type;
   const OperationTypeEnum UpdateBalanceVoteOperation::type    = update_balance_vote_op_type;
   const OperationTypeEnum UpdateAssetExtOperation::type       = update_asset_ext_op_type;

   static bool first_chain = []()->bool{
      goopal::blockchain::OperationFactory::instance().register_operation<WithdrawOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<DepositOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<RegisterAccountOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<UpdateAccountOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<WithdrawPayOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<CreateAssetOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<UpdateAssetOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<IssueAssetOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<DefineSlateOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<ReleaseEscrowOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<UpdateSigningKeyOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<UpdateBalanceVoteOperation>();
      goopal::blockchain::OperationFactory::instance().register_operation<UpdateAssetExtOperation>();

      return true;
   }();

   OperationFactory& OperationFactory::instance()
   {
      static std::unique_ptr<OperationFactory> inst( new OperationFactory() );
      return *inst;
   }

   void OperationFactory::to_variant( const goopal::blockchain::Operation& in, fc::variant& output )
   { try {
      auto converter_itr = _converters.find( in.type.value );
      FC_ASSERT( converter_itr != _converters.end() ,"No such converter!");
      converter_itr->second->to_variant( in, output );
   } FC_RETHROW_EXCEPTIONS( warn, "" ) }

   void OperationFactory::from_variant( const fc::variant& in, goopal::blockchain::Operation& output )
   { try {
      auto obj = in.get_object();

      if( obj[ "type" ].as_string() == "define_delegate_slate_op_type" )
      {
          output.type = define_slate_op_type;
          return;
      }

      output.type = obj["type"].as<OperationTypeEnum>();

      auto converter_itr = _converters.find( output.type.value );
      FC_ASSERT( converter_itr != _converters.end() );
      converter_itr->second->from_variant( in, output );
   } FC_RETHROW_EXCEPTIONS( warn, "", ("in",in) ) }

} } // goopal::blockchain

namespace fc {
   void to_variant( const goopal::blockchain::Operation& var,  variant& vo )
   {
      goopal::blockchain::OperationFactory::instance().to_variant( var, vo );
   }

   void from_variant( const variant& var,  goopal::blockchain::Operation& vo )
   {
      goopal::blockchain::OperationFactory::instance().from_variant( var, vo );
   }
}
