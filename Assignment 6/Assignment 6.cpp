//
//  main.cpp
//  Data Structures
//
//  Created by Vanessa Miranda on 4/7/25.
//

#include <iostream>
using namespace std;

const int TABLE_SIZE = 907;
const int EMPTY = -1;
const int DELETED = -2;

int hashTable[TABLE_SIZE];

// Initialize the hash table
void InitializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Hash function
int HashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insertion using linear probing
int HashInsertion(int key) {
    int hash = HashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = (hash + i) % TABLE_SIZE;
        if (hashTable[index] == EMPTY || hashTable[index] == DELETED) {
            hashTable[index] = key;
            return index;
        }
    }
    return -1; // Table is full
}

// Deletion using linear probing
int HashDeletion(int key) {
    int hash = HashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = (hash + i) % TABLE_SIZE;
        if (hashTable[index] == EMPTY) {
            return -1; // Key not found
        }
        if (hashTable[index] == key) {
            hashTable[index] = DELETED;
            return index;
        }
    }
    return -1; // Key not found
}

// Display the hash table (for testing)
void PrintTable() {
    for (int i = 0; i < 20; i++) { // just print first 20 slots
        cout << "[" << i << "]: " << hashTable[i] << endl;
    }
}

// Main function to test
int main() {
    InitializeTable();

    cout << "Inserting keys..." << endl;
    HashInsertion(1000);
    HashInsertion(1814);
    HashInsertion(907);
    HashInsertion(908);
    HashInsertion(1001);

    PrintTable();

    cout << "\nDeleting key 907..." << endl;
    HashDeletion(907);

    PrintTable();

    return 0;
}
