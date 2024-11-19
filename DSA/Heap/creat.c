#include <stdio.h>

#define MAX 100

int heap[MAX];
int size;

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

//choose lasgest from left
//choose largest from right
//if largest==index terminate
void MAXhepify(int index,int n){
    int c_left=2*index+1;
    int c_right=2*index+2;
    int largest=index;
    if(c_left < n && heap[c_left]>heap[largest]){
        largest=c_left;
    }
    if(c_right < n && heap[c_right]>heap[largest]){
        largest=c_right;
    }
    if(largest!=index){
        swap(&heap[index],&heap[largest]);
        MAXhepify(largest,n);
    }
    return;
}

void MINhepify(int index,int n){
    int c_left=2*index+1;
    int c_right=2*index+2;
    int smallest=index;
    if(c_left < n && heap[c_left]<heap[smallest]){
        smallest=c_left;
    }
    if(c_right < n && heap[c_right]<heap[smallest]){
        smallest=c_right;
    }
    if(smallest!=index){
        swap(&heap[index],&heap[smallest]);
        MINhepify(smallest,n);
    }
    return;
}

void buildHeap(int arr[],int length,int choice){
    size=length;
    for(int i=0;i<size;i++){
        heap[i]=arr[i];
    }
    if (choice==1){
        for(int i=(size/2)-1;i>=0;i--){
            MAXhepify(i,size);
        }
    }
    else{
        for(int i=(size/2)-1;i>=0;i--){
            MINhepify(i,size);
        }
    }
}

int extractMAX(){
    int max=heap[0];
    heap[0]=heap[size-1];
    size--;
    MAXhepify(0,size);
    return max;
}

void valueUpdated(int index){
    if(index<=0){
        return;
    }
    int parent=(index-1)/2;
    if(heap[parent] < heap[index]){
        swap(&heap[parent],&heap[index]);
        valueUpdated(parent);
    }
}

void increaseKey(int index,int value){
    heap[index]=value;
    valueUpdated(index);
}

void decreaseKey(int index,int value){
    heap[index]=value;
    MAXhepify(index,size);
}

void print_heap(){
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={3,6,5,0,8,2,1,9};
    buildHeap(arr,8,1);
    print_heap();
    increaseKey(5,50);
    print_heap();
    decreaseKey(2,0);
    print_heap();
}