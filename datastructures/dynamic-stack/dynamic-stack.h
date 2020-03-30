typedef struct
{
    int *item;
    int top;
    int size;
} Stack;

Stack *create_Stack(int size);

void push(Stack *stack, int value);

int pop(Stack *stack);

void destroy_Stack(Stack *stack);

int size(Stack *stack);

int isOverflow(Stack *stack);

int isUnderflow(Stack *stack);
