#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
    void insert(node* root,int val) {
        if(root == nullptr) {
            root = new node(val);
            return;
        }
        else if( root->left == nullptr ) {
            root->left = new node(val);
            return;
        }
        else if( root->right == nullptr ) {
            root->right = new node(val);
            return;
        }
        else {
            node* temp = root->left;
            while(temp->left != nullptr) {
                if(temp->right != nullptr){
                    temp->right = new node(val);
                    return;
                }
                temp = temp->left;
            }
            temp->left = new node(val);
            return;
        }
    }
    int display(){
        //display the tree in inorder
        if(this == nullptr) return -1;
        if(this->left != nullptr) this->left->display();
        cout << this->data << " ";
        if(this->right != nullptr) this->right->display();
        return 0;
    }
};

int main(){
    node* root = nullptr;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        root->insert(root,val);
    }
    return 0;
}

