//Create an doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addtoempty(struct node* head,int data);
struct node* addatend(struct node* head,int data);
struct node* createlist(struct node* head);
int main(){
    struct node* head = NULL;
    struct node* ptr;

    head = createlist(head);

    ptr = head;
    while(ptr != NULL){
        printf("%d \n",ptr -> data);
        ptr = ptr -> next;
    }
    return 0;
}
struct node* addtoempty(struct node* head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;

    return  head;
}
struct node* addatend(struct node* head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* temp1;
    temp1 = head;
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    while(temp1 -> next != NULL){
        temp1 = temp1 -> next;
    }
    temp1 -> next = temp;
    temp -> prev = temp1;

    return head;

}
struct node* createlist(struct node* head){
    int n,data,i;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    if(n == 0){
        return head;
    }
    printf("Enter the element for the node 1:");
    scanf("%d",&data);
    head = addtoempty(head,data);
    for(i=1 ; i<n ; i++){
        printf("Enter the element for the node %d:",i+1);
        scanf("%d",&data);
        head = addatend(head,data);
    }
    return head;
}