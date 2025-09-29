#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void addbeg(struct node*& head, int newdata) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newdata;
    newNode->next = head;
    head = newNode;


}
void addend(struct node*& head, int newdata) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = newdata;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void del(struct node*& head, int deldat){
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty.");
    }
    while(temp->next->data != deldat){
        temp = temp -> next;   
    }
    struct node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void print(struct node* head) {
    struct node* temp = head;
    while(temp ->next != NULL){
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("Null");
}

void search( struct node*& head, int tofind){
    struct node* temp = head;
    int i =0;
    while(temp->data != tofind && temp != NULL){
        temp = temp -> next;
        i++;
        if(temp == NULL){
            printf("The integer %d is not found in the list.", tofind);
            return;
        }
    }

    printf("The integer %d is at position: %d", tofind , i+1);

}

int main() {
    struct node* head = NULL;
    int flag = 0;
    int choice = 0;
    while(flag == 0){
        printf("What would you like to do: \n 1. Add node at head \n 2.Add node at tail \n 3.Delete specific node \n 4.Print the linked list \n 5.Search position of an integer. \n --> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            int num;
            printf("Enter integer to add: ");
            scanf("%d", &num);
            addbeg(head, num);
            break;
            case 2:
            int num2;
            printf("Enter integer to add: ");
            scanf("%d", &num2);
            addend(head, num2);
            break;
            case 3:
            int num3;
            printf("Enter integer to delete: ");
            scanf("%d", &num3);
            del(head, num3);
            break;
            case 4:
            print(head);
            printf("\n");
            break;
            case 5:
            int num4;
            printf("Enter integer to search: ");
            scanf("%d", &num4);
            search(head, num4);
            break;
            default:
            printf("Invalid input.");
        }
    }

    /*
    addend(head, 10);
    addend(head, 20);
    addend(head, 30);
    addbeg(head, 55);
    print(head);
    del(head, 10);
    printf("\n");
    print(head);
    printf("\n");
    search(head, 20);
    */

    return 0;
}