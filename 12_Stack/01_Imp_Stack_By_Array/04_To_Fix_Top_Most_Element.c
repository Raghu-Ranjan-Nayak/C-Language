//This programm is for the top most element is same but the first element is changing
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first = -1;

int isFull(){
    if(first == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(first == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    return stack_arr[0];
}

void push(int data){
    first += 1;
    int i;
    if(isFull()){
        printf("stack overflow");
        exit(1);
    }
    for(int i=first;i>0;i--){
        stack_arr[i] = stack_arr[i-1];

    }
    stack_arr[0] = data;

}
int pop(){
    int value;
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    value = stack_arr[0];
    for(int i=0;i<first;i++){
        stack_arr[i] = stack_arr[i+1];
    }
    first -= 1;
    return value;
}
int print(){
    if(first == -1){
        printf("stack underflow");
        exit(1);
    }
    for(int i=0;i<=first;i++){
        printf("%d ",stack_arr[i]);
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