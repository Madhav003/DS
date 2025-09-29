// /C:/VSCode stuff/ds/exp3/exp3a.cpp
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    int data[MAX_SIZE];
    int top;
    Stack() : top(-1) {}
};

bool push(Stack &s, int value) {
    if (s.top >= MAX_SIZE - 1) {
        cout << "Error - stack overflow ;)\n";
        return false;
    }
    s.data[++s.top] = value;
    return true;
}

bool pop(Stack &s, int &out) {
    if (s.top < 0) {
        cout << "Error - stack underflow\n";
        return false;
    }
    out = s.data[s.top--];
    return true;
}

bool peek(const Stack &s, int &out) {
    if (s.top < 0) {
        cout << "Stack is empty\n";
        return false;
    }
    out = s.data[s.top];
    return true;
}

void printStack(const Stack &s) {
    if (s.top < 0) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top -> ";
    for (int i = s.top; i >= 0; --i) {
        cout << s.data[i];
        if (i > 0) cout << " | ";
    }
    cout << "\n";
}

int main() {
    Stack st;
    int choice;
    while (true) {
        cout << "\nChoose an operation:\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Peek (top)\n"
             << "4. Print stack\n"
             << "5. Exit\n"
             << "Enter choice: ";
        if (!(cin >> choice)) break;

        if (choice == 1) {
            int x;
            cout << "Enter integer to push: ";
            cin >> x;
            push(st, x);
        } else if (choice == 2) {
            int val;
            if (pop(st, val)) cout << "Popped: " << val << "\n";
        } else if (choice == 3) {
            int val;
            if (peek(st, val)) cout << "Top: " << val << "\n";
        } else if (choice == 4) {
            printStack(st);
        } else if (choice == 5) {
            cout << "Exiting.\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}