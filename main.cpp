#include <iostream>
#include <string>
#include "HashTable.h"
#include "Transactions.h"

using std::cout;
using std::cin;
using std::string;

void printMenu() {
    cout << "\n===== Storeventory  =====\n";
    cout << "1. Add Item\n";
    cout << "2. Search Item\n";
    cout << "3. Modify Item\n";
    cout << "4. Display All Items\n";
    cout << "5. Delete Item\n";
    cout << "6. View Recent Transactions\n";
    cout << "7. Save to File\n";
    cout << "8. Load from File\n";
    cout << "9. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    HashTable inventory(101);
    TransactionList transactions(20);
    const string filename = "inventory.csv";

    int choice = 0;
    do {
        printMenu();
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 1) {
            Item item;
            cout << "Enter Item ID: ";
            cin >> item.id;
            cin.ignore();
            cout << "Enter Item Name: ";
            std::getline(cin, item.name);
            cout << "Enter Quantity: ";
            cin >> item.quantity;

            bool isNew = inventory.insertItem(item);
            if (isNew) {
                cout << "Item added.\n";
                transactions.addTransaction("Added item ID " + std::to_string(item.id));
            } else {
                cout << "Item existed; updated.\n";
                transactions.addTransaction("Updated item ID " + std::to_string(item.id));
            }

        } else if (choice == 2) {
            int id;
            cout << "Enter Item ID to search: ";
            cin >> id;
            Item found;
            if (inventory.searchItem(id, found)) {
                cout << "Found: ID " << found.id
                     << ", Name: " << found.name
                     << ", Qty: " << found.quantity << "\n";
            } else {
                cout << "Item not found.\n";
            }

        } else if (choice == 3) {
            int id;
            cout << "Enter Item ID to modify: ";
            cin >> id;
            cin.ignore();

            string newName;
            int newQty;
            cout << "Enter new name: ";
            std::getline(cin, newName);
            cout << "Enter new quantity: ";
            cin >> newQty;

            if (inventory.modifyItem(id, newName, newQty)) {
                cout << "Item modified.\n";
                transactions.addTransaction("Modified item ID " + std::to_string(id));
            } else {
                cout << "Item not found.\n";
            }

        } else if (choice == 4) {
            inventory.printAll();

        } else if (choice == 5) {
            int id;
            cout << "Enter Item ID to delete: ";
            cin >> id;
            if (inventory.deleteItem(id)) {
                cout << "Item deleted.\n";
                transactions.addTransaction("Deleted item ID " + std::to_string(id));
            } else {
                cout << "Item not found.\n";
            }

        } else if (choice == 6) {
            transactions.printRecent();

        } else if (choice == 7) {
            inventory.saveToFile(filename);

        } else if (choice == 8) {
            inventory.loadFromFile(filename);

        } else if (choice == 9) {
            cout << "Exiting program.\n";

        } else {
            cout << "Invalid option.\n";
        }

    } while (choice != 9);

    return 0;
}
 
