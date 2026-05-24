//Print name of a student by using structure
#include<stdio.h>
#include<string.h>
struct student{
    char name[100];
};
int main(){
    struct student S1={"Raghu"};
    printf("student name=%s\n",S1.name);
    return 0;
}