//This programm is for reverse the elements 
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
void push(int data,struct node** top1){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Stsck overflow");
        exit(1);
    }
    newnode -> data = data;
    newnode -> link = NULL;

    newnode -> link = *top1;
    *top1 = newnode;

}
int pop(struct node** top){
struct node* temp;
temp = *top;
int val;
val = temp -> data;
*top = (*top) -> link;
free(temp);
temp = NULL;

return val;
}
void print(struct node **top){
    struct node* temp;
    temp = (*top);
    printf("The stack elements are:");
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}
int main(){
    int data;
    struct node* top = NULL;
    struct node* top1 = NULL;
    struct node* top2 = NULL;

    push(1,&top);
    push(2,&top);
    push(3,&top);
    //from original stack to temporary stack 1
    data = pop(&top);
    push(data,&top1);
    data = pop(&top);
    push(data,&top1);
    data = pop(&top);
    push(data,&top1);
    print(&top);
    print(&top1);
    //from tempory stack 1 to temorary stack 2
    data = pop(&top1);
    push(data,&top2);
    data = pop(&top1);
    push(data,&top2);
    data = pop(&top1);
    push(data,&top2);
    print(&top1);
    print(&top2);
    //from tempory stack 2 to original stack
    data = pop(&top2);
    push(data,&top);
    data = pop(&top2);
    push(data,&top);
    data = pop(&top2);
    push(data,&top);
    print(&top2);
    print(&top);
    return 0;
}