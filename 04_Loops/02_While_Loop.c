//Check armstrong number or not
#include<stdio.h>
int main(){
    int number,count=0,cnt,rem,mul=1,result=0;
    printf("enter a number:");
    scanf("%d",&number);
    int n=number;
    while(n!=0){
        n=n/10;
        count++;
    }
    cnt=count;
    n=number;
    while(n != 0){
        rem=n%10;
    while(cnt !=0){
        mul=mul*rem;
        cnt--;
    }
    result=result+mul;
    cnt=count;
    n=n/10;
    mul=1;
}
if(number == result){
    printf("%d is an armstrong number",number);
}
else{
    printf("%d is not an armsstrong number",number);
}
    return 0;
}