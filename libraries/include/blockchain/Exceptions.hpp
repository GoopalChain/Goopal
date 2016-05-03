#pragma once

#include <fc/exception/exception.hpp>

namespace goopal { namespace blockchain {
   // registered in chain_database.cpp

   FC_DECLARE_EXCEPTION( blockchain_exception, 30000, "Blockchain Exception" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_pts_address,               goopal::blockchain::blockchain_exception, 30001, "invalid pts address" );
   FC_DECLARE_DERIVED_EXCEPTION( addition_overflow,                 goopal::blockchain::blockchain_exception, 30002, "addition overflow" );
   FC_DECLARE_DERIVED_EXCEPTION( subtraction_overflow,              goopal::blockchain::blockchain_exception, 30003, "subtraction overflow" );
   FC_DECLARE_DERIVED_EXCEPTION( asset_type_mismatch,               goopal::blockchain::blockchain_exception, 30004, "asset/price mismatch" );
   FC_DECLARE_DERIVED_EXCEPTION( unsupported_chain_operation,       goopal::blockchain::blockchain_exception, 30005, "unsupported chain operation" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_transaction,               goopal::blockchain::blockchain_exception, 30006, "unknown transaction" );
   FC_DECLARE_DERIVED_EXCEPTION( duplicate_transaction,             goopal::blockchain::blockchain_exception, 30007, "duplicate transaction" );
   FC_DECLARE_DERIVED_EXCEPTION( zero_amount,                       goopal::blockchain::blockchain_exception, 30008, "zero amount" );
   FC_DECLARE_DERIVED_EXCEPTION( zero_price,                        goopal::blockchain::blockchain_exception, 30009, "zero price" );
   FC_DECLARE_DERIVED_EXCEPTION( asset_divide_by_self,              goopal::blockchain::blockchain_exception, 30010, "asset divide by self" );
   FC_DECLARE_DERIVED_EXCEPTION( asset_divide_by_zero,              goopal::blockchain::blockchain_exception, 30011, "asset divide by zero" );
   FC_DECLARE_DERIVED_EXCEPTION( new_database_version,              goopal::blockchain::blockchain_exception, 30012, "new database version" );
   FC_DECLARE_DERIVED_EXCEPTION( unlinkable_block,                  goopal::blockchain::blockchain_exception, 30013, "unlinkable block" );
   FC_DECLARE_DERIVED_EXCEPTION( price_out_of_range,                goopal::blockchain::blockchain_exception, 30014, "price out of range" );

   FC_DECLARE_DERIVED_EXCEPTION( block_numbers_not_sequential,      goopal::blockchain::blockchain_exception, 30015, "block numbers not sequential" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_previous_block_id,         goopal::blockchain::blockchain_exception, 30016, "invalid previous block" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_block_time,                goopal::blockchain::blockchain_exception, 30017, "invalid block time" );
   FC_DECLARE_DERIVED_EXCEPTION( time_in_past,                      goopal::blockchain::blockchain_exception, 30018, "time is in the past" );
   FC_DECLARE_DERIVED_EXCEPTION( time_in_future,                    goopal::blockchain::blockchain_exception, 30019, "time is in the future" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_block_digest,              goopal::blockchain::blockchain_exception, 30020, "invalid block digest" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_delegate_signee,           goopal::blockchain::blockchain_exception, 30021, "invalid delegate signee" );
   FC_DECLARE_DERIVED_EXCEPTION( failed_checkpoint_verification,    goopal::blockchain::blockchain_exception, 30022, "failed checkpoint verification" );
   FC_DECLARE_DERIVED_EXCEPTION( wrong_chain_id,                    goopal::blockchain::blockchain_exception, 30023, "wrong chain id" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_block,                     goopal::blockchain::blockchain_exception, 30024, "unknown block" );
   FC_DECLARE_DERIVED_EXCEPTION( block_older_than_undo_history,     goopal::blockchain::blockchain_exception, 30025, "block is older than our undo history allows us to process" );

   FC_DECLARE_EXCEPTION( evaluation_error, 31000, "Evaluation Error" );
   FC_DECLARE_DERIVED_EXCEPTION( negative_deposit,                  goopal::blockchain::evaluation_error, 31001, "negative deposit" );
   FC_DECLARE_DERIVED_EXCEPTION( not_a_delegate,                    goopal::blockchain::evaluation_error, 31002, "not a delegate" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_balance_entry,            goopal::blockchain::evaluation_error, 31003, "unknown balance entry" );
   FC_DECLARE_DERIVED_EXCEPTION( insufficient_funds,                goopal::blockchain::evaluation_error, 31004, "insufficient funds" );
   FC_DECLARE_DERIVED_EXCEPTION( missing_signature,                 goopal::blockchain::evaluation_error, 31005, "missing signature" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_claim_password,            goopal::blockchain::evaluation_error, 31006, "invalid claim password" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_withdraw_condition,        goopal::blockchain::evaluation_error, 31007, "invalid withdraw condition" );
   FC_DECLARE_DERIVED_EXCEPTION( negative_withdraw,                 goopal::blockchain::evaluation_error, 31008, "negative withdraw" );
   FC_DECLARE_DERIVED_EXCEPTION( not_an_active_delegate,            goopal::blockchain::evaluation_error, 31009, "not an active delegate" );
   FC_DECLARE_DERIVED_EXCEPTION( expired_transaction,               goopal::blockchain::evaluation_error, 31010, "expired transaction" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_transaction_expiration,    goopal::blockchain::evaluation_error, 31011, "invalid transaction expiration" );
   FC_DECLARE_DERIVED_EXCEPTION( oversized_transaction,             goopal::blockchain::evaluation_error, 31012, "transaction exceeded the maximum transaction size" );

   FC_DECLARE_DERIVED_EXCEPTION( invalid_account_name,              goopal::blockchain::evaluation_error, 32001, "invalid account name" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_account_id,                goopal::blockchain::evaluation_error, 32002, "unknown account id" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_account_name,              goopal::blockchain::evaluation_error, 32003, "unknown account name" );
   FC_DECLARE_DERIVED_EXCEPTION( account_expired,                   goopal::blockchain::evaluation_error, 32006, "account expired" );
   FC_DECLARE_DERIVED_EXCEPTION( account_already_registered,        goopal::blockchain::evaluation_error, 32007, "account already registered" );
   FC_DECLARE_DERIVED_EXCEPTION( account_key_in_use,                goopal::blockchain::evaluation_error, 32008, "account key already in use" );
   FC_DECLARE_DERIVED_EXCEPTION( account_retracted,                 goopal::blockchain::evaluation_error, 32009, "account retracted" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_delegate_slate,            goopal::blockchain::evaluation_error, 32011, "unknown delegate slate" );
   FC_DECLARE_DERIVED_EXCEPTION( too_may_delegates_in_slate,        goopal::blockchain::evaluation_error, 32012, "too many delegates in slate" );
   FC_DECLARE_DERIVED_EXCEPTION( pay_balance_remaining,             goopal::blockchain::evaluation_error, 32013, "pay balance remaining" );
   FC_DECLARE_DERIVED_EXCEPTION( message_too_long,                  goopal::blockchain::evaluation_error, 32014, "message is to long");

   FC_DECLARE_DERIVED_EXCEPTION( not_a_delegate_signature,          goopal::blockchain::evaluation_error, 33002, "not delegates signature" );

   FC_DECLARE_DERIVED_EXCEPTION( invalid_precision,                 goopal::blockchain::evaluation_error, 35001, "invalid precision" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_asset_symbol,              goopal::blockchain::evaluation_error, 35002, "invalid asset symbol" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_asset_id,                  goopal::blockchain::evaluation_error, 35003, "unknown asset id" );
   FC_DECLARE_DERIVED_EXCEPTION( asset_symbol_in_use,               goopal::blockchain::evaluation_error, 35004, "asset symbol in use" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_asset_amount,              goopal::blockchain::evaluation_error, 35005, "invalid asset amount" );
   FC_DECLARE_DERIVED_EXCEPTION( negative_issue,                    goopal::blockchain::evaluation_error, 35006, "negative issue" );
   FC_DECLARE_DERIVED_EXCEPTION( over_issue,                        goopal::blockchain::evaluation_error, 35007, "over issue" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_asset_symbol,              goopal::blockchain::evaluation_error, 35008, "unknown asset symbol" );
   FC_DECLARE_DERIVED_EXCEPTION( asset_id_in_use,                   goopal::blockchain::evaluation_error, 35009, "asset id in use" );
   FC_DECLARE_DERIVED_EXCEPTION( not_user_issued,                   goopal::blockchain::evaluation_error, 35010, "not user issued" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_asset_name,                goopal::blockchain::evaluation_error, 35011, "invalid asset name" );

   FC_DECLARE_DERIVED_EXCEPTION( delegate_vote_limit,               goopal::blockchain::evaluation_error, 36001, "delegate_vote_limit" );
   FC_DECLARE_DERIVED_EXCEPTION( insufficient_fee,                  goopal::blockchain::evaluation_error, 36002, "insufficient fee" );
   FC_DECLARE_DERIVED_EXCEPTION( negative_fee,                      goopal::blockchain::evaluation_error, 36003, "negative fee" );
   FC_DECLARE_DERIVED_EXCEPTION( missing_deposit,                   goopal::blockchain::evaluation_error, 36004, "missing deposit" );
   FC_DECLARE_DERIVED_EXCEPTION( insufficient_relay_fee,            goopal::blockchain::evaluation_error, 36005, "insufficient relay fee" );

   FC_DECLARE_DERIVED_EXCEPTION( invalid_market,                    goopal::blockchain::evaluation_error, 37001, "invalid market" );
   FC_DECLARE_DERIVED_EXCEPTION( unknown_market_order,              goopal::blockchain::evaluation_error, 37002, "unknown market order" );
   FC_DECLARE_DERIVED_EXCEPTION( shorting_base_shares,              goopal::blockchain::evaluation_error, 37003, "shorting base shares" );
   FC_DECLARE_DERIVED_EXCEPTION( insufficient_collateral,           goopal::blockchain::evaluation_error, 37004, "insufficient collateral" );
   FC_DECLARE_DERIVED_EXCEPTION( insufficient_depth,                goopal::blockchain::evaluation_error, 37005, "insufficient depth" );
   FC_DECLARE_DERIVED_EXCEPTION( insufficient_feeds,                goopal::blockchain::evaluation_error, 37006, "insufficient feeds" );
   FC_DECLARE_DERIVED_EXCEPTION( invalid_feed_price,                goopal::blockchain::evaluation_error, 37007, "invalid feed price" );

   FC_DECLARE_DERIVED_EXCEPTION( price_multiplication_overflow,     goopal::blockchain::evaluation_error, 38001, "price multiplication overflow" );
   FC_DECLARE_DERIVED_EXCEPTION( price_multiplication_underflow,    goopal::blockchain::evaluation_error, 38002, "price multiplication underflow" );
   FC_DECLARE_DERIVED_EXCEPTION( price_multiplication_undefined,    goopal::blockchain::evaluation_error, 38003, "price multiplication undefined product 0*inf" );

} } // goopal::blockchain
