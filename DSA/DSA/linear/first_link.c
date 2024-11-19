#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* insertmid(struct node *head,int pos){
    int dta;
    struct node *temp=head;
    printf("\nEnter element:-");
    scanf("%d",&dta);
    if(head==NULL){
        head=malloc(sizeof(struct node));
        head->data=dta;
        head->link=NULL;
    }
    else{
        while(pos != 2){
            temp=temp->link;
            pos--;
        }
        struct node *ele=malloc(sizeof(struct node));
        ele->data=dta;
        ele->link=temp->link;
        temp->link=ele;

    }
    return head;
}

struct node* insertfrount(struct node *head){
    int dta;
    struct node *temp=head;
    printf("\nEnter element:-");
    scanf("%d",&dta);
    if(head==NULL){
        head=malloc(sizeof(struct node));
        head->data=dta;
        head->link=NULL;
    }
    else{
        struct node *ele=malloc(sizeof(struct node));
        ele->data=dta;
        ele->link=head;
        head=ele; 
    }
    return head;
}

struct node* insertend(struct node *head){
    int dta;
    struct node *temp=head;
    printf("\nEnter element:-");
    scanf("%d",&dta);
    if(head==NULL){
        head=malloc(sizeof(struct node));
        head->data=dta;
        head->link=NULL;
    }
    else{
        while(temp->link !=  NULL){
            temp=temp->link;
        }
        struct node *ele=malloc(sizeof(struct node));
        ele->data=dta;
        ele->link=NULL;
        temp->link=ele;
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

void deletemid(struct node *head,int pos){
    struct node *temp=head;
    while(pos >= 3){
        temp=temp->link;
        pos--;
    }
    struct node *efree=temp->link;
    temp->link=temp->link->link;
    free(efree);
}

struct node* deletefrount(struct node *head){
    struct node *temp=head;
    head=head->link;
    free(temp);
    return head;
}

void deleteend(struct node *head){
    struct node *temp=head;
    while(temp->link->link != NULL){
        temp=temp->link;
    }
    free(temp->link->link);
    temp->link=NULL;
}

void main(){
    struct node *head=NULL;

    while(1){
        int choice;
        printf("\n1.insert in end\n2.insert in frount\n3.insert in mid\n4.delete in end\n5.delete in frount\n6.delete in mid\n7.sort\n8.print\n9.exit");
        printf("\nEnter choice:- ");
        scanf("%d",&choice);
        if(choice==1){
            head=insertend(head);
        }
        else if(choice==2){
            head=insertfrount(head);
        }
        else if(choice==3){
            int pos;
            printf("\nEnter position:-");
            scanf("%d",&pos);
            head=insertmid(head,pos);
            
        }
        else if(choice==4){
            deleteend(head);
        }
        else if(choice==5){
            head=deletefrount(head);
        }
        else if(choice==6){
            int pos;
            printf("\nEnter position:-");
            scanf("%d",&pos);
            deletemid(head,pos);
        }
        else if(choice==7){
            continue;
        }
        else if(choice==8){
            show(head);
        }
        else if(choice==9){
            break;
        }
        else{
            printf("\ninvalid choice");
        }
    }
}