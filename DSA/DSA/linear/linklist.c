#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node* midinsert(struct node *head,int pos,int a){
    struct node* ptr1=malloc(sizeof(struct node));
    ptr1->data=a;
    ptr1->link=NULL;
    struct node* ptr2=head;
    pos=pos-2;
    while(pos!=0){
        ptr2=ptr2->link;
        pos--;
    }
    ptr1->link=ptr2->link;
    ptr2->link=ptr1;
    return head;

}

struct node* startinsert(struct node* head,int a){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->link=head;
    head=temp;
    return head;
}

void endinsert(struct node *head,int a){
    struct node *ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->link=NULL;
    ptr->link=temp;
}

void count(struct node *head){
    int count=0;
    if(head==NULL){
        printf("empty");
        return;
    }
    struct node *ptr=head;
    while(ptr != NULL){
        ++count;
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n%d\n",count);
}

void main(){
    
    struct node *cur;
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    cur=head;

    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=46;
    current->link=NULL;
    cur->link=current;
    cur=cur->link;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=47;
    current->link=NULL;
    cur->link=current;
    cur=cur->link;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=49;
    current->link=NULL;
    cur->link=current;
    cur=cur->link;


    count(head);
    endinsert(head,50);
    count(head);
    head=startinsert(head,44);
    count(head);
    head=midinsert(head,5,48);
    count(head);
    
}