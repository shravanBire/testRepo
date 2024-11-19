#include<stdio.h>
#include<stdlib.h>

int arr[3][3]={{1,0,0},{0,1,0},{0,0,1}};

struct node{
    int row;
    int col;
    int data;
    struct node* next;
};

struct node* create(struct node* head,int data,int roww,int column){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->row=roww;
    newnode->col=column;
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return head;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

struct node* sparse(struct node* head){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==0){
                continue;
            }
            else{
                head=create(head,arr[i][j],i,j);
            }
        }
    }
    return head;
}

void show(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d-%d-%d ",temp->row,temp->col,temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main(){
    struct node* head = NULL;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
        printf("\n");
    }

    head=sparse(head);
    show(head);
}