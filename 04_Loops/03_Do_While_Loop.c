//Enter number until multiple of 7
#include<stdio.h>
int main(){
    int number;
    do{
       printf("enter a number:");
       scanf("%d",&number);
        printf("%d\n",number);
        if(number % 7 == 0){
            break;
        }
    }while(1);
    return 0;
}