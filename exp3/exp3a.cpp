#include <iostream>
using namespace std;

const int MAX = 100;

struct Stack {
    int arr[MAX], top = -1;
};

void push(Stack &s, int x) {
    if (s.top == MAX - 1) cout << "Overflow\n";
    else s.arr[++s.top] = x;
}

void pop(Stack &s) {
    if (s.top == -1) cout << "Underflow\n";
    else cout << "Popped: " << s.arr[s.top--] << "\n";
}

void peek(const Stack &s) {
    if (s.top == -1) cout << "Empty\n";
    else cout << "Top: " << s.arr[s.top] << "\n";
}

void print(const Stack &s) {
    if (s.top == -1) cout << "Empty\n";
    else for (int i = s.top; i >= 0; --i) cout << s.arr[i] << (i ? " " : "\n");
}

int main() {
    Stack s;
    int c, x;
    while (cin >> c && c != 5) {
        if (c == 1) { cin >> x; push(s, x); }
        else if (c == 2) pop(s);
        else if (c == 3) peek(s);
        else if (c == 4) print(s);
        else cout << "Invalid\n";
    }
}
