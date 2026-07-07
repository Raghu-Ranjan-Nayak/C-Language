//This programm is for pop a elements and check is empty
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*top = NULL;
int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Stsck overflow");
        exit(1);
    }
    newnode -> data = data;
    newnode -> link = NULL;

    newnode -> link = top;
    top = newnode;

}
int pop(){
struct node* temp;;
temp = top;
if(isEmpty()){
    printf("Stack underflow");
    exit(1);
} 
int val;
val = temp -> data;
top = top -> link;
free(temp);
temp = NULL;

return val;
}
int peek(){
    if(isEmpty()){
    printf("Stack underflow");
    exit(1);
} 
return top -> data;

}
void print(){
    struct node* temp;
    temp = top;
    printf("The stack elements are:");
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}
int main(){
    int choice,data;
    while(1){
    printf("\n1.push\n");
    printf("2.delete top most element\n");
    printf("3.The peek element of the stack\n");
    printf("4.print\n");
    printf("5.quite\n");
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
              printf("Enter your pushed element:");
              scanf("%d",&data);
              push(data);
              break;
        case 2:
               data = pop();
               printf("The deleted element is:%d",data);
               break;
        case 3:
               printf("The top most element is:%d",peek());
               break;
        case 4:
              print();
              break;
        case 5:
              exit(1);
              break;
        default:
               printf("Wrong choice");
    }
}

    return 0;

}

