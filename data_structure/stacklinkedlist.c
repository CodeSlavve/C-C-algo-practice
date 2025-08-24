#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
}*top = 0, *temp, *newnode;

void push(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &newnode->data);
    newnode->prev = top;
    top = newnode;
}

void pop(){
    if(top == 0){
        printf("The stack is empty.\n");
    }
    else{
        temp = top;
        top = top->prev;
        printf("Deleted element is: %d\n", temp->data);
        free(temp);
    }
}

void peek(){
    if(top == 0){
        printf("The stack is empty.\n");
    }
    else{
        printf("The top data is: %d\n", top->data);
    }
}

void display(){
    if(top == 0){
        printf("The stack is empty.\n");
    }
    else{
        temp = top;
        printf("The stack is: ");
        while(temp != 0){
            printf("%d  ", temp->data);
            temp = temp->prev;
        }
    printf("\n");
    }
}

void main(){
    int ch;
    do{
        printf("\n1.Enter element in stack 2.Delete element from stack 3.Peek 4.Display stack\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            default: printf("Wrong choice.\n");
            break;
        }
    }
    while(ch != 0);
}