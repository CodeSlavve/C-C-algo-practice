#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head = 0, *newnode, *temp;
int count = 0;

void insertAtLast(){
    int ch;
    do{
        printf("Enter element to insert at last: ");
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0){
            head = temp = newnode;
        }
        else {
            temp = head;
            while(temp->next != 0){
                temp = temp->next; 
            }
            temp->next = newnode;
        }
        count++;
        printf("Do you want to continue?\n1.YES 2.NO\n");
        scanf("%d", &ch);
    }
    while (ch == 1);
}

void insertAtStart(){
    int ch;
    do{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Element to insert at start: ");
        scanf("%d", &newnode->data);
        if (head == 0){
            head = newnode;
            newnode->next = 0;
        }
        else {
            newnode->next = head;
            head = newnode;
        }
        count++;
        printf("Do you want to continue?\n1.YES 2.NO\n");
        scanf("%d", &ch);
    }
    while(ch == 1);
}

void insertAtPos(){
    int i= 1, pos, ch;
    do{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter position: ");
        scanf("%d", &pos);
        printf("Enter element to enter at position %d: ", pos);
        scanf("%d", &newnode->data);
        if(pos < 1 || pos > count + 1){
            printf("Invalid position! Current list length: %d\n", count);
            free(newnode);
        }
        else{
            if(pos == 1){
                newnode->next = head;
                head = temp = newnode;
            }
            else{
                temp = head;
                while(i<pos-1){
                    temp = temp->next;
                    i++;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
            count++;
        }
        printf("Do you want to continue?\n1.YES 2.NO\n");
        scanf("%d", &ch);
    }
    while (ch == 1);
}

void display(){
    if(head == 0){
        printf("The Linked List is empty.\n");
    }
    else{
        temp = head;
        printf("Linked list data is: \n");
        while(temp != 0){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("The length of list is %d\n", count);
    }
}

void deletefirst(){
    if(head == 0){
        printf("The List is empty.\n");
    }
    else{
        temp = head;
        head = head->next;
        printf("Deleted element is: %d\n", temp->data);
        free(temp);
    }
    count--;
}

void deletelast(){
    struct node *prevnode;
    if(head == 0){
        printf("The list is empty.\n");
    }
    else if(head->next == 0){
        head = 0;
        printf("Deleted element is: %d\n", head->data);
        free(head);
    }
    else{
        temp = head;
        while(temp->next != 0){
            prevnode = temp;
            temp=temp->next;
        }
        prevnode->next = 0;
        printf("Deleted element is: %d\n", temp->data);
        free(temp);
    }
    count--;
}

void deletepos(){
    int i = 1, pos;
    struct node *prevnode;
    if (head == 0){
        printf("The list is empty.\n");
    }
    else{
        printf("Enter the position: ");
        scanf("%d", &pos);
        if (pos < 1 || pos > count){
            printf("Invalid position. Current list length: %d\n", count);
        }
        else{
            temp = head;
            if(pos == 1){
                head = head->next;
                printf("Deleted element is: %d\n", temp->data);
                free(temp);
            }
            else{
                while(i<pos){
                    prevnode = temp;
                    temp = temp->next;
                    i++;
                }
                prevnode->next = temp->next;
                printf("Deleted elemet is: %d", temp->data);
                free(temp);
            }
            count--;
        }
    }
}

void main(){
    int ch;
    do{
        printf("\n1.Insert at last 2.Insert at start 3.Insert at pos 4.Delete first 5. Delete last 6.Delete at pos 7.Display 8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            
            case 1: insertAtLast();
            break;
            case 2: insertAtStart();
            break;
            case 3: insertAtPos();
            break;
            case 4: deletefirst();
            break;
            case 5: deletelast();
            break;
            case 6: deletepos();
            break;
            case 7: display();
            break;
            case 8: printf("Exiting program.\n");
            break;
            default: printf("Wrong choice\n");
        }
    }
    while(ch != 8);
}