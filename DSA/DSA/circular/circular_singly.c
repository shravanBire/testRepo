#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(){
    struct node* tail=NULL;
    int a;
    printf("enter number of node:-");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int b;
        printf("enter data:-");
        scanf("%d",&b);
        struct node* temp=malloc(sizeof(struct node));
        temp->data=b;
        temp->next=NULL;
        if(tail==NULL){
            tail=temp;
            tail->next=tail;
        }
        else{
            temp->next=tail->next;
            tail->next=temp;
            tail=tail->next;
        }
    }
    return(tail);  
}

void addbeg(struct node* tail){
    struct node* new=malloc(sizeof(struct node));
    int a;
    printf("enter data:-");
    scanf("%d",&a);
    new->data=a;
    new->next=tail->next;
    tail->next=new;

}

struct node* addend(struct node* tail){
    struct node* new=malloc(sizeof(struct node));
    int a;
    printf("enter data:-");
    scanf("%d",&a);
    new->data=a;
    new->next=tail->next;
    tail->next=new;
    tail=tail->next;
    return(tail);
}

void addmid(struct node* tail,int pos){
    struct node* cur=tail->next;
    struct node* new=malloc(sizeof(struct node));
    int a;
    printf("enter data:-");
    scanf("%d",&a);
    new->data=a;
    new->next=NULL;
    while(pos!=2){
        cur=cur->next;
        pos--;
    }
    new->next=cur->next;
    cur->next=new;
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

struct node* reverse(struct node* tail){
    struct node* head=tail->next;
    struct node* pre=head;
    struct node* cur=head->next;
    struct node* nex=cur->next;
    while(pre!=tail){
        cur->next=pre;
        pre=cur;
        cur=nex;
        nex=nex->next;
    }
    head->next=tail;
    return head;
}

struct node* middle(struct node* tail) {
    struct node *first = tail->next;
    struct node *second = tail->next;
    while (second != tail && second->next != tail) {
        first = first->next;
        second = second->next->next;
    }
    return first;
}

struct node* palirev(struct node* first,struct node* tail){
    struct node* cur=first->next;
    struct node* nex=cur->next;
    while(first!=tail){
        cur->next=first;
        first=cur;
        cur=nex;
        nex=nex->next;
    }
    return first;
}
int palindraome(struct node* tail){    //problem
    struct node* head1=tail->next;
    struct node* mid=middle(tail);
    struct node* head2=palirev(mid,tail);
    while(head1!=mid&&head2!=mid){
        if((head1->data)!=(head2->data)){
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return 1;
}

int intersection(struct node* tail1,struct node* tail2){
    struct node* cur1=tail1->next;
    struct node* cur2=tail2->next;
    while(cur1!=tail1){
        if(cur1==cur2){
            return 1;
        }
        cur1=cur1->next;
    }
    cur1=tail1->next;
    while(cur2!=tail2){
        if(cur2==cur1){
            return 1;
        }
        cur2=cur2->next;
    }
    return 0;
}

struct node* insertInSort(struct node* tail,int ele){
    struct node* head=tail->next;
    struct node* new=malloc(sizeof(struct node));
    new->data=ele;
    new->next=NULL;
    if(ele<head->data){
        new->next=head;
        tail->next=new;
        return tail;
    }
    else if(tail->data<ele){
        tail->next=new;
        new->next=head;
        tail=tail->next;
        return tail;
    }
    else{
        struct node* pre=head;
        head=head->next;
        while(head!=tail){
            if(ele>(pre->data)&&ele<(head->data)){
                pre->next=new;
                new->next=head;
                return tail;
            }
            head=head->next;
            pre=pre->next;
        }
    }
}

int main(){
    struct node *tail=NULL;
    tail=create();
    show(tail);
    tail=insertInSort(tail,4);
    show(tail);
}