#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = nullptr;
    }

    void insert(node*& root, int val) {
        if (root == nullptr) {
            root = new node(val);
            return;
        }
        if (val < root->data)
            insert(root->left, val);
        else
            insert(root->right, val);
    }

    void display(node* root) { //inorder
        if (root == nullptr)
            return;

        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
};

int main() {
    node* root = nullptr;
    node tree(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(root, val);
    }

    tree.display(root);
    cout << endl;

    return 0;
}
