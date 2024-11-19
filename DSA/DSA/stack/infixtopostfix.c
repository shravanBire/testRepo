#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;

struct node {
    char data;
    struct node* link;
};

struct node* push(struct node* head,char a){
    struct node* new=malloc(sizeof(struct node));
    new->data=a;
    new->link=head;
    head=new;
    top++;
    return head;
}

struct node* pop(struct node* head){
    if(top==-1){
        printf("underflow");
        return head;
    }
    printf("%c",head->data);
    head=head->link;
    top--;
    return head;
}

void empty(struct node *head){
    struct node *temp=head;
    while(temp->link!=NULL){
        printf("%c",temp->data);
        temp=temp->link;
    }
}

int precendence(char a){
    if(a=='-'||a=='+'){
        return 1;
    }
    else if(a=='*'||a=='/'){
        return 2;
    }
    else if(a=='^'){
        return 3;
    }
    else{
        return -1;
    }
}

struct node* inToPost(struct node* head,char arr[]){
    int len=9;
    for(int i=0;i<len;i++){
        if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z')){
            printf("%c",arr[i]);
            continue;
        }
        if(precendence(head->data)<precendence(arr[i])){
            head=push(head,arr[i]);
            continue;
        }
        if(precendence(head->data)==precendence(arr[i])){
            head=pop(head);
            head=push(head,arr[i]);
            continue;
        }
        if(precendence(head->data)>precendence(arr[i])){
            while(precendence(head->data)<=precendence(arr[i])){
                head=pop(head);
            }
            head=pop(head);
            head=pop(head);
            head=push(head,arr[i]);
            continue;
        }
        if(arr[i]=='('||arr[i]=='{'||arr[i]=='['){
            head=push(head,arr[i]);
            continue;
        }
        if(arr[i]==')'||arr[i]=='}'||arr[i]=='}'){
            while(head->data!='('||head->data!='{'||head->data!='['){
                head=pop(head);
            }
            head=head->link;
            continue;
        }
    }
    empty(head);
    return head;
}

int main(){
    struct node* head=malloc(sizeof(struct node));
    head->data='0';
    head->link=NULL;
    char arr[9]="a*b+c*d+e";
    head=inToPost(head,arr);
    
}