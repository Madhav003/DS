#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    int pow;
    struct node* next;
};

void add_beg(struct node*& head, int newdata) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newdata;
    newNode->next = head;
    head = newNode;
}

void givepow(struct node*& head, int pow){

    for(int i=0; i<= pow; i++){
        add_beg(head, 0);
        head->pow = i;
    }
}

void print(struct node* head) {
    struct node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("Null");
}


int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    int pow1, pow2;
    printf("Enter degree of eq1: ");
    scanf("%d", &pow1);
    printf("Enter degree for eq2: ");
    scanf("%d", &pow2);
    givepow(head1, pow1);
    givepow(head2, pow2);
    int val;
    struct node* temp1 = head1;
    for(int i=0; i<=pow1; i++){
        printf("Enter coefficient for x^(%d): ", i);
        scanf("%d", &val);
        temp1->data = val;
        temp1 = temp1->next;
    }
    
    struct node* temp2 = head2;
    for(int i=0; i<=pow2; i++){
        printf("Enter coefficient for x^(%d): ", i);
        scanf("%d", &val);
        temp2->data = val;
        temp2 = temp2->next;
    }
    if(pow1 > pow2 || pow1 == pow2) {
        givepow(head3, pow1);
    }
    else {
        givepow(head3, pow2);
    }
    struct node* result = NULL;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    while (ptr1 != NULL || ptr2 != NULL) {
        int sum = 0;
        if (ptr1 != NULL) {
            sum += ptr1->data;
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL) {
            sum += ptr2->data;
            ptr2 = ptr2->next;
        }
        add_beg(result, sum);
    }

    print(result);
}