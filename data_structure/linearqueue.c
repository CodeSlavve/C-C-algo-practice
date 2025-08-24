#include<stdio.h>
#include<conio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue() {
    int x;
    printf("Enter the Element: ");
    scanf("%d", &x);
    
    if (rear == N-1){
        printf("The queueu is Full.\n");
    }
    
    else if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    
    else {
        rear++;
        queue[rear] = x;
    }   
}

void dequeue(){
    if (front == -1 && rear == -1){
        printf("The queue is Empty.\n");
    }
    
    else if (front == rear){
        printf("The deleted element is: %d\n", queue[front]);
        front = rear = -1;
    }
    
    else {
        printf("The deleted element is: %d\n", queue[front]);
        front++;
    }
}

void display() {
    int i = front;
    printf("The queue is:\n");
    for (i = front; i <= rear; i++){
        printf ("%d\n", queue[i]);
    }
}

void main() {
    int ch;
    do{
        printf("\n1.Add to Queue 2.Delete from Queue 3.Display Queue\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: enqueue();
            break;
            
            case 2: dequeue();
            break;
            
            case 3: display();
            break;
        }
    }
    
    while (ch != 0);
}