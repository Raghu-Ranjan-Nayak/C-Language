//Factorial of n
#include<stdio.h>
int fact(int n);
int main(){
    int n;
    printf("enter a number:");
    scanf("%d",&n);
    printf("The factorial is:%d",fact(n));
    return 0;
}
int fact(int n){
     if(n==1){
        return 1;
    }
    int factNM1=fact(n-1);
    int factN=factNM1 * n;
    return factN;
}