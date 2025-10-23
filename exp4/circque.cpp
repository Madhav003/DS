#include <iostream>
using namespace std;

class Queue {
    public:
    Queue* next;
    int val;
};
void add(Queue*&tail, int x){
    Queue* temp = new Queue;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    
}


int main(){
    Queue* head = new Queue;
    Queue* tail = head;

}