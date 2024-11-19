#include<stdio.h>
#include<string.h>
#define size 10
char stack[size];
int top=-1;
void push(char arr[]){
    int n=strlen(arr);
    for(int i=0;i<n;i++){
        if(arr[i]=='{'){
            continue;
        }
        top++;
        stack[top]=arr[i];
    }
}
char pop(){
    while(top!=-1){
        printf("%c",stack[top]);
        top--;
    }
}
void main(){
    char arr[10];
    printf("Enter:-");
    gets(arr);
    push(arr);
    pop();
}


head=pop(head);
    head=push(head,arr[0]);
    head=push(head,arr[1]);
    head=push(head,arr[2]);
    head=push(head,arr[3]);
    head=push(head,arr[4]);
    show(head);
    head=pop(head);
    head=pop(head);
    head=pop(head);
    head=pop(head);
    head=pop(head);
    head=pop(head);