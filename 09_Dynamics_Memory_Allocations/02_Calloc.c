//Dynamics memory allocation by calloc
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr=(int*)calloc(5,sizeof(int));
    if(ptr == NULL){
        printf("The memory is not available");
    }
    for(int i=0;i<5;i++){
        printf("%d\n",ptr+i);
    }
    return 0;
}