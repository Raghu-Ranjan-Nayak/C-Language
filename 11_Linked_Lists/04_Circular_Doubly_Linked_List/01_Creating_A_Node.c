//Create  a node of the circular doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* circulardoubly(int data);

int main(){
    struct node* tail;
    int data = 98;
    tail = circulardoubly(data);

    printf("%d",tail -> data);
    return 0;
}
struct node* circulardoubly(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = temp;
    temp -> data = data;
    temp -> next = temp;
    return temp;
}