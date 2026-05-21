//Check prime or not
#include<stdio.h>
#include<math.h>
int main(){
    int x,val1,val2,count=0;
    printf("enter a number(positive integer):");
    scanf("%d",&x);
    val1=ceil(sqrt(x));
    val2=x;

    for (int i=2;i<=val1;i++){
        if(val2%i == 0){
            count=1;
        }
    }
    if((count==0 && val2 != 1)||val2 == 2 || val2 == 3){
        printf("%d is an prime number",val2);
    }
    else{
        printf("%d is not an prime number",val2);
    }
    return 0;
}