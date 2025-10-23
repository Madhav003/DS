//a.	Write a program to implement phone book dictionary using Binary Search Tree which provides following operations: 
//(a) Add new entry in phone book, (b) Remove entry from phone book, (c) Search phone number
// (d) List all entries in ascending order of name and (e) List all entries in descending order of name.

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

void add(node*&root, string n, int nu) {
    node* temp = new node;
    temp->name = n;
    temp->num = nu;

    if (root == nullptr) {
        root = temp;
        return;
    }

    node* tr = root;
    while (true) {
        if (n < tr->name) {
            if (tr->leftc == nullptr) {
                tr->leftc = temp;
                break;
            } else {
                tr = tr->leftc;
            }
        }


    }
}
void search(node*&root, string sea){
    node* tr = root;
    
}

int main(){
node* root = new node;

    return 0;
}