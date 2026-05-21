//Swap of two numbers
#include<stdio.h>
void swap(int *a,int *b);
int main(){
    int a=5,b=7;
    swap(&a,&b);
    return 0;
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
printf("a=%d,b=%d",*a,*b);
}