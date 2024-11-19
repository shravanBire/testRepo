#include <stdio.h>

void main(){

    int arr[]={931,384,294,741,482,675};

    for(int exp=1;exp<=100;exp*=10){

        int output[6]={0};
        int count[10]={0};

        for(int i=0;i<6;i++){
            count[(arr[i]/exp)%10]+=1;
        }

        for(int j=1;j<10;j++){
            count[j]=count[j]+count[(j-1)];
        }

        for(int i=0;i<6;i++){
            int rem=((arr[i]/exp)%10);
            count[rem]-=1;
            output[(count[rem])]=arr[i];

        }

        for(int i=0;i<6;i++){
            arr[i]=output[i];
        }

        for(int i=0;i<6;i++){
            printf("%d ",arr[i]);
        }
        
    printf("\n");
    }    
}
