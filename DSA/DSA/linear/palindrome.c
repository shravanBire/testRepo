#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node* link;
};

struct node* create(){
    struct node *cur,*new,*head=NULL;
    int a;
    printf("enter number of nodes:-");
    scanf("%d",&a);
    for (int i=0;i<a;i++){
        char b;
        printf("\nEnter data:-");
        scanf(" %c",&b); //added white space
        new=malloc(sizeof(struct node));
        new->data=b;
        new->link=NULL;
        if(head==NULL){
            head=new;
        }
        else{
            cur->link=new;
        }
        cur=new;
    }
    return head;
}

void show(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("\nEmpty");
        return;
    }
    while(temp!=NULL){
        printf("%c ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

struct node *middle(struct node *head){
    struct node *mid=head,*end=head;
    int a=1;
    while(end->link!=NULL){
        mid=mid->link;
        for(int i=0;i<a*2;i++){
            end=end->link;
            if(end->link==NULL){
                break;
            }
        }
        a++;
    }
    return mid;
}

struct node* newll(struct node *head){
    struct node *mid=middle(head);
    struct node *pre=mid,*cur=mid->link,*next=cur->link;
    pre->link=NULL;
    pre=NULL;
    while(cur->link!=NULL){
        cur->link=pre;
        pre=cur;
        cur=next;
        next=next->link;
    }
    cur->link=pre;
    return cur;
}

int pali(struct node *head){
    struct node *temp=head,*new=newll(head);
    int a=0;
    while(new!=NULL){
        if(temp->data != new->data){
            a=1;
            break;
        }
        temp=temp->link;
        new=new->link;
    }
    return a;
}

void main(){
    struct node *head;
    head=create();
    show(head);

    if(pali(head)==0){
        printf("True");
    }
    else{
        printf("False");
    }
}