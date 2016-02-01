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
#pragma once
#include <api/ApiMetadata.hpp>
#include <api/CommonApi.hpp>

namespace goopal { namespace rpc_stubs {
  class CommonApiClient : public goopal::api::CommonApi
  {
  protected:
    virtual goopal::api::CommonApi* get_impl() const = 0;

  public:
    fc::variant_object blockchain_get_info() const override;
    void blockchain_generate_snapshot(const std::string& filename) const override;
    std::vector<goopal::blockchain::GopTrxidBalance> blockchain_get_gop_account_balance_entry(uint32_t block_num) override;
    void blockchain_generate_issuance_map(const std::string& symbol, const std::string& filename) const override;
    goopal::blockchain::Asset blockchain_calculate_supply(const std::string& asset) const override;
    bool blockchain_is_synced() const override;
    uint32_t blockchain_get_block_count() const override;
    goopal::blockchain::BlockchainSecurityState blockchain_get_security_state() const override;
    std::vector<goopal::blockchain::AccountEntry> blockchain_list_accounts(const std::string& first_account_name = fc::json::from_string("\"\"").as<std::string>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) const override;
    std::vector<goopal::blockchain::AccountEntry> blockchain_list_recently_updated_accounts() const override;
    std::vector<goopal::blockchain::AccountEntry> blockchain_list_recently_registered_accounts() const override;
    std::vector<goopal::blockchain::AssetEntry> blockchain_list_assets(const std::string& first_symbol = fc::json::from_string("\"\"").as<std::string>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) const override;
    std::vector<goopal::blockchain::SignedTransaction> blockchain_list_pending_transactions() const override;
    std::pair<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> blockchain_get_transaction(const std::string& transaction_id_prefix, bool exact = fc::json::from_string("false").as<bool>()) const override;
    fc::optional<goopal::blockchain::BlockEntry> blockchain_get_block(const std::string& block) const override;
    std::map<goopal::blockchain::TransactionIdType, goopal::blockchain::TransactionEntry> blockchain_get_block_transactions(const std::string& block) const override;
    fc::optional<goopal::blockchain::AccountEntry> blockchain_get_account(const std::string& account) const override;
    std::map<goopal::blockchain::AccountIdType, std::string> blockchain_get_slate(const std::string& slate) const override;
    goopal::blockchain::BalanceEntry blockchain_get_balance(const goopal::blockchain::Address& balance_id) const override;
    std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> blockchain_list_balances(const std::string& first_balance_id = fc::json::from_string("\"\"").as<std::string>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) const override;
    std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> blockchain_list_address_balances(const std::string& addr, const fc::time_point& chanced_since = fc::json::from_string("\"1970-1-1T00:00:01\"").as<fc::time_point>()) const override;
    fc::variant_object blockchain_list_address_transactions(const std::string& addr, uint32_t filter_before = fc::json::from_string("\"0\"").as<uint32_t>()) const override;
    goopal::wallet::AccountBalanceSummaryType blockchain_get_account_public_balance(const std::string& account_name) const override;
    std::unordered_map<goopal::blockchain::BalanceIdType, goopal::blockchain::BalanceEntry> blockchain_list_key_balances(const goopal::blockchain::PublicKeyType& key) const override;
    fc::optional<goopal::blockchain::AssetEntry> blockchain_get_asset(const std::string& asset) const override;
    std::vector<goopal::blockchain::AccountEntry> blockchain_list_active_delegates(uint32_t first = fc::json::from_string("0").as<uint32_t>(), uint32_t count = fc::json::from_string("20").as<uint32_t>()) const override;
    std::vector<goopal::blockchain::AccountEntry> blockchain_list_delegates(uint32_t first = fc::json::from_string("0").as<uint32_t>(), uint32_t count = fc::json::from_string("20").as<uint32_t>()) const override;
    std::vector<goopal::blockchain::BlockEntry> blockchain_list_blocks(uint32_t max_block_num = fc::json::from_string("-1").as<uint32_t>(), uint32_t limit = fc::json::from_string("20").as<uint32_t>()) override;
    std::vector<std::string> blockchain_list_missing_block_delegates(uint32_t block_number) override;
    std::string blockchain_export_fork_graph(uint32_t start_block = fc::json::from_string("1").as<uint32_t>(), uint32_t end_block = fc::json::from_string("-1").as<uint32_t>(), const std::string& filename = fc::json::from_string("\"\"").as<std::string>()) const override;
    std::map<uint32_t, std::vector<goopal::blockchain::ForkEntry>> blockchain_list_forks() const override;
    std::vector<goopal::blockchain::SlotEntry> blockchain_get_delegate_slot_entrys(const std::string& delegate_name, uint32_t limit = fc::json::from_string("\"10\"").as<uint32_t>()) const override;
    std::string blockchain_get_block_signee(const std::string& block) const override;
    goopal::blockchain::Asset blockchain_unclaimed_genesis() const override;
    bool blockchain_verify_signature(const std::string& signer, const fc::sha256& hash, const fc::ecc::compact_signature& signature) const override;
    void blockchain_dump_state(const std::string& path) const override;
    void blockchain_broadcast_transaction(const goopal::blockchain::SignedTransaction& trx) override;
    void blockchain_btc_address_convert(const std::string& path) const override;
    void network_add_node(const std::string& node, const std::string& command = fc::json::from_string("\"add\"").as<std::string>()) override;
    uint32_t network_get_connection_count() const override;
    std::vector<fc::variant_object> network_get_peer_info(bool not_firewalled = fc::json::from_string("false").as<bool>()) const override;
    goopal::blockchain::TransactionIdType network_broadcast_transaction(const goopal::blockchain::SignedTransaction& transaction_to_broadcast) override;
    void network_set_advanced_node_parameters(const fc::variant_object& params) override;
    fc::variant_object network_get_advanced_node_parameters() const override;
    goopal::net::MessagePropagationData network_get_transaction_propagation_data(const goopal::blockchain::TransactionIdType& transaction_id) override;
    goopal::net::MessagePropagationData network_get_block_propagation_data(const goopal::blockchain::BlockIdType& block_hash) override;
    fc::variant_object network_get_info() const override;
    std::vector<goopal::net::PotentialPeerEntry> network_list_potential_peers() const override;
    fc::variant_object network_get_upnp_info() const override;
    std::string debug_get_client_name() const override;
    fc::variant delegate_get_config() const override;
    void delegate_set_network_min_connection_count(uint32_t count) override;
    void delegate_set_block_max_transaction_count(uint32_t count) override;
    void delegate_set_block_max_size(uint32_t size) override;
    void delegate_set_transaction_max_size(uint32_t size) override;
    void delegate_set_transaction_canonical_signatures_required(bool required) override;
    void delegate_set_transaction_min_fee(uint64_t fee) override;
    void delegate_blacklist_add_transaction(const goopal::blockchain::TransactionIdType& id) override;
    void delegate_blacklist_remove_transaction(const goopal::blockchain::TransactionIdType& id) override;
    void delegate_blacklist_add_operation(const goopal::blockchain::OperationTypeEnum& id) override;
    void delegate_blacklist_remove_operation(const goopal::blockchain::OperationTypeEnum& id) override;
    fc::variant_object wallet_get_info() override;
    void wallet_open(const std::string& wallet_name) override;
    void wallet_create(const std::string& wallet_name, const std::string& new_passphrase, const std::string& brain_key = fc::json::from_string("\"\"").as<std::string>()) override;
    fc::optional<std::string> wallet_get_name() const override;
    std::string wallet_import_private_key(const std::string& wif_key, const std::string& account_name = fc::json::from_string("null").as<std::string>(), bool create_new_account = fc::json::from_string("false").as<bool>(), bool rescan = fc::json::from_string("false").as<bool>()) override;
    void wallet_close() override;
    void wallet_backup_create(const fc::path& json_filename) const override;
    void wallet_backup_restore(const fc::path& json_filename, const std::string& wallet_name, const std::string& imported_wallet_passphrase) override;
    bool wallet_set_automatic_backups(bool enabled) override;
    uint32_t wallet_set_transaction_expiration_time(uint32_t seconds) override;
    std::vector<goopal::wallet::PrettyTransaction> wallet_account_transaction_history(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>(), const std::string& asset_symbol = fc::json::from_string("\"\"").as<std::string>(), int32_t limit = fc::json::from_string("0").as<int32_t>(), uint32_t start_block_num = fc::json::from_string("0").as<uint32_t>(), uint32_t end_block_num = fc::json::from_string("-1").as<uint32_t>()) const override;
    std::vector<goopal::wallet::PrettyTransaction> wallet_transaction_history_splite(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>(), const std::string& asset_symbol = fc::json::from_string("\"\"").as<std::string>(), int32_t limit = fc::json::from_string("0").as<int32_t>(), int32_t transaction_type = fc::json::from_string("\"2\"").as<int32_t>()) const override;
    goopal::wallet::AccountBalanceSummaryType wallet_account_historic_balance(const fc::time_point& time, const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const override;
    void wallet_remove_transaction(const std::string& transaction_id) override;
    std::map<goopal::blockchain::TransactionIdType, fc::exception> wallet_get_pending_transaction_errors(const std::string& filename = fc::json::from_string("\"\"").as<std::string>()) const override;
    void wallet_lock() override;
    void wallet_unlock(uint32_t timeout, const std::string& passphrase) override;
    void wallet_change_passphrase(const std::string& old_passphrase, const std::string& passphrase) override;
    bool wallet_check_passphrase(const std::string& passphrase) override;
    bool wallet_check_address(const std::string& address) override;
    std::vector<std::string> wallet_list() const override;
    goopal::blockchain::PublicKeyType wallet_account_create(const std::string& account_name, const fc::variant& private_data = fc::json::from_string("null").as<fc::variant>()) override;
    int8_t wallet_account_set_approval(const std::string& account_name, int8_t approval = fc::json::from_string("1").as<int8_t>()) override;
    std::string wallet_address_create(const std::string& account_name, const std::string& label = fc::json::from_string("\"\"").as<std::string>(), int32_t legacy_network_byte = fc::json::from_string("-1").as<int32_t>()) override;
    goopal::wallet::WalletTransactionEntry wallet_transfer_to_address(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_address, const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>(), const goopal::wallet::VoteStrategy& strategy = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>()) override;
    goopal::wallet::WalletTransactionEntry wallet_transfer_to_public_account(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_account_name, const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>(), const goopal::wallet::VoteStrategy& strategy = fc::json::from_string("\"vote_recommended\"").as<goopal::wallet::VoteStrategy>()) override;
    goopal::wallet::TransactionBuilder wallet_withdraw_from_address(const std::string& amount, const std::string& symbol, const goopal::blockchain::Address& from_address, const std::string& to, const goopal::wallet::VoteStrategy& strategy = fc::json::from_string("\"vote_none\"").as<goopal::wallet::VoteStrategy>(), bool sign_and_broadcast = fc::json::from_string("true").as<bool>(), const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>()) override;
    void wallet_rescan_blockchain(uint32_t start_block_num = fc::json::from_string("0").as<uint32_t>(), uint32_t limit = fc::json::from_string("-1").as<uint32_t>()) override;
    void wallet_cancel_scan() override;
    goopal::wallet::WalletTransactionEntry wallet_get_transaction(const std::string& transaction_id) override;
    goopal::wallet::WalletTransactionEntry wallet_scan_transaction(const std::string& transaction_id, bool overwrite_existing = fc::json::from_string("false").as<bool>()) override;
    void wallet_rebroadcast_transaction(const std::string& transaction_id) override;
    goopal::wallet::WalletTransactionEntry wallet_account_register(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data = fc::json::from_string("null").as<fc::variant>(), uint8_t delegate_pay_rate = fc::json::from_string("-1").as<uint8_t>(), const std::string& account_type = fc::json::from_string("\"titan_account\"").as<std::string>()) override;
    void wallet_account_update_private_data(const std::string& account_name, const fc::variant& private_data = fc::json::from_string("null").as<fc::variant>()) override;
    goopal::wallet::WalletTransactionEntry wallet_account_update_registration(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data = fc::json::from_string("null").as<fc::variant>(), uint8_t delegate_pay_rate = fc::json::from_string("-1").as<uint8_t>()) override;
    goopal::wallet::WalletTransactionEntry wallet_account_update_active_key(const std::string& account_to_update, const std::string& pay_from_account, const std::string& new_active_key = fc::json::from_string("\"\"").as<std::string>()) override;
    std::vector<goopal::wallet::WalletAccountEntry> wallet_list_accounts() const override;
    std::vector<goopal::wallet::WalletAccountEntry> wallet_list_unregistered_accounts() const override;
    std::vector<goopal::wallet::WalletAccountEntry> wallet_list_my_accounts() const override;
    goopal::wallet::WalletAccountEntry wallet_get_account(const std::string& account_name) const override;
    std::string wallet_get_account_public_address(const std::string& account_name) const override;
    void wallet_remove_contact_account(const std::string& account_name) override;
    void wallet_account_rename(const std::string& current_account_name, const std::string& new_account_name) override;
    goopal::wallet::WalletTransactionEntry wallet_asset_create(const std::string& symbol, const std::string& asset_name, const std::string& issuer_name, const std::string& description, double maximum_share_supply, uint64_t precision, const fc::variant& public_data = fc::json::from_string("null").as<fc::variant>(), bool is_market_issued = fc::json::from_string("false").as<bool>()) override;
    goopal::wallet::WalletTransactionEntry wallet_asset_issue(double amount, const std::string& symbol, const std::string& to_account_name, const std::string& memo_message = fc::json::from_string("\"\"").as<std::string>()) override;
    goopal::wallet::WalletTransactionEntry wallet_asset_issue_to_addresses(const std::string& symbol, const std::map<std::string, goopal::blockchain::ShareType>& addresses) override;
    goopal::wallet::AccountBalanceSummaryType wallet_account_balance(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const override;
    goopal::wallet::AccountBalanceIdSummaryType wallet_account_balance_ids(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const override;
    std::vector<goopal::wallet::PublicKeySummary> wallet_account_list_public_keys(const std::string& account_name) override;
    goopal::wallet::WalletTransactionEntry wallet_delegate_withdraw_pay(const std::string& delegate_name, const std::string& to_account_name, double amount_to_withdraw) override;
    int64_t wallet_delegate_pay_balance_query(const std::string& delegate_name) override;
    bool wallet_get_delegate_statue(const std::string& account_name) override;
    goopal::blockchain::Asset wallet_set_transaction_fee(double fee) override;
    goopal::blockchain::Asset wallet_get_transaction_fee(const std::string& symbol = fc::json::from_string("\"\"").as<std::string>()) override;
    fc::optional<std::string> wallet_dump_private_key(const std::string& input) const override;
    fc::optional<std::string> wallet_dump_account_private_key(const std::string& account_name, const goopal::wallet::AccountKeyType& key_type) const override;
    goopal::wallet::AccountVoteSummaryType wallet_account_vote_summary(const std::string& account_name = fc::json::from_string("\"\"").as<std::string>()) const override;
    goopal::wallet::VoteSummary wallet_check_vote_status(const std::string& account) override;
    void wallet_set_setting(const std::string& name, const fc::variant& value) override;
    fc::optional<fc::variant> wallet_get_setting(const std::string& name) override;
    void wallet_delegate_set_block_production(const std::string& delegate_name, bool enabled) override;
    bool wallet_set_transaction_scanning(bool enabled) override;
    fc::ecc::compact_signature wallet_sign_hash(const std::string& signer, const fc::sha256& hash) override;
    std::string wallet_login_start(const std::string& server_account) override;
    fc::variant wallet_login_finish(const goopal::blockchain::PublicKeyType& server_key, const goopal::blockchain::PublicKeyType& client_key, const fc::ecc::compact_signature& client_signature) override;
    goopal::wallet::TransactionBuilder wallet_balance_set_vote_info(const goopal::blockchain::Address& balance_id, const std::string& voter_address = fc::json::from_string("\"\"").as<std::string>(), const goopal::wallet::VoteStrategy& strategy = fc::json::from_string("\"vote_all\"").as<goopal::wallet::VoteStrategy>(), bool sign_and_broadcast = fc::json::from_string("\"true\"").as<bool>(), const std::string& builder_path = fc::json::from_string("\"\"").as<std::string>()) override;
    goopal::wallet::WalletTransactionEntry wallet_publish_slate(const std::string& publishing_account_name, const std::string& paying_account_name = fc::json::from_string("\"\"").as<std::string>()) override;
    goopal::wallet::WalletTransactionEntry wallet_publish_version(const std::string& publishing_account_name, const std::string& paying_account_name = fc::json::from_string("\"\"").as<std::string>()) override;
    goopal::wallet::WalletTransactionEntry wallet_collect_genesis_balances(const std::string& account_name) override;
    int32_t wallet_recover_accounts(int32_t accounts_to_recover, int32_t maximum_number_of_attempts = fc::json::from_string("1000").as<int32_t>()) override;
    fc::optional<fc::variant_object> wallet_verify_titan_deposit(const std::string& transaction_id_prefix) override;
    void wallet_repair_entrys(const std::string& collecting_account_name = fc::json::from_string("\"\"").as<std::string>()) override;
    int32_t wallet_regenerate_keys(const std::string& account_name, uint32_t max_key_number) override;
    goopal::wallet::WalletTransactionEntry wallet_account_retract(const std::string& account_to_retract, const std::string& pay_from_account) override;
    bool wallet_account_delete(const std::string& account_name) override;
    fc::variant_object about() const override;
    fc::variant_object get_info() const override;
    void stop() override;
    std::string help(const std::string& command_name = fc::json::from_string("\"\"").as<std::string>()) const override;
    fc::variant_object validate_address(const std::string& address) const override;
    std::string execute_command_line(const std::string& input) const override;
    void execute_script(const fc::path& script) const override;
    fc::variants batch(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const override;
    fc::variants batch_authenticated(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const override;
    goopal::wallet::WalletTransactionEntry builder_finalize_and_sign(const goopal::wallet::TransactionBuilder& builder) const override;
    std::map<std::string, goopal::api::MethodData> meta_help() const override;
    void rpc_set_username(const std::string& username = fc::json::from_string("\"\"").as<std::string>()) override;
    void rpc_set_password(const std::string& password = fc::json::from_string("\"\"").as<std::string>()) override;
    void rpc_start_server(uint32_t port = fc::json::from_string("\"65065\"").as<uint32_t>()) override;
    void http_start_server(uint32_t port = fc::json::from_string("\"65066\"").as<uint32_t>()) override;
    void ntp_update_time() override;
    fc::variant disk_usage() const override;
  };

} } // end namespace goopal::rpc_stubs
