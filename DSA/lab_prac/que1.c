#include <stdio.h>
#include<stdlib.h>

struct node{
    int cof;
    int pow;
    struct node* next;
};

struct node* create(int coff,int power,struct node* tail){
    struct node* new=malloc(sizeof(struct node));
    new->cof=coff;
    new->pow=power;
    if(tail==NULL){
        new->next=new;
        tail=new;
        return tail;
    }
    else if((tail->next->pow) >= power){
        new->next=tail->next;
        tail->next=new;
        return tail;
    }
    else{
        struct node* temp=tail->next;
        while(temp!=tail && (temp->next->pow) < power){
            temp=temp->next;
        }
        if(temp==tail){
            new->next=tail->next;
            tail->next=new;
            tail=new;
            return tail;
        }
        else{
            new->next=temp->next;
            temp->next=new;
        }
    }
    return tail;

}

struct node* addition(struct node* tail1,struct node*tail2){
    struct node* tail3=NULL;
    struct node* temp1=tail1->next;
    struct node* temp2=tail2->next;
    do{
        if((temp1->pow)>(temp2->pow)){
            tail3=create((temp1->cof),(temp1->pow),tail3);
            temp1=temp1->next;
        }
        else if((temp1->pow)<(temp2->pow)){
            tail3=create((temp2->cof),(temp2->pow),tail3);
            temp2=temp2->next;
        }
        else{
            tail3=create((temp1->cof)+(temp2->cof),(temp1->pow),tail3);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }while(temp1!=tail1->next && temp2!=tail2->next);

    return tail3;
}

void show(struct node* tail) {
    struct node* temp = tail->next;
    do {
        printf("%dx^%d ", temp->cof,temp->pow);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

void main(){
    struct node* tail1 = NULL;
    struct node* tail2 = NULL;
    struct node* tail3=NULL;

    tail1=create(1,3,tail1);
    tail1=create(1,2,tail1);
    tail1=create(1,4,tail1);
    tail1=create(1,1,tail1);
    show(tail1);

    tail2=create(4,3,tail2);
    tail2=create(1,2,tail2);
    tail2=create(6,4,tail2);
    tail2=create(1,1,tail2);
    show(tail2);

    tail3=addition(tail1,tail2);
    show(tail3);
}