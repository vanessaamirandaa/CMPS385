//
//  main.cpp
//  CMPS 385
//
//  Created by Vanessa Miranda on 2/5/25.
//

#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr){}
};
int Insert(int data, int index, Node** head){
    if (index < 0){
        return -1;
    }
    Node* newNode = new Node(data);
    if (index ==0){
        newNode->next = *head;
        *head = newNode;
        return 0;
    }
    Node* current = *head;
    for (int i=0; i < index -1; ++i){
        if (current == nullptr){
            delete newNode;
            return -1;
        }
        current = current->next;
    }
    if (current == nullptr){
        delete newNode;
        return -1;
    }
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}
int Delete(int index, Node** head) {
    if (*head == nullptr || index < 0) {
        return -1;
    }

    if (index == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return 0;
    }

    Node* current = *head;
    Node* previous = nullptr;
    for (int i = 0; i < index; ++i) {
        if (current == nullptr) {
            return -1;
        }
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return -1;
    }

    previous->next = current->next;
    delete current;
    return 0;
}

int main() {
    Node* head = nullptr;

    Insert(10, 0, &head);
    Insert(20, 1, &head);
    Insert(30, 2, &head);
    Insert(40, 1, &head);

    Delete(1, &head);

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
