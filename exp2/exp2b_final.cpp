#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    int powx;
    int powy;
    struct node* next;
};

void add_end(struct node** head, int newdata, int xpow, int ypow) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = newdata;
    newnode->powx = xpow;
    newnode->powy = ypow;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void display(struct node* head) {
    struct node* cur = head;
    if(cur == NULL) {
        printf("Empty polynomial\n");
        return;
    }
    while (cur != NULL) {
        printf("%d x^%d y^%d", cur->data, cur->powx, cur->powy);
        if(cur->next != NULL) printf(" + ");
        cur = cur->next;
    }
    printf("\n");
}

void add_poly(struct node* head1, struct node* head2, struct node** head3) {
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 != NULL) {
        add_end(head3, temp1->data, temp1->powx, temp1->powy);
        temp1 = temp1->next;
    }
    temp2 = head2;
    while (temp2 != NULL) {
        struct node* cur = *head3;
        int found = 0;
        while (cur != NULL) {
            if (cur->powx == temp2->powx && cur->powy == temp2->powy) {
                cur->data += temp2->data;
                found = 1;
                break;
            }
            cur = cur->next;
        }
        if (!found) {
            add_end(head3, temp2->data, temp2->powx, temp2->powy);
        }
        temp2 = temp2->next;
    }
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;

    add_end(&head1, 3, 2, 1);
    add_end(&head1, -5, -1, 0);

    add_end(&head2, 4, 2, 1);
    add_end(&head2, 2, 0, 2);
    add_end(&head2, 7, 1, 0);

    printf("Polynomial 1:\n");
    display(head1);

    printf("Polynomial 2:\n");
    display(head2);

    add_poly(head1, head2, &head3);

    printf("Sum Polynomial:\n");
    display(head3);

    return 0;
}
