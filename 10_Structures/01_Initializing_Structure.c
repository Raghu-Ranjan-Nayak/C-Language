//Print name,roll number and cgpa of a student by using structure
//Passes structure member as argument
#include<stdio.h>
struct student{
    char name[100];
    int roll_no;
    float cgpa;
};
void print(char name[],int roll_no,float cgpa){
    printf("%s %d %f",name,roll_no,cgpa);
}
int main(){
    struct student S1={"Raghu",7,9.2};
    print(S1.name, S1.roll_no, S1.cgpa);
    return 0;
}