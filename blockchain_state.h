#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "block.h"
#include "transaction.h"
#include "types.h"

struct AddressSummary {
    static std::uint64_t defaultLastBlockId;

    std::int64_t balance = 0;
    bytes_t secondPubkey;
    std::string delegateName;
    std::uint64_t lastBlockId = AddressSummary::defaultLastBlockId;
};

struct BlockchainState {
    tracking_unordered_map<address_t, AddressSummary> addressSummaries;

    void applyTransaction(const TransactionRow &transactionRow);
    void applyBlock(const BlockHeader &bh, std::uint64_t blockId);
};
