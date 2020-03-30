#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "dynamic-stack.h"


int isOverflow(Stack *sp)
{
    return sp->top == sp->size - 1;
}

int isUnderflow(Stack *sp)
{
    return sp->top == -1;
}

int size(Stack *stack)
{
    return stack->size;
}

void push(Stack *stack, int value)
{
    if (isOverflow(stack) == true)
    {
        int *temp;
        temp = (int *)malloc(sizeof(int) * stack->size * 2);

        if (temp == NULL)
	{
            printf("Stack overflow\n");
            return;
        }

        for (int i = 0; i <= stack->top; i++)
	{
            temp[i] = stack->item[i];
        }

        free(stack->item);
        stack->item = temp;
        stack->size *= 2;
        
    }
    
    stack->top++;
    stack->item[stack->top] = value;
}

int pop(Stack *stack)
{
    if (isUnderflow(stack) == true)
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }

    int value = stack->item[stack->top];
    stack->top--;
    return value;
}

Stack *create_Stack(int size)
{
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack) * size);
    stack->top = -1;
    stack->item = (int *)malloc(sizeof(int) * size);

    if (stack->item == NULL)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }

    stack->size = size;
    return stack;
}

void destroy_Stack(Stack *stack)
{
    if (stack->item != NULL)
    {
        free(stack->item);
    }
    free(stack);

    stack->top = -1;
    stack->size = 0;
}

/*
int main() 
{
    Stack *s1;
    s1 = create_Stack(3);

    if (s1 == NULL)
    {
        return INT_MIN;
    }
    
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    int choice, value;
    
    while (true)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("Size of Stack: %d\n", size(s1));

        switch (choice)
	{
            case 1: 
                printf("Enter value: ");
                scanf("%d", &value);
                push(s1, value); 
                break;

            case 2:
                value = pop(s1);
                if (isUnderflow(s1) == false)
		{
                    printf("Popped data: %d\n", value);
                }    
                break;

            case 3:
	        destroy_Stack(s1);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
*/
