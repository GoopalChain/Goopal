#define DEFAULT_LOGGER "rpc"
#include <api/GlobalApiLogger.hpp>
#include <api/ConversionFunctions.hpp>
#include <rpc_stubs/CommonApiClient.hpp>

namespace goopal { namespace rpc_stubs {

fc::variant_object CommonApiClient::blockchain_get_info() const
{
  ilog("received RPC call: blockchain_get_info()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->blockchain_get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_generate_snapshot(const std::string& filename) const
{
  ilog("received RPC call: blockchain_generate_snapshot(${filename})", ("filename", filename));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "blockchain_generate_snapshot", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_generate_snapshot finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_generate_snapshot(filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_generate_snapshot", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::GopTrxidBalance> CommonApiClient::blockchain_get_gop_account_balance_entry(uint32_t block_num)
{
  ilog("received RPC call: blockchain_get_gop_account_balance_entry(${block_num})", ("block_num", block_num));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block_num) );
    call_id = glog->log_call_started( this, "blockchain_get_gop_account_balance_entry", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_gop_account_balance_entry finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::GopTrxidBalance> result = get_impl()->blockchain_get_gop_account_balance_entry(block_num);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_gop_account_balance_entry", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_generate_issuance_map(const std::string& symbol, const std::string& filename) const
{
  ilog("received RPC call: blockchain_generate_issuance_map(${symbol}, ${filename})", ("symbol", symbol)("filename", filename));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "blockchain_generate_issuance_map", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_generate_issuance_map finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_generate_issuance_map(symbol, filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_generate_issuance_map", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::Asset CommonApiClient::blockchain_calculate_supply(const std::string& asset) const
{
  ilog("received RPC call: blockchain_calculate_supply(${asset})", ("asset", asset));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(asset) );
    call_id = glog->log_call_started( this, "blockchain_calculate_supply", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_calculate_supply finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::Asset result = get_impl()->blockchain_calculate_supply(asset);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_calculate_supply", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::blockchain_is_synced() const
{
  ilog("received RPC call: blockchain_is_synced()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_is_synced", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_is_synced finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->blockchain_is_synced();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_is_synced", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

uint32_t CommonApiClient::blockchain_get_block_count() const
{
  ilog("received RPC call: blockchain_get_block_count()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_block_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    uint32_t result = get_impl()->blockchain_get_block_count();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block_count", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::BlockchainSecurityState CommonApiClient::blockchain_get_security_state() const
{
  ilog("received RPC call: blockchain_get_security_state()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_security_state", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_security_state finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::BlockchainSecurityState result = get_impl()->blockchain_get_security_state();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_security_state", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::AccountEntry> CommonApiClient::blockchain_list_accounts(const std::string& first_account_name /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_accounts(${first_account_name}, ${limit})", ("first_account_name", first_account_name)("limit", limit));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first_account_name) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::AccountEntry> result = get_impl()->blockchain_list_accounts(first_account_name, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::AccountEntry> CommonApiClient::blockchain_list_recently_updated_accounts() const
{
  ilog("received RPC call: blockchain_list_recently_updated_accounts()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_recently_updated_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_recently_updated_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::AccountEntry> result = get_impl()->blockchain_list_recently_updated_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_recently_updated_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::AccountEntry> CommonApiClient::blockchain_list_recently_registered_accounts() const
{
  ilog("received RPC call: blockchain_list_recently_registered_accounts()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_recently_registered_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_recently_registered_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::AccountEntry> result = get_impl()->blockchain_list_recently_registered_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_recently_registered_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::AssetEntry> CommonApiClient::blockchain_list_assets(const std::string& first_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_assets(${first_symbol}, ${limit})", ("first_symbol", first_symbol)("limit", limit));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first_symbol) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_assets", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_assets finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::AssetEntry> result = get_impl()->blockchain_list_assets(first_symbol, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_assets", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::pair<goopal::blockchain::TransactionIdType, goopal::blockchain::SignedTransaction>> CommonApiClient::blockchain_list_pending_transactions() const
{
  ilog("received RPC call: blockchain_list_pending_transactions()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_pending_transactions", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_pending_transactions finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::pair<goopal::blockchain::TransactionIdType, goopal::blockchain::SignedTransaction>> result = get_impl()->blockchain_list_pending_transactions();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_pending_transactions", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::pair<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> CommonApiClient::blockchain_get_transaction(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: blockchain_get_transaction(${transaction_id_prefix}, ${exact})", ("transaction_id_prefix", transaction_id_prefix)("exact", exact));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    args.push_back( fc::variant(exact) );
    call_id = glog->log_call_started( this, "blockchain_get_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::pair<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> result = get_impl()->blockchain_get_transaction(transaction_id_prefix, exact);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::PrettyTransaction CommonApiClient::blockchain_get_pretty_transaction(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: blockchain_get_pretty_transaction(${transaction_id_prefix}, ${exact})", ("transaction_id_prefix", transaction_id_prefix)("exact", exact));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    args.push_back( fc::variant(exact) );
    call_id = glog->log_call_started( this, "blockchain_get_pretty_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_pretty_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::PrettyTransaction result = get_impl()->blockchain_get_pretty_transaction(transaction_id_prefix, exact);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_pretty_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<goopal::blockchain::BlockEntry> CommonApiClient::blockchain_get_block(const std::string& block) const
{
  ilog("received RPC call: blockchain_get_block(${block})", ("block", block));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block) );
    call_id = glog->log_call_started( this, "blockchain_get_block", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<goopal::blockchain::BlockEntry> result = get_impl()->blockchain_get_block(block);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> CommonApiClient::blockchain_get_block_transactions(const std::string& block) const
{
  ilog("received RPC call: blockchain_get_block_transactions(${block})", ("block", block));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block) );
    call_id = glog->log_call_started( this, "blockchain_get_block_transactions", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block_transactions finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> result = get_impl()->blockchain_get_block_transactions(block);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block_transactions", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<goopal::blockchain::AccountEntry> CommonApiClient::blockchain_get_account(const std::string& account) const
{
  ilog("received RPC call: blockchain_get_account(${account})", ("account", account));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account) );
    call_id = glog->log_call_started( this, "blockchain_get_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<goopal::blockchain::AccountEntry> result = get_impl()->blockchain_get_account(account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_account", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<goopal::blockchain::AccountIdType, std::string> CommonApiClient::blockchain_get_slate(const std::string& slate) const
{
  ilog("received RPC call: blockchain_get_slate(${slate})", ("slate", slate));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(slate) );
    call_id = glog->log_call_started( this, "blockchain_get_slate", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_slate finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<goopal::blockchain::AccountIdType, std::string> result = get_impl()->blockchain_get_slate(slate);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_slate", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::BalanceEntry CommonApiClient::blockchain_get_balance(const goopal::blockchain::Address& balance_id) const
{
  ilog("received RPC call: blockchain_get_balance(${balance_id})", ("balance_id", balance_id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(balance_id) );
    call_id = glog->log_call_started( this, "blockchain_get_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::BalanceEntry result = get_impl()->blockchain_get_balance(balance_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> CommonApiClient::blockchain_list_balances(const std::string& first_balance_id /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_balances(${first_balance_id}, ${limit})", ("first_balance_id", first_balance_id)("limit", limit));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first_balance_id) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> result = get_impl()->blockchain_list_balances(first_balance_id, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> CommonApiClient::blockchain_list_address_balances(const std::string& addr, const fc::time_point& chanced_since /* = fc::json::from_string("\"1970-1-1T00:00:01\"").as<fc::time_point>() */) const
{
  ilog("received RPC call: blockchain_list_address_balances(${addr}, ${chanced_since})", ("addr", addr)("chanced_since", chanced_since));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(addr) );
    args.push_back( fc::variant(chanced_since) );
    call_id = glog->log_call_started( this, "blockchain_list_address_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_address_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> result = get_impl()->blockchain_list_address_balances(addr, chanced_since);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_address_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::blockchain_list_address_transactions(const std::string& addr, uint32_t filter_before /* = fc::json::from_string("\"0\"").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_address_transactions(${addr}, ${filter_before})", ("addr", addr)("filter_before", filter_before));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(addr) );
    args.push_back( fc::variant(filter_before) );
    call_id = glog->log_call_started( this, "blockchain_list_address_transactions", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_address_transactions finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->blockchain_list_address_transactions(addr, filter_before);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_address_transactions", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::AccountBalanceSummaryType CommonApiClient::blockchain_get_account_public_balance(const std::string& account_name) const
{
  ilog("received RPC call: blockchain_get_account_public_balance(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "blockchain_get_account_public_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_account_public_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::AccountBalanceSummaryType result = get_impl()->blockchain_get_account_public_balance(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_account_public_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> CommonApiClient::blockchain_list_key_balances(const goopal::blockchain::PublicKeyType& key) const
{
  ilog("received RPC call: blockchain_list_key_balances(${key})", ("key", key));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(key) );
    call_id = glog->log_call_started( this, "blockchain_list_key_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_key_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> result = get_impl()->blockchain_list_key_balances(key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_key_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<goopal::blockchain::AssetEntry> CommonApiClient::blockchain_get_asset(const std::string& asset) const
{
  ilog("received RPC call: blockchain_get_asset(${asset})", ("asset", asset));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(asset) );
    call_id = glog->log_call_started( this, "blockchain_get_asset", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_asset finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<goopal::blockchain::AssetEntry> result = get_impl()->blockchain_get_asset(asset);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_asset", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::AccountEntry> CommonApiClient::blockchain_list_active_delegates(uint32_t first /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t count /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_active_delegates(${first}, ${count})", ("first", first)("count", count));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first) );
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "blockchain_list_active_delegates", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_active_delegates finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::AccountEntry> result = get_impl()->blockchain_list_active_delegates(first, count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_active_delegates", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::AccountEntry> CommonApiClient::blockchain_list_delegates(uint32_t first /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t count /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_delegates(${first}, ${count})", ("first", first)("count", count));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first) );
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "blockchain_list_delegates", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_delegates finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::AccountEntry> result = get_impl()->blockchain_list_delegates(first, count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_delegates", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::BlockEntry> CommonApiClient::blockchain_list_blocks(uint32_t max_block_num /* = fc::json::from_string("-1").as<uint32_t>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */)
{
  ilog("received RPC call: blockchain_list_blocks(${max_block_num}, ${limit})", ("max_block_num", max_block_num)("limit", limit));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(max_block_num) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_blocks", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_blocks finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::BlockEntry> result = get_impl()->blockchain_list_blocks(max_block_num, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_blocks", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::blockchain_list_missing_block_delegates(uint32_t block_number)
{
  ilog("received RPC call: blockchain_list_missing_block_delegates(${block_number})", ("block_number", block_number));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block_number) );
    call_id = glog->log_call_started( this, "blockchain_list_missing_block_delegates", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_missing_block_delegates finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->blockchain_list_missing_block_delegates(block_number);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_missing_block_delegates", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::blockchain_export_fork_graph(uint32_t start_block /* = fc::json::from_string("1").as<uint32_t>() */, uint32_t end_block /* = fc::json::from_string("-1").as<uint32_t>() */, const goopal::blockchain::FilePath& filename /* = fc::json::from_string("\"\"").as<goopal::blockchain::FilePath>() */) const
{
  ilog("received RPC call: blockchain_export_fork_graph(${start_block}, ${end_block}, ${filename})", ("start_block", start_block)("end_block", end_block)("filename", filename));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(start_block) );
    args.push_back( fc::variant(end_block) );
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "blockchain_export_fork_graph", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_export_fork_graph finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->blockchain_export_fork_graph(start_block, end_block, filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_export_fork_graph", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<uint32_t, std::vector<goopal::blockchain::ForkEntry>> CommonApiClient::blockchain_list_forks() const
{
  ilog("received RPC call: blockchain_list_forks()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_forks", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_forks finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<uint32_t, std::vector<goopal::blockchain::ForkEntry>> result = get_impl()->blockchain_list_forks();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_forks", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::SlotEntry> CommonApiClient::blockchain_get_delegate_slot_entrys(const std::string& delegate_name, uint32_t limit /* = fc::json::from_string("\"10\"").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_get_delegate_slot_entrys(${delegate_name}, ${limit})", ("delegate_name", delegate_name)("limit", limit));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_get_delegate_slot_entrys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_delegate_slot_entrys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::SlotEntry> result = get_impl()->blockchain_get_delegate_slot_entrys(delegate_name, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_delegate_slot_entrys", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::blockchain_get_block_signee(const std::string& block) const
{
  ilog("received RPC call: blockchain_get_block_signee(${block})", ("block", block));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block) );
    call_id = glog->log_call_started( this, "blockchain_get_block_signee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block_signee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->blockchain_get_block_signee(block);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block_signee", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::Asset CommonApiClient::blockchain_unclaimed_genesis() const
{
  ilog("received RPC call: blockchain_unclaimed_genesis()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_unclaimed_genesis", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_unclaimed_genesis finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::Asset result = get_impl()->blockchain_unclaimed_genesis();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_unclaimed_genesis", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::blockchain_verify_signature(const std::string& signer, const fc::sha256& hash, const fc::ecc::compact_signature& signature) const
{
  ilog("received RPC call: blockchain_verify_signature(${signer}, ${hash}, ${signature})", ("signer", signer)("hash", hash)("signature", signature));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(signer) );
    args.push_back( fc::variant(hash) );
    args.push_back( fc::variant(signature) );
    call_id = glog->log_call_started( this, "blockchain_verify_signature", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_verify_signature finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->blockchain_verify_signature(signer, hash, signature);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_verify_signature", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_dump_state(const std::string& path) const
{
  ilog("received RPC call: blockchain_dump_state(${path})", ("path", path));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(path) );
    call_id = glog->log_call_started( this, "blockchain_dump_state", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_dump_state finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_dump_state(path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_dump_state", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_broadcast_transaction(const goopal::blockchain::SignedTransaction& trx)
{
  ilog("received RPC call: blockchain_broadcast_transaction(${trx})", ("trx", trx));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(trx) );
    call_id = glog->log_call_started( this, "blockchain_broadcast_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_broadcast_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_broadcast_transaction(trx);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_broadcast_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_btc_address_convert(const std::string& path) const
{
  ilog("received RPC call: blockchain_btc_address_convert(${path})", ("path", path));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(path) );
    call_id = glog->log_call_started( this, "blockchain_btc_address_convert", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_btc_address_convert finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_btc_address_convert(path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_btc_address_convert", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::blockchain_get_transaction_rpc(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: blockchain_get_transaction_rpc(${transaction_id_prefix}, ${exact})", ("transaction_id_prefix", transaction_id_prefix)("exact", exact));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    args.push_back( fc::variant(exact) );
    call_id = glog->log_call_started( this, "blockchain_get_transaction_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_transaction_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->blockchain_get_transaction_rpc(transaction_id_prefix, exact);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_transaction_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::network_add_node(const std::string& node, const std::string& command /* = fc::json::from_string("\"add\"").as<std::string>() */)
{
  ilog("received RPC call: network_add_node(${node}, ${command})", ("node", node)("command", command));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(node) );
    args.push_back( fc::variant(command) );
    call_id = glog->log_call_started( this, "network_add_node", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_add_node finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->network_add_node(node, command);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_add_node", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

uint32_t CommonApiClient::network_get_connection_count() const
{
  ilog("received RPC call: network_get_connection_count()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_connection_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_connection_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    uint32_t result = get_impl()->network_get_connection_count();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_connection_count", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<fc::variant_object> CommonApiClient::network_get_peer_info(bool not_firewalled /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: network_get_peer_info(${not_firewalled})", ("not_firewalled", not_firewalled));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(not_firewalled) );
    call_id = glog->log_call_started( this, "network_get_peer_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_peer_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<fc::variant_object> result = get_impl()->network_get_peer_info(not_firewalled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_peer_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::TransactionIdType CommonApiClient::network_broadcast_transaction(const goopal::blockchain::SignedTransaction& transaction_to_broadcast)
{
  ilog("received RPC call: network_broadcast_transaction(${transaction_to_broadcast})", ("transaction_to_broadcast", transaction_to_broadcast));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_to_broadcast) );
    call_id = glog->log_call_started( this, "network_broadcast_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_broadcast_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::TransactionIdType result = get_impl()->network_broadcast_transaction(transaction_to_broadcast);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_broadcast_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::network_set_advanced_node_parameters(const fc::variant_object& params)
{
  ilog("received RPC call: network_set_advanced_node_parameters(${params})", ("params", params));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(params) );
    call_id = glog->log_call_started( this, "network_set_advanced_node_parameters", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_set_advanced_node_parameters finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->network_set_advanced_node_parameters(params);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_set_advanced_node_parameters", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::network_get_advanced_node_parameters() const
{
  ilog("received RPC call: network_get_advanced_node_parameters()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_advanced_node_parameters", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_advanced_node_parameters finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->network_get_advanced_node_parameters();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_advanced_node_parameters", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::net::MessagePropagationData CommonApiClient::network_get_transaction_propagation_data(const goopal::blockchain::TransactionIdType& transaction_id)
{
  ilog("received RPC call: network_get_transaction_propagation_data(${transaction_id})", ("transaction_id", transaction_id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "network_get_transaction_propagation_data", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_transaction_propagation_data finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::net::MessagePropagationData result = get_impl()->network_get_transaction_propagation_data(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_transaction_propagation_data", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::net::MessagePropagationData CommonApiClient::network_get_block_propagation_data(const goopal::blockchain::BlockIdType& block_hash)
{
  ilog("received RPC call: network_get_block_propagation_data(${block_hash})", ("block_hash", block_hash));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block_hash) );
    call_id = glog->log_call_started( this, "network_get_block_propagation_data", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_block_propagation_data finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::net::MessagePropagationData result = get_impl()->network_get_block_propagation_data(block_hash);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_block_propagation_data", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::network_get_info() const
{
  ilog("received RPC call: network_get_info()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->network_get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::net::PotentialPeerEntry> CommonApiClient::network_list_potential_peers() const
{
  ilog("received RPC call: network_list_potential_peers()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_list_potential_peers", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_list_potential_peers finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::net::PotentialPeerEntry> result = get_impl()->network_list_potential_peers();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_list_potential_peers", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::network_get_upnp_info() const
{
  ilog("received RPC call: network_get_upnp_info()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_upnp_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_upnp_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->network_get_upnp_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_upnp_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::network_get_blocked_ips() const
{
  ilog("received RPC call: network_get_blocked_ips()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_blocked_ips", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_blocked_ips finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->network_get_blocked_ips();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_blocked_ips", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::debug_get_client_name() const
{
  ilog("received RPC call: debug_get_client_name()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "debug_get_client_name", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call debug_get_client_name finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->debug_get_client_name();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "debug_get_client_name", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant CommonApiClient::delegate_get_config() const
{
  ilog("received RPC call: delegate_get_config()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "delegate_get_config", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_get_config finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant result = get_impl()->delegate_get_config();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_get_config", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_network_min_connection_count(uint32_t count)
{
  ilog("received RPC call: delegate_set_network_min_connection_count(${count})", ("count", count));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "delegate_set_network_min_connection_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_network_min_connection_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_network_min_connection_count(count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_network_min_connection_count", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_block_max_transaction_count(uint32_t count)
{
  ilog("received RPC call: delegate_set_block_max_transaction_count(${count})", ("count", count));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "delegate_set_block_max_transaction_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_block_max_transaction_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_block_max_transaction_count(count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_block_max_transaction_count", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_soft_max_imessage_length(int64_t soft_length)
{
  ilog("received RPC call: delegate_set_soft_max_imessage_length(${soft_length})", ("soft_length", soft_length));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(soft_length) );
    call_id = glog->log_call_started( this, "delegate_set_soft_max_imessage_length", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_soft_max_imessage_length finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_soft_max_imessage_length(soft_length);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_soft_max_imessage_length", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_imessage_fee_coe(const std::string& fee_coe)
{
  ilog("received RPC call: delegate_set_imessage_fee_coe(${fee_coe})", ("fee_coe", fee_coe));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee_coe) );
    call_id = glog->log_call_started( this, "delegate_set_imessage_fee_coe", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_imessage_fee_coe finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_imessage_fee_coe(fee_coe);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_imessage_fee_coe", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_block_max_size(uint32_t size)
{
  ilog("received RPC call: delegate_set_block_max_size(${size})", ("size", size));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(size) );
    call_id = glog->log_call_started( this, "delegate_set_block_max_size", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_block_max_size finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_block_max_size(size);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_block_max_size", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_transaction_max_size(uint32_t size)
{
  ilog("received RPC call: delegate_set_transaction_max_size(${size})", ("size", size));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(size) );
    call_id = glog->log_call_started( this, "delegate_set_transaction_max_size", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_transaction_max_size finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_transaction_max_size(size);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_transaction_max_size", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_transaction_canonical_signatures_required(bool required)
{
  ilog("received RPC call: delegate_set_transaction_canonical_signatures_required(${required})", ("required", required));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(required) );
    call_id = glog->log_call_started( this, "delegate_set_transaction_canonical_signatures_required", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_transaction_canonical_signatures_required finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_transaction_canonical_signatures_required(required);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_transaction_canonical_signatures_required", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_transaction_min_fee(uint64_t fee)
{
  ilog("received RPC call: delegate_set_transaction_min_fee(${fee})", ("fee", fee));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee) );
    call_id = glog->log_call_started( this, "delegate_set_transaction_min_fee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_transaction_min_fee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_transaction_min_fee(fee);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_transaction_min_fee", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_add_transaction(const goopal::blockchain::TransactionIdType& id)
{
  ilog("received RPC call: delegate_blacklist_add_transaction(${id})", ("id", id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_add_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_add_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_add_transaction(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_add_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_remove_transaction(const goopal::blockchain::TransactionIdType& id)
{
  ilog("received RPC call: delegate_blacklist_remove_transaction(${id})", ("id", id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_remove_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_remove_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_remove_transaction(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_remove_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_add_operation(const goopal::blockchain::OperationTypeEnum& id)
{
  ilog("received RPC call: delegate_blacklist_add_operation(${id})", ("id", id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_add_operation", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_add_operation finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_add_operation(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_add_operation", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_remove_operation(const goopal::blockchain::OperationTypeEnum& id)
{
  ilog("received RPC call: delegate_blacklist_remove_operation(${id})", ("id", id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_remove_operation", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_remove_operation finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_remove_operation(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_remove_operation", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::wallet_get_info()
{
  ilog("received RPC call: wallet_get_info()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->wallet_get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_open(const std::string& wallet_name)
{
  ilog("received RPC call: wallet_open(${wallet_name})", ("wallet_name", wallet_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(wallet_name) );
    call_id = glog->log_call_started( this, "wallet_open", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_open finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_open(wallet_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_open", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_create(const std::string& wallet_name, const std::string& new_passphrase, const std::string& brain_key /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_create(${wallet_name}, *********, *********)", ("wallet_name", wallet_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(wallet_name) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(new_passphrase) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(brain_key) );
    call_id = glog->log_call_started( this, "wallet_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_create(wallet_name, new_passphrase, brain_key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_create", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<std::string> CommonApiClient::wallet_get_name() const
{
  ilog("received RPC call: wallet_get_name()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_name", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_name finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<std::string> result = get_impl()->wallet_get_name();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_name", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_import_private_key(const std::string& wif_key, const std::string& account_name /* = fc::json::from_string("null").as<std::string>() */, bool create_new_account /* = fc::json::from_string("false").as<bool>() */, bool rescan /* = fc::json::from_string("false").as<bool>() */)
{
  ilog("received RPC call: wallet_import_private_key(*********, ${account_name}, ${create_new_account}, ${rescan})", ("account_name", account_name)("create_new_account", create_new_account)("rescan", rescan));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(wif_key) );
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(create_new_account) );
    args.push_back( fc::variant(rescan) );
    call_id = glog->log_call_started( this, "wallet_import_private_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_import_private_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_import_private_key(wif_key, account_name, create_new_account, rescan);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_import_private_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_close()
{
  ilog("received RPC call: wallet_close()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_close", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_close finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_close();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_close", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_backup_create(const fc::path& json_filename) const
{
  ilog("received RPC call: wallet_backup_create(${json_filename})", ("json_filename", json_filename));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(json_filename) );
    call_id = glog->log_call_started( this, "wallet_backup_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_backup_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_backup_create(json_filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_backup_create", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_backup_restore(const fc::path& json_filename, const std::string& wallet_name, const std::string& imported_wallet_passphrase)
{
  ilog("received RPC call: wallet_backup_restore(${json_filename}, ${wallet_name}, *********)", ("json_filename", json_filename)("wallet_name", wallet_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(json_filename) );
    args.push_back( fc::variant(wallet_name) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(imported_wallet_passphrase) );
    call_id = glog->log_call_started( this, "wallet_backup_restore", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_backup_restore finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_backup_restore(json_filename, wallet_name, imported_wallet_passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_backup_restore", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_set_automatic_backups(bool enabled)
{
  ilog("received RPC call: wallet_set_automatic_backups(${enabled})", ("enabled", enabled));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(enabled) );
    call_id = glog->log_call_started( this, "wallet_set_automatic_backups", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_automatic_backups finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_set_automatic_backups(enabled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_automatic_backups", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

uint32_t CommonApiClient::wallet_set_transaction_expiration_time(uint32_t seconds)
{
  ilog("received RPC call: wallet_set_transaction_expiration_time(${seconds})", ("seconds", seconds));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(seconds) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_expiration_time", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_expiration_time finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    uint32_t result = get_impl()->wallet_set_transaction_expiration_time(seconds);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_expiration_time", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::wallet::PrettyTransaction> CommonApiClient::wallet_account_transaction_history(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */, const std::string& asset_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t limit /* = fc::json::from_string("0").as<int32_t>() */, uint32_t start_block_num /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t end_block_num /* = fc::json::from_string("-1").as<uint32_t>() */) const
{
  ilog("received RPC call: wallet_account_transaction_history(${account_name}, ${asset_symbol}, ${limit}, ${start_block_num}, ${end_block_num})", ("account_name", account_name)("asset_symbol", asset_symbol)("limit", limit)("start_block_num", start_block_num)("end_block_num", end_block_num));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(limit) );
    args.push_back( fc::variant(start_block_num) );
    args.push_back( fc::variant(end_block_num) );
    call_id = glog->log_call_started( this, "wallet_account_transaction_history", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_transaction_history finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::wallet::PrettyTransaction> result = get_impl()->wallet_account_transaction_history(account_name, asset_symbol, limit, start_block_num, end_block_num);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_transaction_history", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::wallet::PrettyTransaction> CommonApiClient::wallet_transaction_history_splite(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */, const std::string& asset_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t limit /* = fc::json::from_string("0").as<int32_t>() */, int32_t transaction_type /* = fc::json::from_string("\"2\"").as<int32_t>() */) const
{
  ilog("received RPC call: wallet_transaction_history_splite(${account_name}, ${asset_symbol}, ${limit}, ${transaction_type})", ("account_name", account_name)("asset_symbol", asset_symbol)("limit", limit)("transaction_type", transaction_type));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(limit) );
    args.push_back( fc::variant(transaction_type) );
    call_id = glog->log_call_started( this, "wallet_transaction_history_splite", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transaction_history_splite finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::wallet::PrettyTransaction> result = get_impl()->wallet_transaction_history_splite(account_name, asset_symbol, limit, transaction_type);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transaction_history_splite", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::AccountBalanceSummaryType CommonApiClient::wallet_account_historic_balance(const fc::time_point& time, const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_historic_balance(${time}, ${account_name})", ("time", time)("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(time) );
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_historic_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_historic_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::AccountBalanceSummaryType result = get_impl()->wallet_account_historic_balance(time, account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_historic_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_remove_transaction(const std::string& transaction_id)
{
  ilog("received RPC call: wallet_remove_transaction(${transaction_id})", ("transaction_id", transaction_id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "wallet_remove_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_remove_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_remove_transaction(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_remove_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<goopal::blockchain::TransactionIdType, fc::exception> CommonApiClient::wallet_get_pending_transaction_errors(const goopal::blockchain::FilePath& filename /* = fc::json::from_string("\"\"").as<goopal::blockchain::FilePath>() */) const
{
  ilog("received RPC call: wallet_get_pending_transaction_errors(${filename})", ("filename", filename));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "wallet_get_pending_transaction_errors", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_pending_transaction_errors finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<goopal::blockchain::TransactionIdType, fc::exception> result = get_impl()->wallet_get_pending_transaction_errors(filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_pending_transaction_errors", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_lock()
{
  ilog("received RPC call: wallet_lock()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_lock", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_lock finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_lock();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_lock", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_unlock(uint32_t timeout, const std::string& passphrase)
{
  ilog("received RPC call: wallet_unlock(${timeout}, *********)", ("timeout", timeout));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(timeout) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(passphrase) );
    call_id = glog->log_call_started( this, "wallet_unlock", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_unlock finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_unlock(timeout, passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_unlock", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_change_passphrase(const std::string& old_passphrase, const std::string& passphrase)
{
  ilog("received RPC call: wallet_change_passphrase(*********, *********)", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(old_passphrase) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(passphrase) );
    call_id = glog->log_call_started( this, "wallet_change_passphrase", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_change_passphrase finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_change_passphrase(old_passphrase, passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_change_passphrase", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_check_passphrase(const std::string& passphrase)
{
  ilog("received RPC call: wallet_check_passphrase(*********)", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(passphrase) );
    call_id = glog->log_call_started( this, "wallet_check_passphrase", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_check_passphrase finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_check_passphrase(passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_check_passphrase", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_check_address(const std::string& address)
{
  ilog("received RPC call: wallet_check_address(${address})", ("address", address));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(address) );
    call_id = glog->log_call_started( this, "wallet_check_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_check_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_check_address(address);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_check_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::wallet_list() const
{
  ilog("received RPC call: wallet_list()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->wallet_list();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::Address CommonApiClient::wallet_account_create(const std::string& account_name, const fc::variant& private_data /* = fc::json::from_string("null").as<fc::variant>() */)
{
  ilog("received RPC call: wallet_account_create(${account_name}, ${private_data})", ("account_name", account_name)("private_data", private_data));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(private_data) );
    call_id = glog->log_call_started( this, "wallet_account_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::Address result = get_impl()->wallet_account_create(account_name, private_data);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_create", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int8_t CommonApiClient::wallet_account_set_approval(const std::string& account_name, int8_t approval /* = fc::json::from_string("1").as<int8_t>() */)
{
  ilog("received RPC call: wallet_account_set_approval(${account_name}, ${approval})", ("account_name", account_name)("approval", approval));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(approval) );
    call_id = glog->log_call_started( this, "wallet_account_set_approval", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_set_approval finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int8_t result = get_impl()->wallet_account_set_approval(account_name, approval);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_set_approval", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::blockchain::AccountEntry> CommonApiClient::wallet_get_all_approved_accounts(int8_t approval /* = fc::json::from_string("1").as<int8_t>() */)
{
  ilog("received RPC call: wallet_get_all_approved_accounts(${approval})", ("approval", approval));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(approval) );
    call_id = glog->log_call_started( this, "wallet_get_all_approved_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_all_approved_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::blockchain::AccountEntry> result = get_impl()->wallet_get_all_approved_accounts(approval);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_all_approved_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_address_create(const std::string& account_name, const std::string& label /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t legacy_network_byte /* = fc::json::from_string("-1").as<int32_t>() */)
{
  ilog("received RPC call: wallet_address_create(${account_name}, ${label}, ${legacy_network_byte})", ("account_name", account_name)("label", label)("legacy_network_byte", legacy_network_byte));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(label) );
    args.push_back( fc::variant(legacy_network_byte) );
    call_id = glog->log_call_started( this, "wallet_address_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_address_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_address_create(account_name, label, legacy_network_byte);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_address_create", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_transfer_to_address(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_address, const goopal::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<goopal::blockchain::Imessage>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>() */)
{
  ilog("received RPC call: wallet_transfer_to_address(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_address}, ${memo_message}, ${strategy})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_address", to_address)("memo_message", memo_message)("strategy", strategy));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_address) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_transfer_to_address(amount_to_transfer, asset_symbol, from_account_name, to_address, memo_message, strategy);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_transfer_to_public_account(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_account_name, const goopal::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<goopal::blockchain::Imessage>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>() */)
{
  ilog("received RPC call: wallet_transfer_to_public_account(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_account_name}, ${memo_message}, ${strategy})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_account_name", to_account_name)("memo_message", memo_message)("strategy", strategy));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_public_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_public_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_transfer_to_public_account(amount_to_transfer, asset_symbol, from_account_name, to_account_name, memo_message, strategy);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_public_account", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::TransactionBuilder CommonApiClient::wallet_withdraw_from_address(const std::string& amount, const std::string& symbol, const goopal::blockchain::Address& from_address, const std::string& to, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_none\"").as<goopal::wallet::VoteStrategy>() */, bool sign_and_broadcast /* = fc::json::from_string("true").as<bool>() */, const std::string& builder_path /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_withdraw_from_address(${amount}, ${symbol}, ${from_address}, ${to}, ${strategy}, ${sign_and_broadcast}, ${builder_path})", ("amount", amount)("symbol", symbol)("from_address", from_address)("to", to)("strategy", strategy)("sign_and_broadcast", sign_and_broadcast)("builder_path", builder_path));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount) );
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(from_address) );
    args.push_back( fc::variant(to) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(sign_and_broadcast) );
    args.push_back( fc::variant(builder_path) );
    call_id = glog->log_call_started( this, "wallet_withdraw_from_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_withdraw_from_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::TransactionBuilder result = get_impl()->wallet_withdraw_from_address(amount, symbol, from_address, to, strategy, sign_and_broadcast, builder_path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_withdraw_from_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_rescan_blockchain(uint32_t start_block_num /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t limit /* = fc::json::from_string("-1").as<uint32_t>() */)
{
  ilog("received RPC call: wallet_rescan_blockchain(${start_block_num}, ${limit})", ("start_block_num", start_block_num)("limit", limit));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(start_block_num) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "wallet_rescan_blockchain", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_rescan_blockchain finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_rescan_blockchain(start_block_num, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_rescan_blockchain", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_cancel_scan()
{
  ilog("received RPC call: wallet_cancel_scan()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_cancel_scan", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_cancel_scan finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_cancel_scan();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_cancel_scan", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_get_transaction(const std::string& transaction_id)
{
  ilog("received RPC call: wallet_get_transaction(${transaction_id})", ("transaction_id", transaction_id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "wallet_get_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_get_transaction(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_scan_transaction(const std::string& transaction_id, bool overwrite_existing /* = fc::json::from_string("false").as<bool>() */)
{
  ilog("received RPC call: wallet_scan_transaction(${transaction_id}, ${overwrite_existing})", ("transaction_id", transaction_id)("overwrite_existing", overwrite_existing));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    args.push_back( fc::variant(overwrite_existing) );
    call_id = glog->log_call_started( this, "wallet_scan_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_scan_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_scan_transaction(transaction_id, overwrite_existing);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_scan_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_rebroadcast_transaction(const std::string& transaction_id)
{
  ilog("received RPC call: wallet_rebroadcast_transaction(${transaction_id})", ("transaction_id", transaction_id));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "wallet_rebroadcast_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_rebroadcast_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_rebroadcast_transaction(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_rebroadcast_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_account_register(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, uint8_t delegate_pay_rate /* = fc::json::from_string("-1").as<uint8_t>() */, const std::string& account_type /* = fc::json::from_string("\"titan_account\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_account_register(${account_name}, ${pay_from_account}, ${public_data}, ${delegate_pay_rate}, ${account_type})", ("account_name", account_name)("pay_from_account", pay_from_account)("public_data", public_data)("delegate_pay_rate", delegate_pay_rate)("account_type", account_type));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(pay_from_account) );
    args.push_back( fc::variant(public_data) );
    args.push_back( fc::variant(delegate_pay_rate) );
    args.push_back( fc::variant(account_type) );
    call_id = glog->log_call_started( this, "wallet_account_register", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_register finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_account_register(account_name, pay_from_account, public_data, delegate_pay_rate, account_type);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_register", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_account_update_private_data(const std::string& account_name, const fc::variant& private_data /* = fc::json::from_string("null").as<fc::variant>() */)
{
  ilog("received RPC call: wallet_account_update_private_data(${account_name}, ${private_data})", ("account_name", account_name)("private_data", private_data));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(private_data) );
    call_id = glog->log_call_started( this, "wallet_account_update_private_data", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_update_private_data finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_account_update_private_data(account_name, private_data);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_update_private_data", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_account_update_registration(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, uint8_t delegate_pay_rate /* = fc::json::from_string("-1").as<uint8_t>() */)
{
  ilog("received RPC call: wallet_account_update_registration(${account_name}, ${pay_from_account}, ${public_data}, ${delegate_pay_rate})", ("account_name", account_name)("pay_from_account", pay_from_account)("public_data", public_data)("delegate_pay_rate", delegate_pay_rate));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(pay_from_account) );
    args.push_back( fc::variant(public_data) );
    args.push_back( fc::variant(delegate_pay_rate) );
    call_id = glog->log_call_started( this, "wallet_account_update_registration", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_update_registration finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_account_update_registration(account_name, pay_from_account, public_data, delegate_pay_rate);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_update_registration", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_account_update_active_key(const std::string& account_to_update, const std::string& pay_from_account, const std::string& new_active_key /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_account_update_active_key(${account_to_update}, ${pay_from_account}, ${new_active_key})", ("account_to_update", account_to_update)("pay_from_account", pay_from_account)("new_active_key", new_active_key));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_to_update) );
    args.push_back( fc::variant(pay_from_account) );
    args.push_back( fc::variant(new_active_key) );
    call_id = glog->log_call_started( this, "wallet_account_update_active_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_update_active_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_account_update_active_key(account_to_update, pay_from_account, new_active_key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_update_active_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::wallet::WalletAccountEntry> CommonApiClient::wallet_list_accounts() const
{
  ilog("received RPC call: wallet_list_accounts()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::wallet::WalletAccountEntry> result = get_impl()->wallet_list_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::wallet::WalletAccountEntry> CommonApiClient::wallet_list_unregistered_accounts() const
{
  ilog("received RPC call: wallet_list_unregistered_accounts()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_unregistered_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_unregistered_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::wallet::WalletAccountEntry> result = get_impl()->wallet_list_unregistered_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_unregistered_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::wallet::WalletAccountEntry> CommonApiClient::wallet_list_my_accounts() const
{
  ilog("received RPC call: wallet_list_my_accounts()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_my_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_my_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::wallet::WalletAccountEntry> result = get_impl()->wallet_list_my_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_my_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::wallet::AccountAddressData> CommonApiClient::wallet_list_my_addresses() const
{
  ilog("received RPC call: wallet_list_my_addresses()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_my_addresses", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_my_addresses finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::wallet::AccountAddressData> result = get_impl()->wallet_list_my_addresses();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_my_addresses", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletAccountEntry CommonApiClient::wallet_get_account(const std::string& account_name) const
{
  ilog("received RPC call: wallet_get_account(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletAccountEntry result = get_impl()->wallet_get_account(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_account", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_get_account_public_address(const std::string& account_name) const
{
  ilog("received RPC call: wallet_get_account_public_address(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_account_public_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_account_public_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_get_account_public_address(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_account_public_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_remove_contact_account(const std::string& account_name)
{
  ilog("received RPC call: wallet_remove_contact_account(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_remove_contact_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_remove_contact_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_remove_contact_account(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_remove_contact_account", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_account_rename(const std::string& current_account_name, const std::string& new_account_name)
{
  ilog("received RPC call: wallet_account_rename(${current_account_name}, ${new_account_name})", ("current_account_name", current_account_name)("new_account_name", new_account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(current_account_name) );
    args.push_back( fc::variant(new_account_name) );
    call_id = glog->log_call_started( this, "wallet_account_rename", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_rename finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_account_rename(current_account_name, new_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_rename", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_asset_create(const std::string& symbol, const std::string& asset_name, const std::string& issuer_name, const std::string& description, const std::string& maximum_share_supply, uint64_t precision, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, bool is_market_issued /* = fc::json::from_string("false").as<bool>() */)
{
  ilog("received RPC call: wallet_asset_create(${symbol}, ${asset_name}, ${issuer_name}, ${description}, ${maximum_share_supply}, ${precision}, ${public_data}, ${is_market_issued})", ("symbol", symbol)("asset_name", asset_name)("issuer_name", issuer_name)("description", description)("maximum_share_supply", maximum_share_supply)("precision", precision)("public_data", public_data)("is_market_issued", is_market_issued));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(asset_name) );
    args.push_back( fc::variant(issuer_name) );
    args.push_back( fc::variant(description) );
    args.push_back( fc::variant(maximum_share_supply) );
    args.push_back( fc::variant(precision) );
    args.push_back( fc::variant(public_data) );
    args.push_back( fc::variant(is_market_issued) );
    call_id = glog->log_call_started( this, "wallet_asset_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_asset_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_asset_create(symbol, asset_name, issuer_name, description, maximum_share_supply, precision, public_data, is_market_issued);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_asset_create", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_asset_issue(const std::string& amount, const std::string& symbol, const std::string& to_account_name, const goopal::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<goopal::blockchain::Imessage>() */)
{
  ilog("received RPC call: wallet_asset_issue(${amount}, ${symbol}, ${to_account_name}, ${memo_message})", ("amount", amount)("symbol", symbol)("to_account_name", to_account_name)("memo_message", memo_message));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount) );
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(memo_message) );
    call_id = glog->log_call_started( this, "wallet_asset_issue", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_asset_issue finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_asset_issue(amount, symbol, to_account_name, memo_message);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_asset_issue", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_asset_issue_to_addresses(const std::string& symbol, const std::map<std::string, goopal::blockchain::ShareType>& addresses)
{
  ilog("received RPC call: wallet_asset_issue_to_addresses(${symbol}, ${addresses})", ("symbol", symbol)("addresses", addresses));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(addresses) );
    call_id = glog->log_call_started( this, "wallet_asset_issue_to_addresses", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_asset_issue_to_addresses finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_asset_issue_to_addresses(symbol, addresses);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_asset_issue_to_addresses", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::AccountBalanceSummaryType CommonApiClient::wallet_account_balance(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_balance(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::AccountBalanceSummaryType result = get_impl()->wallet_account_balance(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::AccountBalanceIdSummaryType CommonApiClient::wallet_account_balance_ids(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_balance_ids(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_balance_ids", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_balance_ids finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::AccountBalanceIdSummaryType result = get_impl()->wallet_account_balance_ids(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_balance_ids", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<goopal::wallet::PublicKeySummary> CommonApiClient::wallet_account_list_public_keys(const std::string& account_name)
{
  ilog("received RPC call: wallet_account_list_public_keys(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_list_public_keys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_list_public_keys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<goopal::wallet::PublicKeySummary> result = get_impl()->wallet_account_list_public_keys(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_list_public_keys", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_delegate_withdraw_pay(const std::string& delegate_name, const std::string& to_account_name, const std::string& amount_to_withdraw)
{
  ilog("received RPC call: wallet_delegate_withdraw_pay(${delegate_name}, ${to_account_name}, ${amount_to_withdraw})", ("delegate_name", delegate_name)("to_account_name", to_account_name)("amount_to_withdraw", amount_to_withdraw));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(amount_to_withdraw) );
    call_id = glog->log_call_started( this, "wallet_delegate_withdraw_pay", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_delegate_withdraw_pay finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_delegate_withdraw_pay(delegate_name, to_account_name, amount_to_withdraw);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_delegate_withdraw_pay", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::DelegatePaySalary CommonApiClient::wallet_delegate_pay_balance_query(const std::string& delegate_name)
{
  ilog("received RPC call: wallet_delegate_pay_balance_query(${delegate_name})", ("delegate_name", delegate_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    call_id = glog->log_call_started( this, "wallet_delegate_pay_balance_query", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_delegate_pay_balance_query finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::DelegatePaySalary result = get_impl()->wallet_delegate_pay_balance_query(delegate_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_delegate_pay_balance_query", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_get_delegate_statue(const std::string& account_name)
{
  ilog("received RPC call: wallet_get_delegate_statue(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_delegate_statue", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_delegate_statue finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_get_delegate_statue(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_delegate_statue", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_set_transaction_imessage_fee_coe(const std::string& fee_coe)
{
  ilog("received RPC call: wallet_set_transaction_imessage_fee_coe(${fee_coe})", ("fee_coe", fee_coe));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee_coe) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_imessage_fee_coe", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_imessage_fee_coe finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_set_transaction_imessage_fee_coe(fee_coe);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_imessage_fee_coe", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

double CommonApiClient::wallet_get_transaction_imessage_fee_coe()
{
  ilog("received RPC call: wallet_get_transaction_imessage_fee_coe()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_transaction_imessage_fee_coe", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction_imessage_fee_coe finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    double result = get_impl()->wallet_get_transaction_imessage_fee_coe();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction_imessage_fee_coe", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}
std::map<std::string,goopal::blockchain::DelegatePaySalary> CommonApiClient::wallet_active_delegate_salary()
{
  ilog("received RPC call: wallet_active_delegate_salary()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_active_delegate_salary", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_active_delegate_salary finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<std::string,goopal::blockchain::DelegatePaySalary> result = get_impl()->wallet_active_delegate_salary();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_active_delegate_salary", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}


void CommonApiClient::wallet_set_transaction_imessage_soft_max_length(int64_t soft_length)
{
  ilog("received RPC call: wallet_set_transaction_imessage_soft_max_length(${soft_length})", ("soft_length", soft_length));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(soft_length) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_imessage_soft_max_length", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_imessage_soft_max_length finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_set_transaction_imessage_soft_max_length(soft_length);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_imessage_soft_max_length", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int64_t CommonApiClient::wallet_get_transaction_imessage_soft_max_length()
{
  ilog("received RPC call: wallet_get_transaction_imessage_soft_max_length()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_transaction_imessage_soft_max_length", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction_imessage_soft_max_length finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int64_t result = get_impl()->wallet_get_transaction_imessage_soft_max_length();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction_imessage_soft_max_length", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::Asset CommonApiClient::wallet_set_transaction_fee(const std::string& fee)
{
  ilog("received RPC call: wallet_set_transaction_fee(${fee})", ("fee", fee));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_fee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_fee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::Asset result = get_impl()->wallet_set_transaction_fee(fee);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_fee", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::blockchain::Asset CommonApiClient::wallet_get_transaction_fee(const std::string& symbol /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_get_transaction_fee(${symbol})", ("symbol", symbol));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    call_id = glog->log_call_started( this, "wallet_get_transaction_fee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction_fee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::blockchain::Asset result = get_impl()->wallet_get_transaction_fee(symbol);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction_fee", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<std::string> CommonApiClient::wallet_dump_private_key(const std::string& input) const
{
  ilog("received RPC call: wallet_dump_private_key(${input})", ("input", input));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(input) );
    call_id = glog->log_call_started( this, "wallet_dump_private_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_dump_private_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<std::string> result = get_impl()->wallet_dump_private_key(input);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_dump_private_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<std::string> CommonApiClient::wallet_dump_account_private_key(const std::string& account_name, const goopal::wallet::AccountKeyType& key_type) const
{
  ilog("received RPC call: wallet_dump_account_private_key(${account_name}, ${key_type})", ("account_name", account_name)("key_type", key_type));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(key_type) );
    call_id = glog->log_call_started( this, "wallet_dump_account_private_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_dump_account_private_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<std::string> result = get_impl()->wallet_dump_account_private_key(account_name, key_type);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_dump_account_private_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::AccountVoteSummaryType CommonApiClient::wallet_account_vote_summary(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_vote_summary(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_vote_summary", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_vote_summary finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::AccountVoteSummaryType result = get_impl()->wallet_account_vote_summary(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_vote_summary", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::VoteSummary CommonApiClient::wallet_check_vote_status(const std::string& account)
{
  ilog("received RPC call: wallet_check_vote_status(${account})", ("account", account));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account) );
    call_id = glog->log_call_started( this, "wallet_check_vote_status", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_check_vote_status finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::VoteSummary result = get_impl()->wallet_check_vote_status(account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_check_vote_status", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_set_setting(const std::string& name, const fc::variant& value)
{
  ilog("received RPC call: wallet_set_setting(${name}, ${value})", ("name", name)("value", value));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(name) );
    args.push_back( fc::variant(value) );
    call_id = glog->log_call_started( this, "wallet_set_setting", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_setting finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_set_setting(name, value);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_setting", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<fc::variant> CommonApiClient::wallet_get_setting(const std::string& name)
{
  ilog("received RPC call: wallet_get_setting(${name})", ("name", name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(name) );
    call_id = glog->log_call_started( this, "wallet_get_setting", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_setting finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<fc::variant> result = get_impl()->wallet_get_setting(name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_setting", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_delegate_set_block_production(const std::string& delegate_name, bool enabled)
{
  ilog("received RPC call: wallet_delegate_set_block_production(${delegate_name}, ${enabled})", ("delegate_name", delegate_name)("enabled", enabled));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    args.push_back( fc::variant(enabled) );
    call_id = glog->log_call_started( this, "wallet_delegate_set_block_production", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_delegate_set_block_production finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_delegate_set_block_production(delegate_name, enabled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_delegate_set_block_production", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_set_transaction_scanning(bool enabled)
{
  ilog("received RPC call: wallet_set_transaction_scanning(${enabled})", ("enabled", enabled));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(enabled) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_scanning", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_scanning finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_set_transaction_scanning(enabled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_scanning", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::ecc::compact_signature CommonApiClient::wallet_sign_hash(const std::string& signer, const fc::sha256& hash)
{
  ilog("received RPC call: wallet_sign_hash(${signer}, ${hash})", ("signer", signer)("hash", hash));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(signer) );
    args.push_back( fc::variant(hash) );
    call_id = glog->log_call_started( this, "wallet_sign_hash", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_sign_hash finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::ecc::compact_signature result = get_impl()->wallet_sign_hash(signer, hash);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_sign_hash", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_login_start(const std::string& server_account)
{
  ilog("received RPC call: wallet_login_start(${server_account})", ("server_account", server_account));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(server_account) );
    call_id = glog->log_call_started( this, "wallet_login_start", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_login_start finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_login_start(server_account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_login_start", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant CommonApiClient::wallet_login_finish(const goopal::blockchain::PublicKeyType& server_key, const goopal::blockchain::PublicKeyType& client_key, const fc::ecc::compact_signature& client_signature)
{
  ilog("received RPC call: wallet_login_finish(${server_key}, ${client_key}, ${client_signature})", ("server_key", server_key)("client_key", client_key)("client_signature", client_signature));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(server_key) );
    args.push_back( fc::variant(client_key) );
    args.push_back( fc::variant(client_signature) );
    call_id = glog->log_call_started( this, "wallet_login_finish", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_login_finish finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant result = get_impl()->wallet_login_finish(server_key, client_key, client_signature);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_login_finish", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::TransactionBuilder CommonApiClient::wallet_balance_set_vote_info(const goopal::blockchain::Address& balance_id, const std::string& voter_address /* = fc::json::from_string("\"\"").as<std::string>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_all\"").as<goopal::wallet::VoteStrategy>() */, bool sign_and_broadcast /* = fc::json::from_string("\"true\"").as<bool>() */, const std::string& builder_path /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_balance_set_vote_info(${balance_id}, ${voter_address}, ${strategy}, ${sign_and_broadcast}, ${builder_path})", ("balance_id", balance_id)("voter_address", voter_address)("strategy", strategy)("sign_and_broadcast", sign_and_broadcast)("builder_path", builder_path));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(balance_id) );
    args.push_back( fc::variant(voter_address) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(sign_and_broadcast) );
    args.push_back( fc::variant(builder_path) );
    call_id = glog->log_call_started( this, "wallet_balance_set_vote_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_balance_set_vote_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::TransactionBuilder result = get_impl()->wallet_balance_set_vote_info(balance_id, voter_address, strategy, sign_and_broadcast, builder_path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_balance_set_vote_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_publish_slate(const std::string& publishing_account_name, const std::string& paying_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_publish_slate(${publishing_account_name}, ${paying_account_name})", ("publishing_account_name", publishing_account_name)("paying_account_name", paying_account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(publishing_account_name) );
    args.push_back( fc::variant(paying_account_name) );
    call_id = glog->log_call_started( this, "wallet_publish_slate", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_publish_slate finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_publish_slate(publishing_account_name, paying_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_publish_slate", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_publish_version(const std::string& publishing_account_name, const std::string& paying_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_publish_version(${publishing_account_name}, ${paying_account_name})", ("publishing_account_name", publishing_account_name)("paying_account_name", paying_account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(publishing_account_name) );
    args.push_back( fc::variant(paying_account_name) );
    call_id = glog->log_call_started( this, "wallet_publish_version", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_publish_version finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_publish_version(publishing_account_name, paying_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_publish_version", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_collect_genesis_balances(const std::string& account_name)
{
  ilog("received RPC call: wallet_collect_genesis_balances(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_collect_genesis_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_collect_genesis_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_collect_genesis_balances(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_collect_genesis_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int32_t CommonApiClient::wallet_recover_accounts(int32_t accounts_to_recover, int32_t maximum_number_of_attempts /* = fc::json::from_string("1000").as<int32_t>() */)
{
  ilog("received RPC call: wallet_recover_accounts(${accounts_to_recover}, ${maximum_number_of_attempts})", ("accounts_to_recover", accounts_to_recover)("maximum_number_of_attempts", maximum_number_of_attempts));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(accounts_to_recover) );
    args.push_back( fc::variant(maximum_number_of_attempts) );
    call_id = glog->log_call_started( this, "wallet_recover_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_recover_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int32_t result = get_impl()->wallet_recover_accounts(accounts_to_recover, maximum_number_of_attempts);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_recover_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<fc::variant_object> CommonApiClient::wallet_verify_titan_deposit(const std::string& transaction_id_prefix)
{
  ilog("received RPC call: wallet_verify_titan_deposit(${transaction_id_prefix})", ("transaction_id_prefix", transaction_id_prefix));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    call_id = glog->log_call_started( this, "wallet_verify_titan_deposit", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_verify_titan_deposit finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<fc::variant_object> result = get_impl()->wallet_verify_titan_deposit(transaction_id_prefix);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_verify_titan_deposit", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_repair_entrys(const std::string& collecting_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_repair_entrys(${collecting_account_name})", ("collecting_account_name", collecting_account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(collecting_account_name) );
    call_id = glog->log_call_started( this, "wallet_repair_entrys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_repair_entrys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_repair_entrys(collecting_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_repair_entrys", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int32_t CommonApiClient::wallet_regenerate_keys(const std::string& account_name, uint32_t max_key_number)
{
  ilog("received RPC call: wallet_regenerate_keys(${account_name}, ${max_key_number})", ("account_name", account_name)("max_key_number", max_key_number));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(max_key_number) );
    call_id = glog->log_call_started( this, "wallet_regenerate_keys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_regenerate_keys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int32_t result = get_impl()->wallet_regenerate_keys(account_name, max_key_number);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_regenerate_keys", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::wallet_account_retract(const std::string& account_to_retract, const std::string& pay_from_account)
{
  ilog("received RPC call: wallet_account_retract(${account_to_retract}, ${pay_from_account})", ("account_to_retract", account_to_retract)("pay_from_account", pay_from_account));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_to_retract) );
    args.push_back( fc::variant(pay_from_account) );
    call_id = glog->log_call_started( this, "wallet_account_retract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_retract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->wallet_account_retract(account_to_retract, pay_from_account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_retract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_account_delete(const std::string& account_name)
{
  ilog("received RPC call: wallet_account_delete(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_delete", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_delete finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_account_delete(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_delete", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_transfer_to_address_rpc(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_address, const goopal::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<goopal::blockchain::Imessage>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>() */)
{
  ilog("received RPC call: wallet_transfer_to_address_rpc(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_address}, ${memo_message}, ${strategy})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_address", to_address)("memo_message", memo_message)("strategy", strategy));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_address) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_address_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_address_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_transfer_to_address_rpc(amount_to_transfer, asset_symbol, from_account_name, to_address, memo_message, strategy);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_address_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_account_balance_rpc(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_balance_rpc(${account_name})", ("account_name", account_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_balance_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_balance_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_account_balance_rpc(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_balance_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_transfer_to_public_account_rpc(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_account_name, const goopal::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<goopal::blockchain::Imessage>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>() */)
{
  ilog("received RPC call: wallet_transfer_to_public_account_rpc(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_account_name}, ${memo_message}, ${strategy})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_account_name", to_account_name)("memo_message", memo_message)("strategy", strategy));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_public_account_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_public_account_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_transfer_to_public_account_rpc(amount_to_transfer, asset_symbol, from_account_name, to_account_name, memo_message, strategy);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_public_account_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::about() const
{
  ilog("received RPC call: about()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "about", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call about finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->about();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "about", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::get_info() const
{
  ilog("received RPC call: get_info()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::stop()
{
  ilog("received RPC call: stop()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "stop", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call stop finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->stop();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "stop", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::help(const std::string& command_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: help(${command_name})", ("command_name", command_name));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(command_name) );
    call_id = glog->log_call_started( this, "help", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call help finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->help(command_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "help", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::validate_address(const std::string& address) const
{
  ilog("received RPC call: validate_address(${address})", ("address", address));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(address) );
    call_id = glog->log_call_started( this, "validate_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call validate_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->validate_address(address);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "validate_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::execute_command_line(const std::string& input) const
{
  ilog("received RPC call: execute_command_line(*********)", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(input) );
    call_id = glog->log_call_started( this, "execute_command_line", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call execute_command_line finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->execute_command_line(input);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "execute_command_line", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::execute_script(const fc::path& script) const
{
  ilog("received RPC call: execute_script(${script})", ("script", script));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(script) );
    call_id = glog->log_call_started( this, "execute_script", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call execute_script finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->execute_script(script);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "execute_script", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variants CommonApiClient::batch(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const
{
  ilog("received RPC call: batch(${method_name}, ${parameters_list})", ("method_name", method_name)("parameters_list", parameters_list));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(method_name) );
    args.push_back( fc::variant(parameters_list) );
    call_id = glog->log_call_started( this, "batch", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call batch finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variants result = get_impl()->batch(method_name, parameters_list);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "batch", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variants CommonApiClient::batch_authenticated(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const
{
  ilog("received RPC call: batch_authenticated(${method_name}, ${parameters_list})", ("method_name", method_name)("parameters_list", parameters_list));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(method_name) );
    args.push_back( fc::variant(parameters_list) );
    call_id = glog->log_call_started( this, "batch_authenticated", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call batch_authenticated finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variants result = get_impl()->batch_authenticated(method_name, parameters_list);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "batch_authenticated", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

goopal::wallet::WalletTransactionEntry CommonApiClient::builder_finalize_and_sign(const goopal::wallet::TransactionBuilder& builder) const
{
  ilog("received RPC call: builder_finalize_and_sign(${builder})", ("builder", builder));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(builder) );
    call_id = glog->log_call_started( this, "builder_finalize_and_sign", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call builder_finalize_and_sign finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    goopal::wallet::WalletTransactionEntry result = get_impl()->builder_finalize_and_sign(builder);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "builder_finalize_and_sign", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<std::string, goopal::api::MethodData> CommonApiClient::meta_help() const
{
  ilog("received RPC call: meta_help()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "meta_help", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call meta_help finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<std::string, goopal::api::MethodData> result = get_impl()->meta_help();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "meta_help", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::rpc_set_username(const std::string& username /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: rpc_set_username(${username})", ("username", username));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(username) );
    call_id = glog->log_call_started( this, "rpc_set_username", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call rpc_set_username finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->rpc_set_username(username);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "rpc_set_username", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::rpc_set_password(const std::string& password /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: rpc_set_password(*********)", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(password) );
    call_id = glog->log_call_started( this, "rpc_set_password", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call rpc_set_password finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->rpc_set_password(password);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "rpc_set_password", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::rpc_start_server(uint32_t port /* = fc::json::from_string("\"65065\"").as<uint32_t>() */)
{
  ilog("received RPC call: rpc_start_server(${port})", ("port", port));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(port) );
    call_id = glog->log_call_started( this, "rpc_start_server", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call rpc_start_server finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->rpc_start_server(port);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "rpc_start_server", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::http_start_server(uint32_t port /* = fc::json::from_string("\"65066\"").as<uint32_t>() */)
{
  ilog("received RPC call: http_start_server(${port})", ("port", port));
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(port) );
    call_id = glog->log_call_started( this, "http_start_server", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call http_start_server finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->http_start_server(port);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "http_start_server", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::ntp_update_time()
{
  ilog("received RPC call: ntp_update_time()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "ntp_update_time", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call ntp_update_time finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->ntp_update_time();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "ntp_update_time", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant CommonApiClient::disk_usage() const
{
  ilog("received RPC call: disk_usage()", );
  goopal::api::GlobalApiLogger* glog = goopal::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "disk_usage", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call disk_usage finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant result = get_impl()->disk_usage();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "disk_usage", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

} } // end namespace goopal::rpc_stubs
