//Check student is pass or fail
#include<stdio.h>
int main(){
    int mark;
    printf("enter mark:");
    scanf("%d",&mark);
    if(mark >= 30){
        printf("pass");
    }
    else if(mark < 30){
        printf("fail");
    }
    else{
        printf("wrong mark");
    }
    return 0;
}