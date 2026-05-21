//String copy
#include<stdio.h>
#include<string.h>
int main(){
    char newstr[]="newstr";
    char oldstr[]="oldstr";
    strcpy(newstr,oldstr);
    puts(newstr);
return 0;
}