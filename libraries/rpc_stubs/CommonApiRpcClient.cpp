//                                   _           _    __ _ _      
//                                  | |         | |  / _(_) |     
//    __ _  ___ _ __   ___ _ __ __ _| |_ ___  __| | | |_ _| | ___ 
//   / _` |/ _ \ '_ \ / _ \ '__/ _` | __/ _ \/ _` | |  _| | |/ _ \`
//  | (_| |  __/ | | |  __/ | | (_| | ||  __/ (_| | | | | | |  __/
//   \__, |\___|_| |_|\___|_|  \__,_|\__\___|\__,_| |_| |_|_|\___|
//    __/ |                                                       
//   |___/                                                        
//
//
// Warning: this is a generated file, any changes made here will be
//          overwritten by the build process.  If you need to change what is
//          generated here, you should either modify the input json files
//          (network_api.json, wallet_api.json, etc) or modify the code
//          generator (goopal_api_generator.cpp) itself
//
#define DEFAULT_LOGGER "rpc"
#include <rpc_stubs/CommonApiRpcClient.hpp>
#include <api/ConversionFunctions.hpp>

namespace goopal { namespace rpc_stubs {

fc::variant_object CommonApiRpcClient::blockchain_get_info() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_info", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant_object>();
}
void CommonApiRpcClient::blockchain_generate_snapshot(const std::string& filename) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_generate_snapshot", std::vector<fc::variant>{fc::variant(filename)}).wait();
}
std::vector<goopal::blockchain::GopTrxidBalance> CommonApiRpcClient::blockchain_get_gop_account_balance_entry(uint32_t block_num)
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_gop_account_balance_entry", std::vector<fc::variant>{fc::variant(block_num)}).wait();
  return result.as<std::vector<goopal::blockchain::GopTrxidBalance>>();
}
void CommonApiRpcClient::blockchain_generate_issuance_map(const std::string& symbol, const std::string& filename) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_generate_issuance_map", std::vector<fc::variant>{fc::variant(symbol), fc::variant(filename)}).wait();
}
goopal::blockchain::Asset CommonApiRpcClient::blockchain_calculate_supply(const std::string& asset) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_calculate_supply", std::vector<fc::variant>{fc::variant(asset)}).wait();
  return result.as<goopal::blockchain::Asset>();
}
bool CommonApiRpcClient::blockchain_is_synced() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_is_synced", std::vector<fc::variant>{}).wait();
  return result.as<bool>();
}
uint32_t CommonApiRpcClient::blockchain_get_block_count() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_block_count", std::vector<fc::variant>{}).wait();
  return result.as<uint32_t>();
}
goopal::blockchain::BlockchainSecurityState CommonApiRpcClient::blockchain_get_security_state() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_security_state", std::vector<fc::variant>{}).wait();
  return result.as<goopal::blockchain::BlockchainSecurityState>();
}
std::vector<goopal::blockchain::AccountEntry> CommonApiRpcClient::blockchain_list_accounts(const std::string& first_account_name /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_accounts", std::vector<fc::variant>{fc::variant(first_account_name), fc::variant(limit)}).wait();
  return result.as<std::vector<goopal::blockchain::AccountEntry>>();
}
std::vector<goopal::blockchain::AccountEntry> CommonApiRpcClient::blockchain_list_recently_updated_accounts() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_recently_updated_accounts", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<goopal::blockchain::AccountEntry>>();
}
std::vector<goopal::blockchain::AccountEntry> CommonApiRpcClient::blockchain_list_recently_registered_accounts() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_recently_registered_accounts", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<goopal::blockchain::AccountEntry>>();
}
std::vector<goopal::blockchain::AssetEntry> CommonApiRpcClient::blockchain_list_assets(const std::string& first_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_assets", std::vector<fc::variant>{fc::variant(first_symbol), fc::variant(limit)}).wait();
  return result.as<std::vector<goopal::blockchain::AssetEntry>>();
}
std::vector<goopal::blockchain::SignedTransaction> CommonApiRpcClient::blockchain_list_pending_transactions() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_pending_transactions", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<goopal::blockchain::SignedTransaction>>();
}
std::pair<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> CommonApiRpcClient::blockchain_get_transaction(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_transaction", std::vector<fc::variant>{fc::variant(transaction_id_prefix), fc::variant(exact)}).wait();
  return result.as<std::pair<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry>>();
}
fc::optional<goopal::blockchain::BlockEntry> CommonApiRpcClient::blockchain_get_block(const std::string& block) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_block", std::vector<fc::variant>{fc::variant(block)}).wait();
  return result.as<fc::optional<goopal::blockchain::BlockEntry>>();
}
std::map<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> CommonApiRpcClient::blockchain_get_block_transactions(const std::string& block) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_block_transactions", std::vector<fc::variant>{fc::variant(block)}).wait();
  return result.as<std::map<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry>>();
}
fc::optional<goopal::blockchain::AccountEntry> CommonApiRpcClient::blockchain_get_account(const std::string& account) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_account", std::vector<fc::variant>{fc::variant(account)}).wait();
  return result.as<fc::optional<goopal::blockchain::AccountEntry>>();
}
std::map<goopal::blockchain::AccountIdType, std::string> CommonApiRpcClient::blockchain_get_slate(const std::string& slate) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_slate", std::vector<fc::variant>{fc::variant(slate)}).wait();
  return result.as<std::map<goopal::blockchain::AccountIdType, std::string>>();
}
goopal::blockchain::BalanceEntry CommonApiRpcClient::blockchain_get_balance(const goopal::blockchain::Address& balance_id) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_balance", std::vector<fc::variant>{fc::variant(balance_id)}).wait();
  return result.as<goopal::blockchain::BalanceEntry>();
}
std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> CommonApiRpcClient::blockchain_list_balances(const std::string& first_balance_id /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_balances", std::vector<fc::variant>{fc::variant(first_balance_id), fc::variant(limit)}).wait();
  return result.as<std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry>>();
}
std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> CommonApiRpcClient::blockchain_list_address_balances(const std::string& addr, const fc::time_point& chanced_since /* = fc::json::from_string("\"1970-1-1T00:00:01\"").as<fc::time_point>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_address_balances", std::vector<fc::variant>{fc::variant(addr), fc::variant(chanced_since)}).wait();
  return result.as<std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry>>();
}
fc::variant_object CommonApiRpcClient::blockchain_list_address_transactions(const std::string& addr, uint32_t filter_before /* = fc::json::from_string("\"0\"").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_address_transactions", std::vector<fc::variant>{fc::variant(addr), fc::variant(filter_before)}).wait();
  return result.as<fc::variant_object>();
}
goopal::wallet::AccountBalanceSummaryType CommonApiRpcClient::blockchain_get_account_public_balance(const std::string& account_name) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_account_public_balance", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<goopal::wallet::AccountBalanceSummaryType>();
}
std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> CommonApiRpcClient::blockchain_list_key_balances(const goopal::blockchain::PublicKeyType& key) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_key_balances", std::vector<fc::variant>{fc::variant(key)}).wait();
  return result.as<std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry>>();
}
fc::optional<goopal::blockchain::AssetEntry> CommonApiRpcClient::blockchain_get_asset(const std::string& asset) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_asset", std::vector<fc::variant>{fc::variant(asset)}).wait();
  return result.as<fc::optional<goopal::blockchain::AssetEntry>>();
}
std::vector<goopal::blockchain::AccountEntry> CommonApiRpcClient::blockchain_list_active_delegates(uint32_t first /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t count /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_active_delegates", std::vector<fc::variant>{fc::variant(first), fc::variant(count)}).wait();
  return result.as<std::vector<goopal::blockchain::AccountEntry>>();
}
std::vector<goopal::blockchain::AccountEntry> CommonApiRpcClient::blockchain_list_delegates(uint32_t first /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t count /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_delegates", std::vector<fc::variant>{fc::variant(first), fc::variant(count)}).wait();
  return result.as<std::vector<goopal::blockchain::AccountEntry>>();
}
std::vector<goopal::blockchain::BlockEntry> CommonApiRpcClient::blockchain_list_blocks(uint32_t max_block_num /* = fc::json::from_string("-1").as<uint32_t>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */)
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_blocks", std::vector<fc::variant>{fc::variant(max_block_num), fc::variant(limit)}).wait();
  return result.as<std::vector<goopal::blockchain::BlockEntry>>();
}
std::vector<std::string> CommonApiRpcClient::blockchain_list_missing_block_delegates(uint32_t block_number)
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_missing_block_delegates", std::vector<fc::variant>{fc::variant(block_number)}).wait();
  return result.as<std::vector<std::string>>();
}
std::string CommonApiRpcClient::blockchain_export_fork_graph(uint32_t start_block /* = fc::json::from_string("1").as<uint32_t>() */, uint32_t end_block /* = fc::json::from_string("-1").as<uint32_t>() */, const std::string& filename /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_export_fork_graph", std::vector<fc::variant>{fc::variant(start_block), fc::variant(end_block), fc::variant(filename)}).wait();
  return result.as<std::string>();
}
std::map<uint32_t, std::vector<goopal::blockchain::ForkEntry>> CommonApiRpcClient::blockchain_list_forks() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_list_forks", std::vector<fc::variant>{}).wait();
  return result.as<std::map<uint32_t, std::vector<goopal::blockchain::ForkEntry>>>();
}
std::vector<goopal::blockchain::SlotEntry> CommonApiRpcClient::blockchain_get_delegate_slot_entrys(const std::string& delegate_name, uint32_t limit /* = fc::json::from_string("\"10\"").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_delegate_slot_entrys", std::vector<fc::variant>{fc::variant(delegate_name), fc::variant(limit)}).wait();
  return result.as<std::vector<goopal::blockchain::SlotEntry>>();
}
std::string CommonApiRpcClient::blockchain_get_block_signee(const std::string& block) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_get_block_signee", std::vector<fc::variant>{fc::variant(block)}).wait();
  return result.as<std::string>();
}
goopal::blockchain::Asset CommonApiRpcClient::blockchain_unclaimed_genesis() const
{
  fc::variant result = get_json_connection()->async_call("blockchain_unclaimed_genesis", std::vector<fc::variant>{}).wait();
  return result.as<goopal::blockchain::Asset>();
}
bool CommonApiRpcClient::blockchain_verify_signature(const std::string& signer, const fc::sha256& hash, const fc::ecc::compact_signature& signature) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_verify_signature", std::vector<fc::variant>{fc::variant(signer), fc::variant(hash), fc::variant(signature)}).wait();
  return result.as<bool>();
}
void CommonApiRpcClient::blockchain_dump_state(const std::string& path) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_dump_state", std::vector<fc::variant>{fc::variant(path)}).wait();
}
void CommonApiRpcClient::blockchain_broadcast_transaction(const goopal::blockchain::SignedTransaction& trx)
{
  fc::variant result = get_json_connection()->async_call("blockchain_broadcast_transaction", std::vector<fc::variant>{fc::variant(trx)}).wait();
}
void CommonApiRpcClient::blockchain_btc_address_convert(const std::string& path) const
{
  fc::variant result = get_json_connection()->async_call("blockchain_btc_address_convert", std::vector<fc::variant>{fc::variant(path)}).wait();
}
void CommonApiRpcClient::network_add_node(const std::string& node, const std::string& command /* = fc::json::from_string("\"add\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("network_add_node", std::vector<fc::variant>{fc::variant(node), fc::variant(command)}).wait();
}
uint32_t CommonApiRpcClient::network_get_connection_count() const
{
  fc::variant result = get_json_connection()->async_call("network_get_connection_count", std::vector<fc::variant>{}).wait();
  return result.as<uint32_t>();
}
std::vector<fc::variant_object> CommonApiRpcClient::network_get_peer_info(bool not_firewalled /* = fc::json::from_string("false").as<bool>() */) const
{
  fc::variant result = get_json_connection()->async_call("network_get_peer_info", std::vector<fc::variant>{fc::variant(not_firewalled)}).wait();
  return result.as<std::vector<fc::variant_object>>();
}
goopal::blockchain::TransactionIdType CommonApiRpcClient::network_broadcast_transaction(const goopal::blockchain::SignedTransaction& transaction_to_broadcast)
{
  fc::variant result = get_json_connection()->async_call("network_broadcast_transaction", std::vector<fc::variant>{fc::variant(transaction_to_broadcast)}).wait();
  return result.as<goopal::blockchain::TransactionIdType>();
}
void CommonApiRpcClient::network_set_advanced_node_parameters(const fc::variant_object& params)
{
  fc::variant result = get_json_connection()->async_call("network_set_advanced_node_parameters", std::vector<fc::variant>{fc::variant(params)}).wait();
}
fc::variant_object CommonApiRpcClient::network_get_advanced_node_parameters() const
{
  fc::variant result = get_json_connection()->async_call("network_get_advanced_node_parameters", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant_object>();
}
goopal::net::MessagePropagationData CommonApiRpcClient::network_get_transaction_propagation_data(const goopal::blockchain::TransactionIdType& transaction_id)
{
  fc::variant result = get_json_connection()->async_call("network_get_transaction_propagation_data", std::vector<fc::variant>{fc::variant(transaction_id)}).wait();
  return result.as<goopal::net::MessagePropagationData>();
}
goopal::net::MessagePropagationData CommonApiRpcClient::network_get_block_propagation_data(const goopal::blockchain::BlockIdType& block_hash)
{
  fc::variant result = get_json_connection()->async_call("network_get_block_propagation_data", std::vector<fc::variant>{fc::variant(block_hash)}).wait();
  return result.as<goopal::net::MessagePropagationData>();
}
fc::variant_object CommonApiRpcClient::network_get_info() const
{
  fc::variant result = get_json_connection()->async_call("network_get_info", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant_object>();
}
std::vector<goopal::net::PotentialPeerEntry> CommonApiRpcClient::network_list_potential_peers() const
{
  fc::variant result = get_json_connection()->async_call("network_list_potential_peers", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<goopal::net::PotentialPeerEntry>>();
}
fc::variant_object CommonApiRpcClient::network_get_upnp_info() const
{
  fc::variant result = get_json_connection()->async_call("network_get_upnp_info", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant_object>();
}
std::string CommonApiRpcClient::debug_get_client_name() const
{
  fc::variant result = get_json_connection()->async_call("debug_get_client_name", std::vector<fc::variant>{}).wait();
  return result.as<std::string>();
}
fc::variant CommonApiRpcClient::delegate_get_config() const
{
  fc::variant result = get_json_connection()->async_call("delegate_get_config", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant>();
}
void CommonApiRpcClient::delegate_set_network_min_connection_count(uint32_t count)
{
  fc::variant result = get_json_connection()->async_call("delegate_set_network_min_connection_count", std::vector<fc::variant>{fc::variant(count)}).wait();
}
void CommonApiRpcClient::delegate_set_block_max_transaction_count(uint32_t count)
{
  fc::variant result = get_json_connection()->async_call("delegate_set_block_max_transaction_count", std::vector<fc::variant>{fc::variant(count)}).wait();
}
void CommonApiRpcClient::delegate_set_block_max_size(uint32_t size)
{
  fc::variant result = get_json_connection()->async_call("delegate_set_block_max_size", std::vector<fc::variant>{fc::variant(size)}).wait();
}
void CommonApiRpcClient::delegate_set_transaction_max_size(uint32_t size)
{
  fc::variant result = get_json_connection()->async_call("delegate_set_transaction_max_size", std::vector<fc::variant>{fc::variant(size)}).wait();
}
void CommonApiRpcClient::delegate_set_transaction_canonical_signatures_required(bool required)
{
  fc::variant result = get_json_connection()->async_call("delegate_set_transaction_canonical_signatures_required", std::vector<fc::variant>{fc::variant(required)}).wait();
}
void CommonApiRpcClient::delegate_set_transaction_min_fee(uint64_t fee)
{
  fc::variant result = get_json_connection()->async_call("delegate_set_transaction_min_fee", std::vector<fc::variant>{fc::variant(fee)}).wait();
}
void CommonApiRpcClient::delegate_blacklist_add_transaction(const goopal::blockchain::TransactionIdType& id)
{
  fc::variant result = get_json_connection()->async_call("delegate_blacklist_add_transaction", std::vector<fc::variant>{fc::variant(id)}).wait();
}
void CommonApiRpcClient::delegate_blacklist_remove_transaction(const goopal::blockchain::TransactionIdType& id)
{
  fc::variant result = get_json_connection()->async_call("delegate_blacklist_remove_transaction", std::vector<fc::variant>{fc::variant(id)}).wait();
}
void CommonApiRpcClient::delegate_blacklist_add_operation(const goopal::blockchain::OperationTypeEnum& id)
{
  fc::variant result = get_json_connection()->async_call("delegate_blacklist_add_operation", std::vector<fc::variant>{fc::variant(id)}).wait();
}
void CommonApiRpcClient::delegate_blacklist_remove_operation(const goopal::blockchain::OperationTypeEnum& id)
{
  fc::variant result = get_json_connection()->async_call("delegate_blacklist_remove_operation", std::vector<fc::variant>{fc::variant(id)}).wait();
}
fc::variant_object CommonApiRpcClient::wallet_get_info()
{
  fc::variant result = get_json_connection()->async_call("wallet_get_info", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant_object>();
}
void CommonApiRpcClient::wallet_open(const std::string& wallet_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_open", std::vector<fc::variant>{fc::variant(wallet_name)}).wait();
}
void CommonApiRpcClient::wallet_create(const std::string& wallet_name, const std::string& new_passphrase, const std::string& brain_key /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_create", std::vector<fc::variant>{fc::variant(wallet_name), fc::variant(new_passphrase), fc::variant(brain_key)}).wait();
}
fc::optional<std::string> CommonApiRpcClient::wallet_get_name() const
{
  fc::variant result = get_json_connection()->async_call("wallet_get_name", std::vector<fc::variant>{}).wait();
  return result.as<fc::optional<std::string>>();
}
std::string CommonApiRpcClient::wallet_import_private_key(const std::string& wif_key, const std::string& account_name /* = fc::json::from_string("null").as<std::string>() */, bool create_new_account /* = fc::json::from_string("false").as<bool>() */, bool rescan /* = fc::json::from_string("false").as<bool>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_import_private_key", std::vector<fc::variant>{fc::variant(wif_key), fc::variant(account_name), fc::variant(create_new_account), fc::variant(rescan)}).wait();
  return result.as<std::string>();
}
void CommonApiRpcClient::wallet_close()
{
  fc::variant result = get_json_connection()->async_call("wallet_close", std::vector<fc::variant>{}).wait();
}
void CommonApiRpcClient::wallet_backup_create(const fc::path& json_filename) const
{
  fc::variant result = get_json_connection()->async_call("wallet_backup_create", std::vector<fc::variant>{fc::variant(json_filename)}).wait();
}
void CommonApiRpcClient::wallet_backup_restore(const fc::path& json_filename, const std::string& wallet_name, const std::string& imported_wallet_passphrase)
{
  fc::variant result = get_json_connection()->async_call("wallet_backup_restore", std::vector<fc::variant>{fc::variant(json_filename), fc::variant(wallet_name), fc::variant(imported_wallet_passphrase)}).wait();
}
bool CommonApiRpcClient::wallet_set_automatic_backups(bool enabled)
{
  fc::variant result = get_json_connection()->async_call("wallet_set_automatic_backups", std::vector<fc::variant>{fc::variant(enabled)}).wait();
  return result.as<bool>();
}
uint32_t CommonApiRpcClient::wallet_set_transaction_expiration_time(uint32_t seconds)
{
  fc::variant result = get_json_connection()->async_call("wallet_set_transaction_expiration_time", std::vector<fc::variant>{fc::variant(seconds)}).wait();
  return result.as<uint32_t>();
}
std::vector<goopal::wallet::PrettyTransaction> CommonApiRpcClient::wallet_account_transaction_history(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */, const std::string& asset_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t limit /* = fc::json::from_string("0").as<int32_t>() */, uint32_t start_block_num /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t end_block_num /* = fc::json::from_string("-1").as<uint32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("wallet_account_transaction_history", std::vector<fc::variant>{fc::variant(account_name), fc::variant(asset_symbol), fc::variant(limit), fc::variant(start_block_num), fc::variant(end_block_num)}).wait();
  return result.as<std::vector<goopal::wallet::PrettyTransaction>>();
}
std::vector<goopal::wallet::PrettyTransaction> CommonApiRpcClient::wallet_transaction_history_splite(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */, const std::string& asset_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t limit /* = fc::json::from_string("0").as<int32_t>() */, int32_t transaction_type /* = fc::json::from_string("\"2\"").as<int32_t>() */) const
{
  fc::variant result = get_json_connection()->async_call("wallet_transaction_history_splite", std::vector<fc::variant>{fc::variant(account_name), fc::variant(asset_symbol), fc::variant(limit), fc::variant(transaction_type)}).wait();
  return result.as<std::vector<goopal::wallet::PrettyTransaction>>();
}
goopal::wallet::AccountBalanceSummaryType CommonApiRpcClient::wallet_account_historic_balance(const fc::time_point& time, const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  fc::variant result = get_json_connection()->async_call("wallet_account_historic_balance", std::vector<fc::variant>{fc::variant(time), fc::variant(account_name)}).wait();
  return result.as<goopal::wallet::AccountBalanceSummaryType>();
}
void CommonApiRpcClient::wallet_remove_transaction(const std::string& transaction_id)
{
  fc::variant result = get_json_connection()->async_call("wallet_remove_transaction", std::vector<fc::variant>{fc::variant(transaction_id)}).wait();
}
std::map<goopal::blockchain::TransactionIdType, fc::exception> CommonApiRpcClient::wallet_get_pending_transaction_errors(const std::string& filename /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  fc::variant result = get_json_connection()->async_call("wallet_get_pending_transaction_errors", std::vector<fc::variant>{fc::variant(filename)}).wait();
  return result.as<std::map<goopal::blockchain::TransactionIdType, fc::exception>>();
}
void CommonApiRpcClient::wallet_lock()
{
  fc::variant result = get_json_connection()->async_call("wallet_lock", std::vector<fc::variant>{}).wait();
}
void CommonApiRpcClient::wallet_unlock(uint32_t timeout, const std::string& passphrase)
{
  fc::variant result = get_json_connection()->async_call("wallet_unlock", std::vector<fc::variant>{fc::variant(timeout), fc::variant(passphrase)}).wait();
}
void CommonApiRpcClient::wallet_change_passphrase(const std::string& old_passphrase, const std::string& passphrase)
{
  fc::variant result = get_json_connection()->async_call("wallet_change_passphrase", std::vector<fc::variant>{fc::variant(old_passphrase), fc::variant(passphrase)}).wait();
}
bool CommonApiRpcClient::wallet_check_passphrase(const std::string& passphrase)
{
  fc::variant result = get_json_connection()->async_call("wallet_check_passphrase", std::vector<fc::variant>{fc::variant(passphrase)}).wait();
  return result.as<bool>();
}
bool CommonApiRpcClient::wallet_check_address(const std::string& address)
{
  fc::variant result = get_json_connection()->async_call("wallet_check_address", std::vector<fc::variant>{fc::variant(address)}).wait();
  return result.as<bool>();
}
std::vector<std::string> CommonApiRpcClient::wallet_list() const
{
  fc::variant result = get_json_connection()->async_call("wallet_list", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<std::string>>();
}
goopal::blockchain::PublicKeyType CommonApiRpcClient::wallet_account_create(const std::string& account_name, const fc::variant& private_data /* = fc::json::from_string("null").as<fc::variant>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_create", std::vector<fc::variant>{fc::variant(account_name), fc::variant(private_data)}).wait();
  return result.as<goopal::blockchain::PublicKeyType>();
}
int8_t CommonApiRpcClient::wallet_account_set_approval(const std::string& account_name, int8_t approval /* = fc::json::from_string("1").as<int8_t>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_set_approval", std::vector<fc::variant>{fc::variant(account_name), fc::variant(approval)}).wait();
  return result.as<int8_t>();
}
std::string CommonApiRpcClient::wallet_address_create(const std::string& account_name, const std::string& label /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t legacy_network_byte /* = fc::json::from_string("-1").as<int32_t>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_address_create", std::vector<fc::variant>{fc::variant(account_name), fc::variant(label), fc::variant(legacy_network_byte)}).wait();
  return result.as<std::string>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_transfer_to_address(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_address, const std::string& memo_message /* = fc::json::from_string("\"\"").as<std::string>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_transfer_to_address", std::vector<fc::variant>{fc::variant(amount_to_transfer), fc::variant(asset_symbol), fc::variant(from_account_name), fc::variant(to_address), fc::variant(memo_message), fc::variant(strategy)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_transfer_to_public_account(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_account_name, const std::string& memo_message /* = fc::json::from_string("\"\"").as<std::string>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_transfer_to_public_account", std::vector<fc::variant>{fc::variant(amount_to_transfer), fc::variant(asset_symbol), fc::variant(from_account_name), fc::variant(to_account_name), fc::variant(memo_message), fc::variant(strategy)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::TransactionBuilder CommonApiRpcClient::wallet_withdraw_from_address(const std::string& amount, const std::string& symbol, const goopal::blockchain::Address& from_address, const std::string& to, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_none\"").as<goopal::wallet::VoteStrategy>() */, bool sign_and_broadcast /* = fc::json::from_string("true").as<bool>() */, const std::string& builder_path /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_withdraw_from_address", std::vector<fc::variant>{fc::variant(amount), fc::variant(symbol), fc::variant(from_address), fc::variant(to), fc::variant(strategy), fc::variant(sign_and_broadcast), fc::variant(builder_path)}).wait();
  return result.as<goopal::wallet::TransactionBuilder>();
}
void CommonApiRpcClient::wallet_rescan_blockchain(uint32_t start_block_num /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t limit /* = fc::json::from_string("-1").as<uint32_t>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_rescan_blockchain", std::vector<fc::variant>{fc::variant(start_block_num), fc::variant(limit)}).wait();
}
void CommonApiRpcClient::wallet_cancel_scan()
{
  fc::variant result = get_json_connection()->async_call("wallet_cancel_scan", std::vector<fc::variant>{}).wait();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_get_transaction(const std::string& transaction_id)
{
  fc::variant result = get_json_connection()->async_call("wallet_get_transaction", std::vector<fc::variant>{fc::variant(transaction_id)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_scan_transaction(const std::string& transaction_id, bool overwrite_existing /* = fc::json::from_string("false").as<bool>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_scan_transaction", std::vector<fc::variant>{fc::variant(transaction_id), fc::variant(overwrite_existing)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
void CommonApiRpcClient::wallet_rebroadcast_transaction(const std::string& transaction_id)
{
  fc::variant result = get_json_connection()->async_call("wallet_rebroadcast_transaction", std::vector<fc::variant>{fc::variant(transaction_id)}).wait();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_account_register(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, uint8_t delegate_pay_rate /* = fc::json::from_string("-1").as<uint8_t>() */, const std::string& account_type /* = fc::json::from_string("\"titan_account\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_register", std::vector<fc::variant>{fc::variant(account_name), fc::variant(pay_from_account), fc::variant(public_data), fc::variant(delegate_pay_rate), fc::variant(account_type)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
void CommonApiRpcClient::wallet_account_update_private_data(const std::string& account_name, const fc::variant& private_data /* = fc::json::from_string("null").as<fc::variant>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_update_private_data", std::vector<fc::variant>{fc::variant(account_name), fc::variant(private_data)}).wait();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_account_update_registration(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, uint8_t delegate_pay_rate /* = fc::json::from_string("-1").as<uint8_t>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_update_registration", std::vector<fc::variant>{fc::variant(account_name), fc::variant(pay_from_account), fc::variant(public_data), fc::variant(delegate_pay_rate)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_account_update_active_key(const std::string& account_to_update, const std::string& pay_from_account, const std::string& new_active_key /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_update_active_key", std::vector<fc::variant>{fc::variant(account_to_update), fc::variant(pay_from_account), fc::variant(new_active_key)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
std::vector<goopal::wallet::WalletAccountEntry> CommonApiRpcClient::wallet_list_accounts() const
{
  fc::variant result = get_json_connection()->async_call("wallet_list_accounts", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<goopal::wallet::WalletAccountEntry>>();
}
std::vector<goopal::wallet::WalletAccountEntry> CommonApiRpcClient::wallet_list_unregistered_accounts() const
{
  fc::variant result = get_json_connection()->async_call("wallet_list_unregistered_accounts", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<goopal::wallet::WalletAccountEntry>>();
}
std::vector<goopal::wallet::WalletAccountEntry> CommonApiRpcClient::wallet_list_my_accounts() const
{
  fc::variant result = get_json_connection()->async_call("wallet_list_my_accounts", std::vector<fc::variant>{}).wait();
  return result.as<std::vector<goopal::wallet::WalletAccountEntry>>();
}
goopal::wallet::WalletAccountEntry CommonApiRpcClient::wallet_get_account(const std::string& account_name) const
{
  fc::variant result = get_json_connection()->async_call("wallet_get_account", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<goopal::wallet::WalletAccountEntry>();
}
std::string CommonApiRpcClient::wallet_get_account_public_address(const std::string& account_name) const
{
  fc::variant result = get_json_connection()->async_call("wallet_get_account_public_address", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<std::string>();
}
void CommonApiRpcClient::wallet_remove_contact_account(const std::string& account_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_remove_contact_account", std::vector<fc::variant>{fc::variant(account_name)}).wait();
}
void CommonApiRpcClient::wallet_account_rename(const std::string& current_account_name, const std::string& new_account_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_rename", std::vector<fc::variant>{fc::variant(current_account_name), fc::variant(new_account_name)}).wait();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_asset_create(const std::string& symbol, const std::string& asset_name, const std::string& issuer_name, const std::string& description, double maximum_share_supply, uint64_t precision, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, bool is_market_issued /* = fc::json::from_string("false").as<bool>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_asset_create", std::vector<fc::variant>{fc::variant(symbol), fc::variant(asset_name), fc::variant(issuer_name), fc::variant(description), fc::variant(maximum_share_supply), fc::variant(precision), fc::variant(public_data), fc::variant(is_market_issued)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_asset_issue(double amount, const std::string& symbol, const std::string& to_account_name, const std::string& memo_message /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_asset_issue", std::vector<fc::variant>{fc::variant(amount), fc::variant(symbol), fc::variant(to_account_name), fc::variant(memo_message)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_asset_issue_to_addresses(const std::string& symbol, const std::map<std::string, goopal::blockchain::ShareType>& addresses)
{
  fc::variant result = get_json_connection()->async_call("wallet_asset_issue_to_addresses", std::vector<fc::variant>{fc::variant(symbol), fc::variant(addresses)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::AccountBalanceSummaryType CommonApiRpcClient::wallet_account_balance(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  fc::variant result = get_json_connection()->async_call("wallet_account_balance", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<goopal::wallet::AccountBalanceSummaryType>();
}
goopal::wallet::AccountBalanceIdSummaryType CommonApiRpcClient::wallet_account_balance_ids(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  fc::variant result = get_json_connection()->async_call("wallet_account_balance_ids", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<goopal::wallet::AccountBalanceIdSummaryType>();
}
std::vector<goopal::wallet::PublicKeySummary> CommonApiRpcClient::wallet_account_list_public_keys(const std::string& account_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_list_public_keys", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<std::vector<goopal::wallet::PublicKeySummary>>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_delegate_withdraw_pay(const std::string& delegate_name, const std::string& to_account_name, double amount_to_withdraw)
{
  fc::variant result = get_json_connection()->async_call("wallet_delegate_withdraw_pay", std::vector<fc::variant>{fc::variant(delegate_name), fc::variant(to_account_name), fc::variant(amount_to_withdraw)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
int64_t CommonApiRpcClient::wallet_delegate_pay_balance_query(const std::string& delegate_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_delegate_pay_balance_query", std::vector<fc::variant>{fc::variant(delegate_name)}).wait();
  return result.as<int64_t>();
}
bool CommonApiRpcClient::wallet_get_delegate_statue(const std::string& account_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_get_delegate_statue", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<bool>();
}
goopal::blockchain::Asset CommonApiRpcClient::wallet_set_transaction_fee(double fee)
{
  fc::variant result = get_json_connection()->async_call("wallet_set_transaction_fee", std::vector<fc::variant>{fc::variant(fee)}).wait();
  return result.as<goopal::blockchain::Asset>();
}
goopal::blockchain::Asset CommonApiRpcClient::wallet_get_transaction_fee(const std::string& symbol /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_get_transaction_fee", std::vector<fc::variant>{fc::variant(symbol)}).wait();
  return result.as<goopal::blockchain::Asset>();
}
fc::optional<std::string> CommonApiRpcClient::wallet_dump_private_key(const std::string& input) const
{
  fc::variant result = get_json_connection()->async_call("wallet_dump_private_key", std::vector<fc::variant>{fc::variant(input)}).wait();
  return result.as<fc::optional<std::string>>();
}
fc::optional<std::string> CommonApiRpcClient::wallet_dump_account_private_key(const std::string& account_name, const goopal::wallet::AccountKeyType& key_type) const
{
  fc::variant result = get_json_connection()->async_call("wallet_dump_account_private_key", std::vector<fc::variant>{fc::variant(account_name), fc::variant(key_type)}).wait();
  return result.as<fc::optional<std::string>>();
}
goopal::wallet::AccountVoteSummaryType CommonApiRpcClient::wallet_account_vote_summary(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  fc::variant result = get_json_connection()->async_call("wallet_account_vote_summary", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<goopal::wallet::AccountVoteSummaryType>();
}
goopal::wallet::VoteSummary CommonApiRpcClient::wallet_check_vote_status(const std::string& account)
{
  fc::variant result = get_json_connection()->async_call("wallet_check_vote_status", std::vector<fc::variant>{fc::variant(account)}).wait();
  return result.as<goopal::wallet::VoteSummary>();
}
void CommonApiRpcClient::wallet_set_setting(const std::string& name, const fc::variant& value)
{
  fc::variant result = get_json_connection()->async_call("wallet_set_setting", std::vector<fc::variant>{fc::variant(name), fc::variant(value)}).wait();
}
fc::optional<fc::variant> CommonApiRpcClient::wallet_get_setting(const std::string& name)
{
  fc::variant result = get_json_connection()->async_call("wallet_get_setting", std::vector<fc::variant>{fc::variant(name)}).wait();
  return result.as<fc::optional<fc::variant>>();
}
void CommonApiRpcClient::wallet_delegate_set_block_production(const std::string& delegate_name, bool enabled)
{
  fc::variant result = get_json_connection()->async_call("wallet_delegate_set_block_production", std::vector<fc::variant>{fc::variant(delegate_name), fc::variant(enabled)}).wait();
}
bool CommonApiRpcClient::wallet_set_transaction_scanning(bool enabled)
{
  fc::variant result = get_json_connection()->async_call("wallet_set_transaction_scanning", std::vector<fc::variant>{fc::variant(enabled)}).wait();
  return result.as<bool>();
}
fc::ecc::compact_signature CommonApiRpcClient::wallet_sign_hash(const std::string& signer, const fc::sha256& hash)
{
  fc::variant result = get_json_connection()->async_call("wallet_sign_hash", std::vector<fc::variant>{fc::variant(signer), fc::variant(hash)}).wait();
  return result.as<fc::ecc::compact_signature>();
}
std::string CommonApiRpcClient::wallet_login_start(const std::string& server_account)
{
  fc::variant result = get_json_connection()->async_call("wallet_login_start", std::vector<fc::variant>{fc::variant(server_account)}).wait();
  return result.as<std::string>();
}
fc::variant CommonApiRpcClient::wallet_login_finish(const goopal::blockchain::PublicKeyType& server_key, const goopal::blockchain::PublicKeyType& client_key, const fc::ecc::compact_signature& client_signature)
{
  fc::variant result = get_json_connection()->async_call("wallet_login_finish", std::vector<fc::variant>{fc::variant(server_key), fc::variant(client_key), fc::variant(client_signature)}).wait();
  return result.as<fc::variant>();
}
goopal::wallet::TransactionBuilder CommonApiRpcClient::wallet_balance_set_vote_info(const goopal::blockchain::Address& balance_id, const std::string& voter_address /* = fc::json::from_string("\"\"").as<std::string>() */, const goopal::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_all\"").as<goopal::wallet::VoteStrategy>() */, bool sign_and_broadcast /* = fc::json::from_string("\"true\"").as<bool>() */, const std::string& builder_path /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_balance_set_vote_info", std::vector<fc::variant>{fc::variant(balance_id), fc::variant(voter_address), fc::variant(strategy), fc::variant(sign_and_broadcast), fc::variant(builder_path)}).wait();
  return result.as<goopal::wallet::TransactionBuilder>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_publish_slate(const std::string& publishing_account_name, const std::string& paying_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_publish_slate", std::vector<fc::variant>{fc::variant(publishing_account_name), fc::variant(paying_account_name)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_publish_version(const std::string& publishing_account_name, const std::string& paying_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_publish_version", std::vector<fc::variant>{fc::variant(publishing_account_name), fc::variant(paying_account_name)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_collect_genesis_balances(const std::string& account_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_collect_genesis_balances", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
int32_t CommonApiRpcClient::wallet_recover_accounts(int32_t accounts_to_recover, int32_t maximum_number_of_attempts /* = fc::json::from_string("1000").as<int32_t>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_recover_accounts", std::vector<fc::variant>{fc::variant(accounts_to_recover), fc::variant(maximum_number_of_attempts)}).wait();
  return result.as<int32_t>();
}
fc::optional<fc::variant_object> CommonApiRpcClient::wallet_verify_titan_deposit(const std::string& transaction_id_prefix)
{
  fc::variant result = get_json_connection()->async_call("wallet_verify_titan_deposit", std::vector<fc::variant>{fc::variant(transaction_id_prefix)}).wait();
  return result.as<fc::optional<fc::variant_object>>();
}
void CommonApiRpcClient::wallet_repair_entrys(const std::string& collecting_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("wallet_repair_entrys", std::vector<fc::variant>{fc::variant(collecting_account_name)}).wait();
}
int32_t CommonApiRpcClient::wallet_regenerate_keys(const std::string& account_name, uint32_t max_key_number)
{
  fc::variant result = get_json_connection()->async_call("wallet_regenerate_keys", std::vector<fc::variant>{fc::variant(account_name), fc::variant(max_key_number)}).wait();
  return result.as<int32_t>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::wallet_account_retract(const std::string& account_to_retract, const std::string& pay_from_account)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_retract", std::vector<fc::variant>{fc::variant(account_to_retract), fc::variant(pay_from_account)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
bool CommonApiRpcClient::wallet_account_delete(const std::string& account_name)
{
  fc::variant result = get_json_connection()->async_call("wallet_account_delete", std::vector<fc::variant>{fc::variant(account_name)}).wait();
  return result.as<bool>();
}
fc::variant_object CommonApiRpcClient::about() const
{
  fc::variant result = get_json_connection()->async_call("about", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant_object>();
}
fc::variant_object CommonApiRpcClient::get_info() const
{
  fc::variant result = get_json_connection()->async_call("get_info", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant_object>();
}
void CommonApiRpcClient::stop()
{
  fc::variant result = get_json_connection()->async_call("stop", std::vector<fc::variant>{}).wait();
}
std::string CommonApiRpcClient::help(const std::string& command_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  fc::variant result = get_json_connection()->async_call("help", std::vector<fc::variant>{fc::variant(command_name)}).wait();
  return result.as<std::string>();
}
fc::variant_object CommonApiRpcClient::validate_address(const std::string& address) const
{
  fc::variant result = get_json_connection()->async_call("validate_address", std::vector<fc::variant>{fc::variant(address)}).wait();
  return result.as<fc::variant_object>();
}
std::string CommonApiRpcClient::execute_command_line(const std::string& input) const
{
  fc::variant result = get_json_connection()->async_call("execute_command_line", std::vector<fc::variant>{fc::variant(input)}).wait();
  return result.as<std::string>();
}
void CommonApiRpcClient::execute_script(const fc::path& script) const
{
  fc::variant result = get_json_connection()->async_call("execute_script", std::vector<fc::variant>{fc::variant(script)}).wait();
}
fc::variants CommonApiRpcClient::batch(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const
{
  fc::variant result = get_json_connection()->async_call("batch", std::vector<fc::variant>{fc::variant(method_name), fc::variant(parameters_list)}).wait();
  return result.as<fc::variants>();
}
fc::variants CommonApiRpcClient::batch_authenticated(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const
{
  fc::variant result = get_json_connection()->async_call("batch_authenticated", std::vector<fc::variant>{fc::variant(method_name), fc::variant(parameters_list)}).wait();
  return result.as<fc::variants>();
}
goopal::wallet::WalletTransactionEntry CommonApiRpcClient::builder_finalize_and_sign(const goopal::wallet::TransactionBuilder& builder) const
{
  fc::variant result = get_json_connection()->async_call("builder_finalize_and_sign", std::vector<fc::variant>{fc::variant(builder)}).wait();
  return result.as<goopal::wallet::WalletTransactionEntry>();
}
std::map<std::string, goopal::api::MethodData> CommonApiRpcClient::meta_help() const
{
  fc::variant result = get_json_connection()->async_call("meta_help", std::vector<fc::variant>{}).wait();
  return result.as<std::map<std::string, goopal::api::MethodData>>();
}
void CommonApiRpcClient::rpc_set_username(const std::string& username /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("rpc_set_username", std::vector<fc::variant>{fc::variant(username)}).wait();
}
void CommonApiRpcClient::rpc_set_password(const std::string& password /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  fc::variant result = get_json_connection()->async_call("rpc_set_password", std::vector<fc::variant>{fc::variant(password)}).wait();
}
void CommonApiRpcClient::rpc_start_server(uint32_t port /* = fc::json::from_string("\"65065\"").as<uint32_t>() */)
{
  fc::variant result = get_json_connection()->async_call("rpc_start_server", std::vector<fc::variant>{fc::variant(port)}).wait();
}
void CommonApiRpcClient::http_start_server(uint32_t port /* = fc::json::from_string("\"65066\"").as<uint32_t>() */)
{
  fc::variant result = get_json_connection()->async_call("http_start_server", std::vector<fc::variant>{fc::variant(port)}).wait();
}
void CommonApiRpcClient::ntp_update_time()
{
  fc::variant result = get_json_connection()->async_call("ntp_update_time", std::vector<fc::variant>{}).wait();
}
fc::variant CommonApiRpcClient::disk_usage() const
{
  fc::variant result = get_json_connection()->async_call("disk_usage", std::vector<fc::variant>{}).wait();
  return result.as<fc::variant>();
}

} } // end namespace goopal::rpc_stubs
