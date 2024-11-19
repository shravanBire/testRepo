#include<stdio.h>
#include<stdlib.h>

struct poly{
    int coef;
    int pow;
    struct poly* next;
};

struct poly* create(int coef,int pow,struct poly* head){
    struct poly* node=malloc(sizeof(struct poly));
    node->coef=coef;
    node->pow=pow;
    node->next=NULL;
    if(head==NULL){
        head=node;
        return head;
    }
    else{
        if(head->pow <= node->pow){
            node->next=head;
            head=node;
            return head;
        }
        struct poly* cur=head;
        struct poly* prev=NULL;
        while(cur->next!=NULL){
            if(cur->pow <= node->pow){
                prev->next=node;
                node->next=cur;
                return head;
            }
            prev=cur;
            cur=cur->next;
        }
        cur->next=node;
        return head;
    }
}

struct poly* addition(struct poly* head1, struct poly* head2) {
    struct poly* head3 = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->pow > head2->pow) {
            head3 = create(head1->coef, head1->pow, head3);
            head1 = head1->next;
        } else if (head1->pow < head2->pow) {
            head3 = create(head2->coef, head2->pow, head3);
            head2 = head2->next;
        } else {
            int coef = head1->coef + head2->coef;
            head3 = create(coef, head1->pow, head3);
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        head3 = create(head1->coef, head1->pow, head3);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        head3 = create(head2->coef, head2->pow, head3);
        head2 = head2->next;
    }

    return head3;

}

struct poly* multiplication(struct poly* head1,struct poly* head2){
    struct poly* head3 = NULL;
    struct poly* tempHead2;
    while(head1!=NULL){
        tempHead2 = head2;
        while(tempHead2!=NULL){
            int coef = head1->coef * tempHead2->coef;
            int pow = head1->pow * tempHead2->pow;
            head3 = create(coef,pow,head3);
            tempHead2=tempHead2->next;
        }
        head1=head1->next;
    }
    return head3;
}

void show(struct poly* head){
    struct poly* temp=head;
    while(temp!=NULL){
        printf("%d*x^%d ",temp->coef,temp->pow);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct poly* head1 = NULL;
    head1 = create(1,5, head1);
    head1 = create(2,3, head1);

    struct poly* head2 = NULL;
    head2 = create(4,3, head2);
    head2 = create(3,2, head2);
    head2 = create(5,1, head2);

    show(head1);
    show(head2);

    struct poly* head3 =NULL;
    head3 = multiplication(head1,head2);
    show(head3);
}