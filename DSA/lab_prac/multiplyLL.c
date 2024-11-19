#include<stdio.h>
#include<stdlib.h>

struct node{
    int cof;
    int exp;
    struct node* next;
};

struct node* create(struct node *head,int valueCof,int valueExp){
    struct node *new = malloc(sizeof(struct node));

    new->cof = valueCof;
    new->exp = valueExp;
    new->next = NULL;

    if(head==NULL || head->exp <= valueExp){
        new->next = head;
        head = new;
        return(head);
    }

    struct node* temp=head;
    while(temp->next!=NULL && temp->next->exp > valueExp){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;

    return(head);
}

void printlist(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%dx^%d  ",temp->cof,temp->exp);
        temp=temp->next;
    }
    printf("\n");
}


void main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *added=NULL;

    // head1=create(head1,1,1);
    // head1=create(head1,1,2);
    // head1=create(head1,1,3);
    // printlist(head1);

    // head2=create(head2,1,1);
    // head2=create(head2,1,2);
    // head2=create(head2,1,3);
    // printlist(head2);

    // added=addition(added,head1,head2);
    // printlist(added);






    // head1=create(head1,1,1);
    // head1=create(head1,1,2);
    // head1=create(head1,1,4);2
    // printlist(head1);

    // head2=create(head2,1,2);
    // head2=create(head2,1,1);
    // head2=create(head2,1,3);
    // printlist(head2); 

    // added=addition(added,head1,head2);
    // printlist(added);





    head1=create(head1,1,1);
    head1=create(head1,1,2);
    head1=create(head1,1,4);
    printlist(head1);

    head2=create(head2,1,1);
    head2=create(head2,1,3);
    head2=create(head2,1,2);
    head2=create(head2,1,5);
    printlist(head2);


}