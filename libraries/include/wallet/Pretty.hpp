/*
 * This file contains structs to populate for JSON representation of transactions/operations
 * for wallets and block explorers and such
 */

#pragma once

namespace goopal { namespace wallet {

using namespace goopal::blockchain;

struct PublicKeySummary
{
    string    hex;
    string    native_pubkey;
    string    native_address;
    string    pts_normal_address;
    string    pts_compressed_address;
    string    btc_normal_address;
    string    btc_compressed_address;

};

struct VoteSummary
{
    bool      up_to_date_with_recommendation;  // Are my votes all voting for the result of "vote_recommended" ?
    float     utilization;
    float     negative_utilization;
};

struct PrettyLedgerEntry
{
   string                                   from_account;
   string                                   to_account;
   Asset                                    amount;
   string                                   memo;
   map<string, map<AssetIdType, Asset>>   running_balances;
};

struct PrettyTransaction
{
    bool                        is_virtual = false;
    bool                        is_confirmed = false;
    bool                        is_market = false;
    bool                        is_market_cancel = false;
    TransactionIdType         trx_id;
    uint32_t                    block_num = 0;
    vector<PrettyLedgerEntry> ledger_entries;
    Asset                       fee;
    fc::time_point_sec          timestamp;
    fc::time_point_sec          expiration_timestamp;
    optional<fc::exception>     error;
};

struct PrettyReserveBalance
{
    BalanceIdType     balance_id;
    optional<string>    sharedrop_address;

    time_point_sec      start_time;
    uint32_t            duration = 0;

    AssetIdType       asset_id;
    ShareType          original_balance;
    ShareType          reserve_balance;
    ShareType          claimed_balance;
    ShareType          available_balance;
};

   struct EscrowSummary
   {
      /** the transaction ID that created the escrow balance */
      TransactionIdType creating_transaction_id;
      BalanceIdType     balance_id;
      /** the amount of money still held in escrow */
      Asset               balance;
      /** the account name of the escrow agent */
      string              sender_account_name;
      string              receiver_account_name;
      string              escrow_agent_account_name;
      DigestType         agreement_digest;
   };


}} // goopal::wallet

FC_REFLECT( goopal::wallet::PublicKeySummary, (hex)(native_pubkey)(native_address)(pts_normal_address)(pts_compressed_address)(btc_normal_address)(btc_compressed_address) )

FC_REFLECT( goopal::wallet::VoteSummary, (utilization)(negative_utilization)(up_to_date_with_recommendation) )

FC_REFLECT( goopal::wallet::PrettyLedgerEntry,
            (from_account)
            (to_account)
            (amount)
            (memo)
            (running_balances)
            )
FC_REFLECT( goopal::wallet::PrettyTransaction,
            (is_virtual)
            (is_confirmed)
            (is_market)
            (is_market_cancel)
            (trx_id)
            (block_num)
            (ledger_entries)
            (fee)
            (timestamp)
            (expiration_timestamp)
            (error)
            )
FC_REFLECT( goopal::wallet::PrettyReserveBalance,
        (balance_id)
        (sharedrop_address)
        (start_time)
        (duration)
        (asset_id)
        (original_balance)
        (reserve_balance)
        (claimed_balance)
        (available_balance)
        )
FC_REFLECT( goopal::wallet::EscrowSummary,
            (creating_transaction_id)
            (balance_id)
            (balance)
            (sender_account_name)
            (receiver_account_name)
            (escrow_agent_account_name)
            (agreement_digest)
            )
