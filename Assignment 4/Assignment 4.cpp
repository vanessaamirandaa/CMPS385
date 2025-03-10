//
//  main.cpp
//  CMPS 385
//
//  Created by Vanessa Miranda on 03/09/25.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear;
public:
    CircularQueue() : rear(nullptr) {}

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* front = rear->next;
        if (rear == front) {
            rear = nullptr;
        } else {
            rear->next = front->next;
        }
        delete front;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << rear->next->data << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.getFront(); // Should print 10
    q.dequeue();
    q.getFront(); // Should print 20
    q.dequeue();
    q.dequeue();
    q.getFront(); // Should print "Queue is empty!"
    return 0;
}
