//Check which day
#include<stdio.h>
int main(){
    int day;//1-mon,2-tue,3-wed,4-thus,6-fri,7-sat
    printf("enter a day(1-7):");
    scanf("%d",&day);
    switch(day){
        case 1:printf("sunday\n");
        break;
        case 2:printf("monday\n");
        break;
        case 3:printf("tuesday\n");
        break;
        case 4:printf("wednesday\n");
        break;
        case 5:printf("thursday\n");
        break;
        case 6:printf("friday\n");
        break;
        case 7:printf("saturday\n");
        break;
        default:printf("This is not a valid day");
        break;
    }
    return 0;
}