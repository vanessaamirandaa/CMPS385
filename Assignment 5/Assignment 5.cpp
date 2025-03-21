//
//  main.cpp
//  CMPS 385
//
//  Created by Vanessa Miranda on 03/21/25.
//
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void reheapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void reheapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        reheapifyUp(heap.size() - 1);
    }

    void removeMin() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        reheapifyDown(0);
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;
    
    cout << "Inserting elements into the heap:\n";
    minHeap.insert(10);
    minHeap.insert(4);
    minHeap.insert(15);
    minHeap.insert(20);
    minHeap.insert(0);
    minHeap.insert(8);
    minHeap.printHeap();

    cout << "Removing the minimum element:\n";
    minHeap.removeMin();
    minHeap.printHeap();
    
    return 0;
}
