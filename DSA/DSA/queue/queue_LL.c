#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int first=-1;
int last=-1;
struct node *end=NULL;
struct node *head=NULL;

void enqueue(int d){
    struct node *new=malloc(sizeof(struct node));
    new->data=d;
    new->next=NULL;
    if(head==NULL){
        head=new;
        ++first;
        ++last;
        end=head;
    }
    else{
        end->next=new;
        ++last;
        end=new;
    }
}

void dequeue(){
    if(first>last){
        first=last=-1;
        printf("queue undeflow");
    }
    else{
        struct node *fre=head;
        head=head->next;
        free(fre);
        fre=NULL;
        ++first;
    }
}

void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
}