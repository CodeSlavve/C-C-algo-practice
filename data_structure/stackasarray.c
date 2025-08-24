#include <stdio.h>

int N = 8;       
int stack[8];     
int top = -1; 
void push(int x);
void pop ();
void peek();
void display();
int main(){
    int ch,element;
    do{	
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch){
        case 1: printf("Enter elemrnt");
	        scanf("%d",&element);
                push(element);
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: peek();
                break;
	    default:printf("Wrong choice");
    }
    }
    while(ch!=5);
    return 0;
}

void push(int x)
{
	if(top==N-1)
	printf("Stack is full");
	else
	{   
            top++;
	    stack[top]=x;
	}
}

void pop()
{   
    int item;
	if(top==-1)
	printf("stack is empty");
	else
	{
              item=stack[top];
	  top--;	
	}
	printf("item deleted:%d",item);
}

void display()
{  
    printf("elements in stack:");
    for(int i=top;i>=0;i--)
    printf("\n%d",stack[i]);
}

void peek()
{
	int item;
	if(top==-1)
	printf("stack is empty");
	else
	{
        item=stack[top];
	}
	printf("item at top is:%d",item);
}
