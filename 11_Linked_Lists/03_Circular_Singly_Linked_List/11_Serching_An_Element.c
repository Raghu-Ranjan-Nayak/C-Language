//Serching an element in circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* addatempty(int data);
struct node* addatend(struct node* tail,int data);
int serchinganelement(struct node* tail,int element);

int main(){
    struct node* tail = NULL;
    int element;
    
    tail = addatempty(98);
    tail = addatend(tail,45);
    tail = addatend(tail,3);
    tail = addatend(tail,5);

    printf("Enter the element:");
    scanf("%d",&element);

    int index = serchinganelement(tail,element);

    if(index == -1){
        printf("Element not found");
    }
    else if(index == -2){
        printf("Linked list is empty");
    }
    else{
        printf("Element %d is at index %d",element,index);
    }

    struct node* ptr = tail -> next;
   
    return 0; 
}
struct node* addatempty(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
}
struct node* addatend(struct node* tail,int data){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> data = data;
    newp -> next = NULL;

    newp -> next = tail -> next;
    tail -> next = newp;
    tail = tail -> next;

    return tail;
}
int serchinganelement(struct node* tail,int element){
    struct node* temp = tail ->next;
    int index = 0;

    if(tail == NULL){
        return -2;
    }
    
    do{
        if(temp -> data == element){
            return index;
        }
        temp = temp -> next;
        index++;
    }while(temp != tail -> next);
    return -1;


}