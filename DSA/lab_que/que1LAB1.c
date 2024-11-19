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

struct node* addition(struct node *added,struct node *head1,struct node *head2){
    struct node *ptr1=head1;
    struct node *ptr2=head2;

    if( (head1->exp) > (head2->exp) ){
        struct node *ptr1=head1;
        struct node *ptr2=head2;
    }
    else{
        struct node *ptr1=head2;
        struct node *ptr2=head1;
    }

    while(ptr1!=NULL){
        if(ptr1->exp > ptr2->exp){
            added=create(added,ptr1->cof,ptr1->exp);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp){
            added=create(added,ptr2->cof,ptr2->exp);
            ptr2=ptr2->next;
        }
        else{
            added=create(added,ptr1->cof+ptr2->cof,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }

    return added;
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

    added=addition(added,head1,head2);
    printlist(added);

}