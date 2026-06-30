//Adding two numbers using singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* link;
};
struct node* push(struct node* head,int val);
struct node* add(struct node* head1,struct node* head2);
struct node* reversell(struct node* head);
struct node* add_node(struct node* head,int val);
struct node* creatll(struct node* head,int n);
void print(struct node* head);
void back2num(struct node* head);
int main(){
    int a,b;
    printf("Enter the two numbers:");
    scanf("%d %d", &a ,&b);

    printf("Linked list representation of first number:\n");
    struct node* head1 = NULL;
    head1 = creatll(head1,a);
    print(head1);
    
    struct node* head2 = NULL;
    printf("\nLinked list representation of second number:\n");
    head2 = creatll(head2,b);
    print(head2);

    head1 = reversell(head1);
    head2 = reversell(head2);

    printf("\nReverse linked list:\n");
    print(head1);
    printf("\n");
    print(head2);

    struct node* head3 = NULL;
    head3 = add(head1,head2);
    printf("\nResultant linked list after addition:\n");
    print(head3);

    back2num(head3);

    return 0;
}
struct node* push(struct node* head,int val){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> data = val;
    newp -> link = head;
    head = newp;
    return head;
}
struct node* add(struct node* head1,struct node* head2){
    if(head1 -> data == 0){
        return head2;
    }
    if(head2 -> data == 0){
        return head1;
    }
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    int sum , carry = 0;

    while(ptr1 != NULL || ptr2 != NULL){
        sum = 0;
        if(ptr1){
            sum += ptr1 -> data;
        }
        if(ptr2){
            sum += ptr2 -> data;
        }
        sum += carry;

        carry = sum/10;
        sum = sum%10;

        head3 = push(head3,sum);

        if(ptr1){
            ptr1 = ptr1 -> link;
        }
        if(ptr2){
            ptr2 = ptr2 -> link;
        }
    }
    if(carry){
        head3 = push(head3,carry); 
    }
    return head3;

}
struct node* reversell(struct node* head){
    if(head == NULL){
        return head;
    }
    struct node* current = NULL;
    struct node* next = head -> link;
    head -> link = NULL;

    while(next != NULL){
        current = next;
        next = next -> link;
        current -> link = head;
        head = current;
    }
    return head;
}
struct node* add_node(struct node* head,int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = val;
    newnode -> link = NULL;

    newnode -> link = head;
    head = newnode;
    return head;
}
struct node* creatll(struct node* head,int n){
    while(n != 0){
        head = add_node(head,n%10);
        n = n/10;
    }
    return head;
}
void print(struct node* head){
    struct node* temp = head;
    if(head == NULL){
        printf("no number");
    }
    else{
        while(temp -> link != NULL){
            printf("%d ->", temp -> data);
            temp = temp -> link;
        }
        printf("%d", temp -> data);
    }
}
//This function is for displaying the result
void back2num(struct node* head){
    struct node* temp = head;
    printf("\nResult = ");
    while(temp){
        printf("%d",temp -> data);
        temp = temp -> link;
    }
    return;
}
