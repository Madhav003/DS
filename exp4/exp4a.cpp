#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    explicit Node(int v) : data(v), next(nullptr) {}
};

class LinkedQueue {
    Node* front_;
    Node* back_;
public:
    LinkedQueue() : front_(nullptr), back_(nullptr) {}
    ~LinkedQueue() {
        while (front_) {
            Node* tmp = front_;
            front_ = front_->next;
            delete tmp;
        }
    }
    void enqueue(int data) {
        Node* node = new Node(data);
        if (!back_) {
            front_ = back_ = node;
            return;
        }
        back_->next = node;
        back_ = node;
    }
    bool dequeue(int& removed) {
        if (!front_) {
            return false;
        }
        Node* tmp = front_;
        removed = tmp->data;
        front_ = front_->next;
        if (!front_) {
            back_ = nullptr;
        }
        delete tmp;
        return true;
    }
    void display() const {
        if (!front_) {
            cout << "Queue is empty\n";
            return;
        }
        for (Node* cur = front_; cur; cur = cur->next) {
            cout << cur->data << (cur->next ? " " : "\n");
        }
    }
};

int main() {
    LinkedQueue queue;
    int choice;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ";
        if (!(cin >> choice)) {
            break;
        }
        if (choice == 1) {
            int data;
            cout << "data: ";
            if (cin >> data) {
                queue.enqueue(data);
            }
        } else if (choice == 2) {
            int removed;
            if (queue.dequeue(removed)) {
                cout << "Dequeued: " << removed << "\n";
            } else {
                cout << "Queue is empty\n";
            }
        } else if (choice == 3) {
            queue.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid option\n";
        }
    }
    return 0;
}
