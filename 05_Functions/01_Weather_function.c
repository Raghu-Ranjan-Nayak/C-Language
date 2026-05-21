//Check hot or cold day
#include<stdio.h>
void weather();
int main(){
    weather();
    return 0;
}
void weather(){
    int temp;
    printf("enter temprature(celsius):");
    scanf("%d",&temp);
    if(temp >= 20 ){
        printf("%d is a hot day",temp);
    }
    else{
        printf("%d is a cold day",temp);
    }
}