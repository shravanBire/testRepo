#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* create(){
    struct node* tail=NULL;
    struct node* first;
    int a;
    printf("enter number of node:-");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int b;
        printf("enter data:-");
        scanf("%d",&b);
        struct node* new=malloc(sizeof(struct node));
        new->data=b;
        new->prev=NULL;
        new->next=NULL;
        if(tail==NULL){
            tail=new;
            tail->next=tail;
            tail->prev=tail;
            first=tail;
        }
        else{
            tail->next=new;
            new->prev=tail;
            new->next=first;
            first->prev=new;
            tail=tail->next;
        }
    }
    return tail;    
}



void show(struct node *tail){
    struct node *cur=tail->next;
    if(tail==NULL){
        printf("No node present\n");
        return;
    }
    do{
        printf("%d ",cur->data);
        cur=cur->next;
    }while(cur!=tail->next);
    printf("\n");
}

int main(){
    struct node* tail=NULL;
    tail=create();
    show(tail);
    printf("\n%d",tail->prev->prev->data);
    return 0;
}