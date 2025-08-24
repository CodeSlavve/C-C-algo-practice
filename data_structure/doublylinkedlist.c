#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head = NULL, *temp, *newnode;
int count= 0;
int element;

void takingInput(){
    printf("Enter element: ");
    scanf("%d", &element);
}

void insertAtStart(){
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation unsuccessful.\n");
        free(newnode);
    }
    else{
        takingInput();
        newnode->data = element;
        newnode->prev = NULL;
        if(head == NULL){
            newnode->next = NULL;
            head = newnode;
        }
        else{
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
        count++;
    }
}

void insertAtLast(){
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation Unsuccessful.\n");
        free(newnode);
    }
    else{
        takingInput();
        newnode->data = element; 
        newnode->next = NULL;
        if (head == NULL){
            newnode->prev = NULL;
            head = newnode;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
        count++;
    }
}

void inserAtPos(){
    int i = 1, pos;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("Memory alloocation unsuccessful.\n");
        free(newnode);
    }
    else{
        printf("Enter position: ");
        scanf("%d", &pos);
        if(pos < 1 || pos > count + 1 ){
            printf("Invalid Position.\n");
            printf("Current list length: %d\n", count);
            free(newnode);
        }
        else{
            takingInput();
            newnode->data = element;
            if(pos == 1){
                newnode->prev = NULL;
                newnode->next = head;
                if(head == NULL){
                    head = newnode;
                }
                else{
                    head->prev = newnode;
                    head = newnode;
                }
            }
            else{
                temp = head;
                while(i < pos-1){
                    temp = temp->next;
                    i++;
                }
                
                newnode->prev = temp;
                if(temp->next == NULL){
                    newnode->next = NULL;
                    temp->next = newnode;
                }
                else{
                    newnode->next = temp->next;
                    temp->next = newnode;
                    newnode->next->prev = newnode;
                }
            }
            count++;
        }
    }
}

void deletefirst(){
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        count--;
    }
}

void deletelast(){
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        count--;
    }
}


void deletepos(){
    int i = 1, pos;
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        printf("Enter position: ");
        scanf("%d", &pos);
        if (pos < 1 || pos > count){
            printf("Invalid Position.\n");
            printf("Curent list length: %d\n", count);
        }
        else{
            temp = head;
            while(i < pos){
                temp = temp->next;
                i++;
            }
            if(temp->next == NULL){
                temp->prev->next = NULL;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            count--;
        }
    }
}

void display(){
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        printf("Linked list is: \n");
        while(temp != NULL){
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        printf("The length of list is: %d\n", count);
    }
}

void main(){
    int ch;
    do{
        printf("\n1.InserAtStart 2.InsertAtLast 3.InsertAtPos 4.Deletefirst 5.Deletelast 6.Deletepos 7.Display 8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insertAtStart();
            break;
            case 2: insertAtLast();
            break;
            case 3: inserAtPos();
            break;
            case 4: deletefirst();
            break;
            case 5: deletelast();
            break;
            case 6: deletepos();
            break;
            case 7: display();
            break;
            case 8: printf("Exiting program\n");
            break;
            default: printf("Invalid choice.\n");
            break;
        }
    }
    while(ch != 8);
}