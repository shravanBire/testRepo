#include<stdio.h>
#include<string.h>
#define size 10
char stack[size];
int top=-1;
void pop(char a){
    if(int(stack[top])==int(a)+1||int(stack[top])==int(a)+2){
        top--;
    }
}
void push(char arr[]){
    int n=strlen(arr);
    for(int i=0;i<n;i++){
        if(arr[i]=='{'||arr[i]=='('||arr[i]=='['){
            top++;
            stack[top]=arr[i];
        }
        if(arr[i]=='}'||arr[i]==')'||arr[i]==']'){
            pop();
        }
    }
}
void main(){
    char arr[10];
    printf("Enter:-");
    gets(arr);
    printf("%d",top);
    push(arr);
    printf("%d",top);
    if(top==-1){
        printf("Balanced");
    }
    else{
        printf("Unbalanced");
    }
}