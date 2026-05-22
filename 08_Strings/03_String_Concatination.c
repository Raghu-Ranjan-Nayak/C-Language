//String concatination
#include<stdio.h>
#include<string.h>
int main(){
    char firststr[100]="Hello ";
    char secstr[]="World";
    strcat(firststr,secstr);
    puts(firststr);
    return 0;
}