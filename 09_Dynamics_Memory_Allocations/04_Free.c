//Dynamically memory allocated malloc and released by free
#include<stdio.h>
#include<stdlib.h>
int *input(){
    int *ptr=(int*)malloc(5*sizeof(int));
    printf("Enter 5 numbers:");
    for(int i=0;i<5;i++){
        scanf("%d",ptr+i);
    }
        return ptr;
    
}
int main(){
    int sum=0;
    int *ptr=input();
    for(int i=0;i<5;i++){
        sum += *(ptr+i);
    }
    printf("sum is:%d",sum);
    free(ptr);
    ptr=NULL;
    return 0;
}