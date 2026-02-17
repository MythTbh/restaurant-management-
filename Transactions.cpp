#include "Transactions.h"
#include <iostream>

using std::cout;
using std::string;

TransactionList::TransactionList(int maxSize)
    : head(nullptr), maxSize(maxSize) {}

TransactionList::~TransactionList() {
    TransactionNode* curr = head;
    while (curr) {
        TransactionNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void TransactionList::addTransaction(const string& desc) {
    TransactionNode* node = new TransactionNode(desc);
    node->next = head;
    head = node;

    int count = 0;
    TransactionNode* prev = nullptr;
    TransactionNode* curr = head;
    while (curr) {
        count++;
        if (count > maxSize) {
            if (prev) {
                prev->next = nullptr;
            }
            while (curr) {
                TransactionNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

void TransactionList::printRecent() const {
    if (!head) {
        cout << "No recent transactions.\n";
        return;
    }
    cout << "Recent Transactions:\n";
    TransactionNode* curr = head;
    while (curr) {
        cout << "- " << curr->description << "\n";
        curr = curr->next;
    }
}
