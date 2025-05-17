//
//  main.cpp
//  Data Structures
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    int pos = 2; // position to insert
    int value = 25;

    vec.insert(vec.begin() + pos, value);

    for (int v : vec)
        cout << v << " | ";
    return 0;
}
