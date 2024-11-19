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

int circcheck(struct node* tail){
    struct node* cur=tail->next;
    while(0<1){
        if(cur==tail){
            return 1;
        }
        if(cur==NULL){
            return 0;
        }
        cur=cur->next;
    }
}

struct node *reverse(struct node* tail){
    struct node
}

int main(){
    struct node* tail=NULL;
    tail=create();
    show(tail);
    sort(tail);
    show(tail);
    return 0;
}