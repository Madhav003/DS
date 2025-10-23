// b.	Write a simple program to construct a binary tree from the given preorder and inorder traversal sequence.
#include<iostream>
#include <string>
using namespace std;

class node{
    public:
    string name;
    int num;
    node* leftc;
    node* rightc;
};

node* constructTree(string preorder, string inorder) {
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    // The first element in the preorder sequence is the root
    char rootValue = preorder[0];
    node* root = new node();
    root->name = rootValue;

    // Find the root in the inorder sequence
    size_t rootIndex = inorder.find(rootValue);
    if (rootIndex == string::npos) {
        cerr << "Invalid input: root not found in inorder sequence." << endl;
        delete root;
        return nullptr;
    }

    // Construct the left and right subtrees
    string leftInorder = inorder.substr(0, rootIndex);
    string rightInorder = inorder.substr(rootIndex + 1);
    string leftPreorder = preorder.substr(1, leftInorder.length());
    string rightPreorder = preorder.substr(1 + leftInorder.length());

    root->leftc = constructTree(leftPreorder, leftInorder);
    root->rightc = constructTree(rightPreorder, rightInorder);

    return root;
}
int main(){
    
}