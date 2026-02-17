#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <string>
#include "Item.h"

struct HashNode {
    Item item;
    HashNode* next;
    HashNode(const Item& it) : item(it), next(nullptr) {}
};

class HashTable {
private:
    std::vector<HashNode*> table;
    int capacity;

    int hashFunction(int key) const;

public:
    HashTable(int cap = 101);
    ~HashTable();

    bool insertItem(const Item& item);          // add or update
    bool searchItem(int id, Item& result) const;
    bool deleteItem(int id);
    bool modifyItem(int id, const std::string& newName, int newQty);
    void printAll() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
