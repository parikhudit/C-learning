#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "dynamic-stack.h"


bool isOverflow(Stack *sp)
{
    return sp->top == sp->size - 1;
}

bool isUnderflow(Stack *sp)
{
    return sp->top == -1;
}

int size(Stack *stack)
{
    return stack->size;
}

int push(Stack *stack, int value)
{
    if (isOverflow(stack) == true)
    {
        int *temp;
        temp = (int *)malloc(sizeof(int) * stack->size * 2);

        if (temp == NULL)
	{
            printf("Stack overflow\n");
            return INT_MIN;;
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
    return 1;
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

int stackTop(Stack *stack)
{
    if (isUnderflow(stack) == true)
    {
        return INT_MIN; 
    }

    return stack->item[stack->top];
}

Stack *create_stack(int size)
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

void destroy_stack(Stack *stack)
{
    if (stack->item != NULL)
    {
        free(stack->item);
    }
    free(stack);

    stack->top = -1;
    stack->size = 0;
}
