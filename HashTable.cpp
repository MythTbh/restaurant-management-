#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <limits>

using std::cout;
using std::string;

HashTable::HashTable(int cap) : capacity(cap) {
    table.resize(capacity, nullptr);
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        HashNode* curr = table[i];
        while (curr) {
            HashNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}

int HashTable::hashFunction(int key) const {
    if (key < 0) key = -key;
    return key % capacity;
}

bool HashTable::insertItem(const Item& item) {
    int index = hashFunction(item.id);
    HashNode* curr = table[index];

    while (curr) {
        if (curr->item.id == item.id) {
            curr->item.name = item.name;
            curr->item.quantity = item.quantity;
            return false; // updated existing
        }
        curr = curr->next;
    }

    HashNode* node = new HashNode(item);
    node->next = table[index];
    table[index] = node;
    return true; // new insert
}

bool HashTable::searchItem(int id, Item& result) const {
    int index = hashFunction(id);
    HashNode* curr = table[index];
    while (curr) {
        if (curr->item.id == id) {
            result = curr->item;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool HashTable::deleteItem(int id) {
    int index = hashFunction(id);
    HashNode* curr = table[index];
    HashNode* prev = nullptr;

    while (curr) {
        if (curr->item.id == id) {
            if (prev) {
                prev->next = curr->next;
            } else {
                table[index] = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

bool HashTable::modifyItem(int id, const string& newName, int newQty) {
    int index = hashFunction(id);
    HashNode* curr = table[index];
    while (curr) {
        if (curr->item.id == id) {
            curr->item.name = newName;
            curr->item.quantity = newQty;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void HashTable::printAll() const {
    cout << "Current Inventory:\n";
    for (int i = 0; i < capacity; ++i) {
        HashNode* curr = table[i];
        while (curr) {
            cout << "ID: " << curr->item.id
                 << ", Name: " << curr->item.name
                 << ", Qty: " << curr->item.quantity << "\n";
            curr = curr->next;
        }
    }
}

void HashTable::saveToFile(const string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        cout << "Error opening file for writing.\n";
        return;
    }
    for (int i = 0; i < capacity; ++i) {
        HashNode* curr = table[i];
        while (curr) {
            out << curr->item.id << ","
                << curr->item.name << ","
                << curr->item.quantity << "\n";
            curr = curr->next;
        }
    }
    out.close();
    cout << "Inventory saved to " << filename << "\n";
}

void HashTable::loadFromFile(const string& filename) {
    std::ifstream in(filename);
    if (!in) {
        cout << "No existing file or error opening file.\n";
        return;
    }

    // clear existing
    for (int i = 0; i < capacity; ++i) {
        HashNode* curr = table[i];
        while (curr) {
            HashNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
        table[i] = nullptr;
    }

    int id;
    string name;
    int qty;
    char comma;

    while (in >> id >> comma) {
        if (!std::getline(in, name, ',')) break;
        in >> qty;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Item item{id, name, qty};
        insertItem(item);
    }
    in.close();
    cout << "Inventory loaded from " << filename << "\n";
}
