//I have to use functions like push,pop,isEmpty,isFull to give some data to user
#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
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
//push function means inserted elements in the stack
void push(int data){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}
//pop function means delete the last inserted element in the stack
int pop(){
    int value;
    if(isEmpty()){
        printf("stack underflow");
        exit(1);//means abnormal termination of the programm
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}
int peek(){
    if(isEmpty()){
        printf("Stack underflow");
    }
    return stack_arr[top];

}
void print(){
    if(isEmpty()){
        printf("stack underflow");
        return;
    }
    for(int i = top ; i >= 0 ; i--){
        printf("%d",stack_arr[i]);
        printf("\n");
    }
}
int main(){
    int choice,data;
    while(1){
        printf("\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Print top most element\n");
        printf("4.Print all the elements\n");
        printf("5.Quite\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                   printf("Enter your element to be push:");
                   scanf("%d",&data);
                   push(data);
                   break;
            case 2:
                   data = pop();
                   printf("The deleted element:%d",data);
                   break;
            case 3:
                   printf("The top most element:%d",peek());
                   break;
            case 4:
                   printf("All elements are:");
                   print();
                   break;
            case 5:
                   exit(1);
            default:
                    printf("Wrong choice");
                    
        }
    }
    return 0;
}