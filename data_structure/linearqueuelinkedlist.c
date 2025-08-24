#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node *next;
} *temp, *front = 0, *rear = 0, *newnode;
int count = 0;

void enqueue(int element){
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory Allocation Unsuccessful.\n");
        free(newnode);
    }
    else{
        newnode->data = element;
        newnode->next = 0;
        if(rear == 0){
            front = rear = newnode;
        }
        else{
            temp = front;
            while(temp->next != 0){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        count++;
    }
}

void dequeue(){
    if(front == 0){
        printf("The queue is empty.\n");
    }
    else{
        temp = front;
        if(front == rear){
            rear = rear->next;
        }
        front = front->next;
        printf("The deleted elemenet is: %d\n", temp->data);
        free(temp);
        count--;
    }
}

void display(){
    if(front == 0){
        printf("The queue is empty.\n");
    }
    else{
        temp = front;
        printf("The Queue is:\n");
        while(temp != 0){
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        printf("The current queue length is: %d\n", count);
    }
}

void main(){
    int ch, element;
    do{
        printf("\n1.Enter element in queue 2.Delete element from queue 3.Display queue 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            enqueue(element);
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: printf("Exiting program.\n");
            break;
            default: printf("Wrong Choice!\n");
            break;
        }
    }
    while(ch != 4);
}