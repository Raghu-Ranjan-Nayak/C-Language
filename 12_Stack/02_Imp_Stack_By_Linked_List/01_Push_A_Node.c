//Push a node at the begning of a linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*top = NULL;
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
    printf("1.push\n");
    printf("2.print\n");
    printf("3.quite\n");
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
              printf("Enter your pushed element:");
              scanf("%d",&data);
              push(data);
              break;
        case 2:
              print();
              break;
        case 3:
              exit(1);
              break;
        default:
               printf("Wrong choice");
    }
}

    return 0;

}

