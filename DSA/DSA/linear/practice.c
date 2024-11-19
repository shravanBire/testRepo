#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* createll(struct node* head,int dta){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=dta;
    newnode->link=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }
    return head;
}

struct node* create(){
    int a;
    printf("ENTER NUMBER OF ELEMENT:-");
    scanf("%d",&a);
    struct node *head=NULL;
    struct node *cur;
    for(int i=0;i<a;i++){
        int b;
        printf("\nENTER DATA:-");
        scanf("%d",&b);
        struct node* new=malloc(sizeof(struct node));
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
        printf("\nList is empty");
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void middle_list(struct node *head){
    struct node *start=head;
    struct node *end=head;
    int i=1;
    while(end->link!=NULL){
        start=start->link;
        for(int j=1;j<i*2;j++){
            if(end->link==NULL){
                break;
            }
            else{
                end=end->link;
            }
        }
        i++;
    }
    printf("\n%d",start->data);
}

struct node *reverse_list(struct node *head){
    struct node *prev=NULL;
    struct node *next=head->link;
    struct node *cur=head;
    while(cur->link!=NULL){
        cur->link=prev;
        prev=cur;
        cur=next;
        next=next->link;
    }
    cur->link=prev;
    head=cur;
    return(head);
}

struct node *rotate_list(struct node *head,int pos){
    struct node *joint=head;
    while(pos!=1){
        head=head->link;
        pos--;
    }
    struct node *end=head;
    head=head->link;
    struct node *cur=head;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=joint;
    end->link=NULL;
    return(head);
}

struct node *nthend(struct node *head,int pos){
    struct node *guard=head;
    struct node *ele=head;
    while(pos != 1){
        guard=guard->link;
        pos--;
    }
    while(guard->link!=NULL){
        ele=ele->link;
        guard=guard->link;
    }
    return(ele);
}//printf("%d",nthend(head,2)->data);

void duplicate(struct node *head){
    struct node *temp=head;
    struct node *cur=head;
    struct node *temp2;
    while(temp!=NULL){
        int a=temp->data;
        temp2=cur->link;
        if(a==temp2->data){
            cur->link=cur->link->link;
            if(a==cur->link->data){
                continue;
            }
        }
        temp=temp->link;
        cur=cur->link;
    }
}

void nafterm(struct node *head,int m,int n){
    struct node *temp=head;
    int a=1,b=0;
    while(temp!=NULL){
        if(a!=m){
            temp=temp->link;
            a++;
            continue;
        }
        if(b!=n){
            temp->link=temp->link->link;
            b++;
            continue;
        }
        temp=temp->link;
        a=1;
        b=0;
    }

}

struct node* pairswap(struct node *head){
    struct node *temp,*prev=head,*next=head->link;
    while(next!=NULL){
        if(prev==head){
            prev->link=next->link;
            next->link=prev;
            head=next;
            temp=prev;
            prev=prev->link;
            next=prev->link;
        }
        else{
            prev->link=next->link;
            temp->link=next;
            next->link=prev;
            temp=prev;
            prev=prev->link;
            if(prev==NULL){
                break;
            }
            next=prev->link;
        }
    }
    return(head);
}

struct node* grprev(struct node *head,int grp){
    
}

struct node* lastoccdel(struct node* head,int a){
    struct node *note=NULL;
    struct node *temp=head->link;
    struct node *cur=head;
    while(cur->link!=NULL){
        if(temp->data==a){
            note=cur;
        }
        temp=temp->link;
        cur=cur->link;
    }
    if(head->data==a && note==NULL){
        head=head->link;
        return(head);
    }
    else{
        note->link=note->link->link;
        return(head);
    }
}

struct node* sublistrev(struct node* head,int x,int y){
    int p1=0; 
    struct node* head2=NULL;
    struct node* temp1=head; 
    while(p1!=(x-1)){
        temp1=temp1->link;
        p1++;
    }
    struct node* temp2=temp1;
    while(p1!=y){
        temp2=temp2->link;
        p1++;
    }
    return head;
}

void main(){
    struct node *head;
    head=create(head);
    show(head);
    head=sublistrev(head,3,6);
    show(head);
}