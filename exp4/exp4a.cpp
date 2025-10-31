#include <iostream>
using namespace std;

class Queue {
public:
    int data;
    Queue* next;
} *front = NULL, *rear = NULL;

void enqueue(int x) {
    Queue* t = new Queue;
    if (t == NULL) {
        cout << "Queue is full" << endl;
        return;
    }

    t->data = x;
    t->next = NULL;

    if (front == NULL) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }  
}

int dequeue() {
    int x = -1;
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return x;
    }

    Queue* p = front;
    x = p->data;
    front = front->next;
    delete p;

    if (front == NULL)
        rear = NULL;

    return x;
}

void display() {
    Queue* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue contents: ";
    display();

    cout << "Dequeued: " << dequeue() << endl;

    cout << "Queue after dequeue: ";
    display();

    return 0;
}
