#include <stdio.h>
#define N 20
int stack[N];
int top = -1;
void main()
{
    char ch[N]; 
    int result, i = 0;
    printf("\nEnter postfix expression: ");
    scanf("%s", &ch); 
    while (ch[i] != '\0')
    { 
        if (ch[i] == '+')
        {
            result = stack[top - 1] + stack[top];
            top--;
            stack[top] = result;
        }
        else if (ch[i] == '-')
        {
            result = stack[top - 1] - stack[top];
            top--;
            stack[top] = result;
        }
        else if (ch[i] == '*')
        {
            result = stack[top - 1] * stack[top];
            top--;
            stack[top] = result;
        }
        else if (ch[i] == '/')
        {
            if (stack[top] == 0)
            {
                printf("Division by zero is not possible\n");
            }
            result = stack[top - 1] / stack[top];
            top--;
            stack[top] = result;
        }
        else
        {
            top++;
            stack[top] = ch[i] - '0';
        }
        i++;
    }
    printf("Result: %d\n", stack[top]);
}