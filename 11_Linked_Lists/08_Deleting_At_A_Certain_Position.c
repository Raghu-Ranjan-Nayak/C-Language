//Deleting thet node at a certain position from single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* del_pos(struct node *head, int position);
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

    int position = 2;
    head = del_pos(head,position);

    current = head;
    while(current != NULL){
        printf("%d \n",current -> data);
        current = current -> link;
    }

    return 0;
}
struct node* del_pos(struct node *head, int position){
    struct node *current2 = head;
    struct node *previous = head;
    if(head == NULL){
        printf("list is already empty");
    }
    else if(position == 1){
        head = current2 -> link;
        free(current2);
        current2 = NULL;
    }
    else{
        while(position != 1){
            previous = current2;
            current2 = current2 -> link;
            position --;
        }
        previous -> link = current2 -> link;
        free(current2);
        current2 = NULL;
    }
    return head;
}