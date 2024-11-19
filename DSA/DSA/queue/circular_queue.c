#include<stdio.h>
#include<stdlib.h>

int arr[5];
int frount=-1;
int last=-1;

void display(){
    for(int i=frount;i<=last;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
} 

void enqueue(int data){
    if(last==5){
        printf("queue overflow\n");
        return;
    }
    if(frount==-1){
        ++frount;
        ++last;
        arr[last]=data;
    }
    else{
        ++last;
        arr[last]=data;
    }
}

void dequeue(){
    if(frount>last){
        frount=last=-1;
        printf("queue underflow\n");
    }
    else{
        ++frount;
    }
}

void main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
}