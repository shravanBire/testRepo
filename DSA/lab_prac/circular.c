#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(struct node* tail, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    
    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;  
        tail->next = newNode;       
        tail = newNode;              
    }
    return tail;
}

void show(struct node* tail) {
    struct node* temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

void main() {
    struct node* tail = NULL;
    
    tail = create(tail, 1);
    tail = create(tail, 2);
    tail = create(tail, 3);
    
    show(tail);
}
