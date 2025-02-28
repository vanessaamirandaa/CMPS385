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
    Node* prev, *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

int DoubleLinkedlistInsert(int data, int index, Node** head) {
    if (index < 0) return -1;
    Node* newNode = new Node(data);
    if (!*head) return (*head = newNode), 0;
    Node* temp = *head;
    for (int i = 0; temp && i < index - 1; temp = temp->next, i++);
    if (!temp && index) return -1;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    return 0;
}

int DoubleLinkedlistDelete(int index, Node** head) {
    if (!*head || index < 0) return -1;
    Node* temp = *head;
    for (int i = 0; temp && i < index; temp = temp->next, i++);
    if (!temp) return -1;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next;
    delete temp;
    return 0;
}

void printList(Node* head) {
    for (Node* temp = head; temp; temp = temp->next)
        cout << temp->data << " <-> ";
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    DoubleLinkedlistInsert(10, 0, &head);
    DoubleLinkedlistInsert(20, 1, &head);
    DoubleLinkedlistInsert(30, 2, &head);
    DoubleLinkedlistInsert(15, 1, &head);
    cout << "Doubly Linked List after insertions:\n";
    printList(head);
    DoubleLinkedlistDelete(2, &head);
    cout << "Doubly Linked List after deletion:\n";
    printList(head);
    return 0;
}
