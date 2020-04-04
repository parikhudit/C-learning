typedef struct
{
    int *item;
    int top;
    int size;
} Stack;

Stack *create_stack(int size);

void push(Stack *stack, int value);

int pop(Stack *stack);

void destroy_stack(Stack *stack);

int size(Stack *stack);

int isOverflow(Stack *stack);

int isUnderflow(Stack *stack);
