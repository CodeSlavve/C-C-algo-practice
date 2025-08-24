#include<stdio.h>
#include<conio.h>
#define N 5
int queue[N];
int rear = -1;
int front = -1;

void enqueue(int x) {
    if (front == (rear + 1)% N){
        printf("The queue is Full.\n");
    }

    else if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }

    else {
        rear = (rear + 1)% N;
        queue[rear] = x;
    }
}

void dequeue(){
    if (front == -1 && rear == -1){
        printf("The queue is Empty.\n");
    }

    else if(front == rear){
        printf("The deleted element is: %d\n", queue[front]);
        front = rear = -1;
    }

    else{
        printf("The deleted element is: %d\n", queue[front]);
        front = (front + 1)%N;
    }
}

void display(){
    if (front == -1 && rear == -1){
        printf("The queue is Empty.\n");
    }

    else {
        int i = front;
        while (i != rear){
            printf("%d ", queue[i]);
            i = (i+1)%N;
        }

        printf("%d\n", queue[i]);
    }
}

void main (){
    int ch, x2;
    do {
        printf("\n1.Enter element in queue 2.Delete element from queue 3.Display queue 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter the element: ");
                    scanf("%d", &x2);
                    enqueue(x2);
            break;

            case 2: dequeue();
            break;

            case 3: display();
            break;

            case 4: printf("Exiting programm\n");
            break;

            default: printf("Invalid Input.\n");
        }
    }

    while (ch != 4);
}