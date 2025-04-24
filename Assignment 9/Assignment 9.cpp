//
//  main.cpp
//  Data Structures
//
//  Created by Vanessa Miranda on 4/7/25.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A simple structure to simulate a B⁻-like node with insert
struct BMinusTree {
    vector<int> keys;

    // Insert function that keeps keys sorted
    void insert(int key) {
        keys.push_back(key);
        sort(keys.begin(), keys.end()); // Keep keys in order (not optimal for real B-Trees)
    }

    void print() {
        cout << "Keys in B⁻-Tree: ";
        for (int key : keys) {
            cout << key << " ";
        }
        cout << endl;
    }
};

int main() {
    BMinusTree tree;

    // Insert some sample keys
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(15);

    tree.print(); // Output should be: 5 10 15 20

    return 0;
}
