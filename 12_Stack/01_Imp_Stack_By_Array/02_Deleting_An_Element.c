//Deleting an element on stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;
//push function means inserted elements in the stack
void push(int data){
    if(top == MAX - 1){
        printf("Stack Overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}
//pop function means delete the last inserted element in the stack
int pop(){
    int value;
    if(top == -1){
        printf("stack underflow");
        exit(1);//means abnormal termination of the programm
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}
void print(){
    if(top == -1){
        printf("stack underflow");
        return;
    }
    for(int i = top ; i >= 0 ; i--){
        printf("%d",stack_arr[i]);
        printf("\n");
    }
}
int main(){
    int data;
    printf("Before pop function\n");
    push(1);
    push(2);
    push(3);
    push(4);
    print();
    printf("\nAfter pop function\n");
    data = pop();
    print();
    printf("Deleted value\n");
    printf("%d",data);
    printf("\n");

    return 0;
}