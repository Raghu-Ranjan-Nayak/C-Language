//Reverse a single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* rev_list(struct node *head);
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current -> data = 98;
    current -> link = NULL;
    head -> link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current -> data = 3;
    current -> link = NULL;
    head -> link -> link = current;

    head = rev_list(head);

    current = head;
    while(current != NULL){
        printf("%d \n",current -> data);
        current = current -> link;
    }

    return 0;
}
struct node* rev_list(struct node *head){
    struct node *prev = NULL;
    struct node *next = head;
    while(head != NULL){
        next = head -> link;
        head -> link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;

}