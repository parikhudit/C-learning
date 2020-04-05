// implementation of bracket checker program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../dynamic-stack/dynamic-stack.h"

#define SIZE 100
// function required for this application
bool isOpeningMatch(char, char);
bool checkExpr(Stack *);


bool isOpeningMatch(char left, char right)
{
    bool match = false;

    switch(left)
    {
        case '(': 
            if (right == ')')
                match = true;
            break;

       case '{': 
           if (right == '}')
               match = true;
	   break;

       case '[': 
           if (right == ']')
               match = true;
           break;

       default: printf("Invalid symbol encountered, terminating program\n");
           exit(1);
    }	

    return match;
}

bool checkExpr(Stack *input)
{
    Stack *stack;
    stack = create_stack(SIZE);
    bool error = false;
    int i = 0;
    char poppedValue =  EOF;

    while ((poppedValue = pop(input)) != EOF)
    {
        // get the next character from the stack
        char next_char = (char)poppedValue;

        if (next_char == '(' || next_char == '{' || next_char == '[')
	{
            push(stack, next_char);
	}
        else if (next_char == ')' || next_char == '}' || next_char == ']')
	{
            if (isUnderflow(stack) == true)
	    {
                error = 1;
                break;
            }
            else if (isOpeningMatch((char)stackTop(stack), next_char) == true)
	    {
                pop(stack);
            }
            else
	    {
                error = 1;
                break;
            }
        }
        ++i;
    }

    if (error == false && isUnderflow(stack) == false)
    {
        error = true;
    }

    destroy_stack(stack);
    return error;
}

int main()
{
    Stack *input;
    input = create_stack(SIZE);

    printf("Input expression: ");

    int c = EOF;
    while (( c = getchar() ) != '\n' && c != EOF)
    {
        push(input, c);
    }

    if (checkExpr(input) == true)
    {
        printf("Does not contain well formed brackets\n");
    }
    else
    {
        printf("Contains well formed brackets\n");
    }

    destroy_stack(input);

    return 1;
}
