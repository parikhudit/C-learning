#include<stdbool.h>

typedef struct
{
    int *item;
    int top;
    int size;
} Stack;

Stack *create_stack(int size);

int push(Stack *stack, int value);

int pop(Stack *stack);

void destroy_stack(Stack *stack);

int size(Stack *stack);

bool isOverflow(Stack *stack);

bool isUnderflow(Stack *stack);

int stackTop(Stack *stack);
