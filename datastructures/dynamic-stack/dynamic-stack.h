#include<stdbool.h>

#ifndef DATATYPE
    #define DATATYPE int
#endif

typedef struct
{
    DATATYPE *item;
    int top;
    int size;
} Stack;

Stack *create_stack(int size);

bool push(Stack *stack, DATATYPE value);

DATATYPE pop(Stack *stack);

void destroy_stack(Stack *stack);

int size(Stack *stack);

bool isOverflow(Stack *stack);

bool isUnderflow(Stack *stack);

DATATYPE stackTop(Stack *stack);
