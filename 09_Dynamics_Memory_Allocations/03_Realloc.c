//Dynamics memory allocation by malloc and realloc
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr=(int*)malloc(2*sizeof(int));
    if(ptr == NULL){
        printf("The memory is not available");
    }
    printf("Enter two integer:\n");
    for(int i=0;i<2;i++){
        scanf("%d",ptr+i);
    }
    //memory allocation for two more integers
    ptr=realloc(ptr,4*sizeof(int));
    if(ptr == NULL){
        printf("The memory is not available");
    }
    printf("Enter 2 more integer:\n");
    for(int i=2;i<4;i++){
        scanf("%d",ptr+i);
    }
    //pint the values on the screen
    for(int i=0;i<4;i++){
        printf("%d\n",*(ptr+i));
    }
    return 0;
}