//This programm is for to print the prime factor of a number
#include<stdio.h>
#include<stdlib.h>
#define MAX 4

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
int prime_fact(int num){
    int i=2;
    while(num != 1){
        while(num % i == 0){
            push(i);
            num = num/i;
        }
        i++;
    }
    printf("The prime factor of a number in descending order are as below:");
    while(top != -1){
        printf("%d ",pop());
    }
}
int main(){
    int number;
    printf("Enter a positive integer:");
    scanf("%d",&number);

    prime_fact(number);

    return 0;
}