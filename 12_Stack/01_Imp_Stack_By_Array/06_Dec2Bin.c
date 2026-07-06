//This programm is for convert decimal to binary
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;
int isFull(){
    if(top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    top = top + 1;
    stack[top] = data;
}
int pop(){
    int value;
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    value = stack[top];
    top = top - 1;
    return value;
}
void dec2bin(int n){
    //print all the remainder into stack
    while(n != 0){
        push(n%2);
        n = n/2;
    }
}
int print(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    while(!isEmpty()){
        printf("%d ",pop());
    }
}
int main(){
    int dec;
    printf("Enter a decimal number:");
    scanf("%d",&dec);

    dec2bin(dec);
    print();

    return 0;
}