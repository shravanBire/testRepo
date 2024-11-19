#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* arr[10];
void clear(){
    for(int i=0;i<10;i++){
        arr[i]=NULL;
    }
}

struct node* create(struct node* head,int dta){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=dta;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}

void sort(struct node* head,int exp){
    struct node* temp=head;
    while(temp!=NULL){
        int i=temp->data;
        int place=(i/exp)%10;
        arr[place]=create(arr[place],i);
        temp=temp->next;
    }
}

struct node* joining(struct node* new){
    for(int i=0;i<10;i++){
        if(arr[i]==NULL){
            continue;
        }
        struct node* temp=arr[i];
        while(temp!=NULL){
            new=create(new,temp->data);
            temp=temp->next;
        }
    }
    return new;
}

void show(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main(){
    clear();
    struct node* head=NULL;
    struct node* new=NULL;

    head=create(head,931);
    head=create(head,384);
    head=create(head,294);
    head=create(head,741);
    head=create(head,482);
    head=create(head,675);
    show(head);
    printf("\n");

    for(int i=1;i<=100;i*=10){
        sort(head,i);
        new=joining(new);
        show(new);
        clear();
        head=new;
        new=NULL;
    }

}