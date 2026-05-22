//Salted form of a password
#include<stdio.h>
#include<string.h>
void salting(char password[]);
int main(){
    char password[100];
    puts("enter password:");
    fgets(password,100,stdin);
    salting(password);
    return 0;
}
void salting(char password[]){
    char salt[]="123";
    char newpassword[200];
    strcpy(newpassword,password);
    strcat(newpassword,salt);
    puts(newpassword);
}