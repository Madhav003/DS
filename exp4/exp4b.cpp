//Create double ended queue data structure using Linked List and implement following
//functions: i. Insert front ii. Insert rear iii. Delete front iv. Delete rear v. Display
#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;
} *front = NULL, *rear = NULL;

void insertAtFront(int x) {
    Node* t = new Node;
    if (t == NULL) {
        cout << "Queue is full" << endl;
        return;
    }

    t->data = x;
    t->prev = NULL;
    t->next = front;

    if (front == NULL) {
        front = rear = t;
    } else {
        front->prev = t;
        front = t;
    }
}

void insertAtRear(int x) {
    Node* t = new Node;
    if (t == NULL) {
        cout << "Queue is full" << endl;
        return;
    }

    t->data = x;
    t->next = NULL;
    t->prev = rear;

    if (rear == NULL) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

int deleteAtFront() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    int x = front->data;
    Node* p = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    delete p;
    return x;
}

int deleteAtRear() {
    if (rear == NULL) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    int x = rear->data;
    Node* p = rear;

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }

    delete p;
    return x;
}

void display() {
    Node* p = front;
    cout << "Deque: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    insertAtFront(10);
    insertAtFront(20);
    insertAtRear(30);
    insertAtRear(40);

    display();

    cout << "Deleted from front: " << deleteAtFront() << endl;
    cout << "Deleted from rear: " << deleteAtRear() << endl;

    display();

    return 0;
}
