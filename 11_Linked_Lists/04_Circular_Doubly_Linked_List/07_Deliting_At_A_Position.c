//Deliting a node at position 2 of a circular doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;

};
struct node* addatempty(int data);
struct node* addatend(struct node* tail,int data);
struct node* delatpos(struct node* tail,int pos);
int print(struct node* tail);
int main(){
    struct  node* tail = NULL;
    int pos = 2;
    tail = addatempty(98);
    tail = addatend(tail,45);
    tail = addatend(tail,3);

    printf("List before delition:\n");
    print(tail);

    tail = delatpos(tail,pos);

    printf("List after delition:\n");
    print(tail);

    return 0;
}
struct node* addatempty(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = temp;
    temp -> data = data;
    temp -> next = temp;

    return temp;
}
struct node* addatend(struct node* tail,int data){
    struct node* newp = addatempty(data);
    if(tail == NULL){
        return newp;
    }
    else{
    struct node* temp =  tail -> next;
    newp -> next = temp;
    newp -> prev = tail;
    tail -> next = newp;
    temp -> prev = newp;
    tail = newp;

    return tail;
    }
}
struct node* delatpos(struct node* tail,int pos){
    struct node* temp;
    while(pos > 1){
        temp = temp -> next;
        pos --;
    }
    struct node* temp2 = temp -> prev;
    temp2 -> next = temp -> next;
    temp -> next -> prev = temp2;
    free(temp);
    if(temp == tail){
        tail = temp2;
    } 
    return tail;
}
int print(struct node* tail){
    if(tail == NULL){
        printf("No element in the list");
    }
    else{
        struct node* temp = tail -> next;
        do{
            printf("%d \n",temp -> data);
            temp = temp -> next;
        }while(temp != tail -> next);

    }
    printf("\n");
}