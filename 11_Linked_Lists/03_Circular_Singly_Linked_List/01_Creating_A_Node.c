//Create  a anode of the circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* circularsingly(int data);

int main(){
    struct node* tail;
    int data = 98;
    tail = circularsingly(data);

    printf("%d",tail -> data);
    return 0;
}
struct node* circularsingly(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
}