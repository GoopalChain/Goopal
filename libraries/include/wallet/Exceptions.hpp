#pragma once

#include <fc/exception/exception.hpp>

namespace goopal { namespace wallet {

  FC_DECLARE_EXCEPTION        ( wallet_exception,                                          20000, "wallet error" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_password,           goopal::wallet::wallet_exception, 20001, "invalid password" );
  FC_DECLARE_DERIVED_EXCEPTION( wallet_locked,              goopal::wallet::wallet_exception, 20002, "wallet locked" );
  FC_DECLARE_DERIVED_EXCEPTION( wallet_already_exists,      goopal::wallet::wallet_exception, 20003, "wallet already exists" );
  FC_DECLARE_DERIVED_EXCEPTION( no_such_wallet,             goopal::wallet::wallet_exception, 20004, "wallet does not exist" );
  FC_DECLARE_DERIVED_EXCEPTION( unknown_receive_account,    goopal::wallet::wallet_exception, 20005, "unknown receive account" );
  FC_DECLARE_DERIVED_EXCEPTION( unknown_account,            goopal::wallet::wallet_exception, 20006, "unknown account" );
  FC_DECLARE_DERIVED_EXCEPTION( wallet_closed,              goopal::wallet::wallet_exception, 20007, "wallet closed" );
  FC_DECLARE_DERIVED_EXCEPTION( negative_bid,               goopal::wallet::wallet_exception, 20008, "negative bid" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_price,              goopal::wallet::wallet_exception, 20009, "invalid price" );
  FC_DECLARE_DERIVED_EXCEPTION( insufficient_funds,         goopal::wallet::wallet_exception, 20010, "insufficient funds" );
  FC_DECLARE_DERIVED_EXCEPTION( unknown_market_order,       goopal::wallet::wallet_exception, 20011, "unknown market order" );
  FC_DECLARE_DERIVED_EXCEPTION( fee_greater_than_amount,    goopal::wallet::wallet_exception, 20012, "fee greater than amount" );
  FC_DECLARE_DERIVED_EXCEPTION( unknown_address,            goopal::wallet::wallet_exception, 20013, "unknown address" );
  FC_DECLARE_DERIVED_EXCEPTION( brain_key_too_short,        goopal::wallet::wallet_exception, 20014, "brain key is too short" );
  FC_DECLARE_DERIVED_EXCEPTION( password_too_short,         goopal::wallet::wallet_exception, 20015, "password too short" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_timestamp,          goopal::wallet::wallet_exception, 20016, "invalid timestamp" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_name,               goopal::wallet::wallet_exception, 20017, "invalid account name" );
  FC_DECLARE_DERIVED_EXCEPTION( file_already_exists,        goopal::wallet::wallet_exception, 20018, "file already exists" );
  FC_DECLARE_DERIVED_EXCEPTION( file_not_found,             goopal::wallet::wallet_exception, 20019, "file not found" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_timeout,            goopal::wallet::wallet_exception, 20020, "invalid timeout" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_operation,          goopal::wallet::wallet_exception, 20021, "invalid operation" );
  FC_DECLARE_DERIVED_EXCEPTION( transaction_not_found,      goopal::wallet::wallet_exception, 20022, "transaction not found" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_transaction_id,     goopal::wallet::wallet_exception, 20023, "invalid transaction id" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_asset_symbol,       goopal::wallet::wallet_exception, 20024, "invalid asset symbol" );
  FC_DECLARE_DERIVED_EXCEPTION( duplicate_account_name,     goopal::wallet::wallet_exception, 20025, "duplicate account name" );
  FC_DECLARE_DERIVED_EXCEPTION( not_contact_account,        goopal::wallet::wallet_exception, 20026, "not contact account" );
  FC_DECLARE_DERIVED_EXCEPTION( memo_too_long,              goopal::wallet::wallet_exception, 20027, "memo too long" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_pay_rate,           goopal::wallet::wallet_exception, 20028, "invalid pay rate" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_wallet_name,        goopal::wallet::wallet_exception, 20029, "invalid wallet name" );
  FC_DECLARE_DERIVED_EXCEPTION( unsupported_version,        goopal::wallet::wallet_exception, 20030, "unsupported version" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_fee,                goopal::wallet::wallet_exception, 20031, "invalid fee" );
  FC_DECLARE_DERIVED_EXCEPTION( key_already_registered,     goopal::wallet::wallet_exception, 20032, "key belongs to other account" );
  FC_DECLARE_DERIVED_EXCEPTION( double_cover,               goopal::wallet::wallet_exception, 20033, "double cover" );
  FC_DECLARE_DERIVED_EXCEPTION( stupid_order,               goopal::wallet::wallet_exception, 20034, "stupid order" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_expiration_time,    goopal::wallet::wallet_exception, 20035, "invalid expiration time" );
  FC_DECLARE_DERIVED_EXCEPTION( bad_collateral_amount,      goopal::wallet::wallet_exception, 20036, "bad collateral amount" );
  FC_DECLARE_DERIVED_EXCEPTION( unknown_slate,              goopal::wallet::wallet_exception, 20037, "unknown slate" );
  FC_DECLARE_DERIVED_EXCEPTION( duplicate_key,              goopal::wallet::wallet_exception, 20038, "duplicate key" );
  FC_DECLARE_DERIVED_EXCEPTION( unauthorized_child_account, goopal::wallet::wallet_exception, 20039, "unauthorized child account" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_slate,              goopal::wallet::wallet_exception, 20040, "invalid slate" );
  FC_DECLARE_DERIVED_EXCEPTION( private_key_not_found,      goopal::wallet::wallet_exception, 20041, "private key not found" );
  FC_DECLARE_DERIVED_EXCEPTION( invalid_cancel,             goopal::wallet::wallet_exception, 20042, "invalid cancel" );
  FC_DECLARE_DERIVED_EXCEPTION( account_not_registered,     goopal::wallet::wallet_exception, 20043, "account not registered" );
FC_DECLARE_DERIVED_EXCEPTION( invalid_contact,              goopal::wallet::wallet_exception, 20044, "invalid contact" );
FC_DECLARE_DERIVED_EXCEPTION( label_already_in_use,         goopal::wallet::wallet_exception, 20045, "label already in use" );
FC_DECLARE_DERIVED_EXCEPTION(invalid_delegate_pay_rate, goopal::wallet::wallet_exception, 20046, "invalid_delegate_pay_rate");
FC_DECLARE_DERIVED_EXCEPTION(invalid_transaction_imessage_fee_coe, goopal::wallet::wallet_exception, 20047, "invalid_transaction_fee_coe");
FC_DECLARE_DERIVED_EXCEPTION(invalid_transaction_imessage_soft_length, goopal::wallet::wallet_exception, 20048, "invalid_transaction_soft_max length");
FC_DECLARE_DERIVED_EXCEPTION(imessage_size_bigger_than_soft_max_lenth, goopal::wallet::wallet_exception, 20049, "imessage size bigger than soft_max_lenth");

} } // goopal::wallet
