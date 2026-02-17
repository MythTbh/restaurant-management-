#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>

struct TransactionNode {
    std::string description;
    TransactionNode* next;
    TransactionNode(const std::string& desc) : description(desc), next(nullptr) {}
};

class TransactionList {
private:
    TransactionNode* head;
    int maxSize;

public:
    TransactionList(int maxSize = 20);
    ~TransactionList();

    void addTransaction(const std::string& desc);
    void printRecent() const;
};

#endif
