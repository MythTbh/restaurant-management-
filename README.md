# This was a group assignment for Data Structure class

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/tZkI3Gp9)



# Storeventory 

Storeventory is a simple console-based store inventory management system written in C++.  
It stores items in a hash table keyed by item ID and keeps a linked-list log of recent transactions.

## Features

- Add a new item (ID, name, quantity)
- Search for an item by ID
- Modify an existing item
- Delete an item
- Display all items in the inventory
- View recent transactions (adds, updates, deletes)
- Save inventory to a CSV file (`inventory.csv`)
- Load inventory from a CSV file (`inventory.csv`)

## Project Structure

- `Item.h`  
  Defines the `Item` struct (ID, name, quantity).

- `HashTable.h` / `HashTable.cpp`  
  Implements a hash table with separate chaining:
  - `insertItem`
  - `searchItem`
  - `modifyItem`
  - `deleteItem`
  - `printAll`
  - `saveToFile`
  - `loadFromFile`

- `Transactions.h` / `Transactions.cpp`  
  Implements a singly linked list for recent transaction logs:
  - `addTransaction`
  - `printRecent`

- `main.cpp`  
  Contains the menu-driven user interface and uses `HashTable` and `TransactionList`.

## Requirements

- C++17-compatible compiler (for example, `g++`, `clang++`, or MSVC)
- Standard C++ library only (no external libraries required)

## How to Build

### Using g++ 
- In your terminal type
( g++ -std=c++17 -g *.cpp -o StoreVentory.exe  )
This should compile and build the program

If compilation succeeds, an executable named `StoreVentory.exe` will be created.

### How to Run the Program
Type
.\StoreVentory.exe
