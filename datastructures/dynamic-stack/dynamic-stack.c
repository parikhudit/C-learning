#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "dynamic-stack.h"

#define STR(x)   #x
#define SHOW_DEFINE(x) printf("%s=%s\n", #x, STR(x))

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

bool push(Stack *stack, DATATYPE value)
{
    if (isOverflow(stack) == true)
    {
        DATATYPE *temp;
        temp = (DATATYPE *)malloc(sizeof(DATATYPE) * stack->size * 2);

        if (temp == NULL)
	{
            printf("Stack overflow\n");
            return false;
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
    return true;
}

DATATYPE pop(Stack *stack)
{
    if (isUnderflow(stack) == true)
    {
        printf("Stack Underflow\n");
        return EOF;
    }

    DATATYPE value = stack->item[stack->top];
    stack->top--;
    return value;
}

DATATYPE stackTop(Stack *stack)
{
    if (isUnderflow(stack) == true)
    {
        #if DATATYPE == char
        return EOF;
        #else
        return INT_MIN;
        #endif
    }

    return stack->item[stack->top];
}

Stack *create_stack(int size)
{
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack) * size);
    stack->top = -1;
    stack->item = (DATATYPE *)malloc(sizeof(DATATYPE) * size);

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
        stack->item = NULL;
    }
    free(stack);
    stack = NULL;
}
