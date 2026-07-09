//Cheak the given charector string is palindrome or not
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
    newnode -> data = data;
    newnode -> link = NULL;

    newnode -> link = top;
    top = newnode;
}
int pop(){
    struct node* temp;
    int val;
    if(isEmpty()){
        printf("Stack underflow");
    }
    temp = top;
    top = top -> link;
    val = temp -> data;
    free(temp);
    temp = NULL;

    return val;
}
int peek(){
    if(isEmpty){
        printf("Stack underflow");
        exit(1);
    }
    return top -> data;
}
void palindrome_check(char* s){
    int i = 0;
    while(s[i] != 'X'){
        push(s[i]);
        i++;
    }
    i++;
    while(s[i]){
    if((isEmpty()) || s[i] != pop()){
        printf("Not polindrome");
        exit(1);
    }
    i++;
}
    if(isEmpty()){
        printf("Polindrome");
    }
    else{
        printf("Not polindrome");
    }
}
int main(){
    char s[100];
    printf("Plese enter a charector string:");
    scanf("%s",&s);

    palindrome_check(s);

    return 0;
}