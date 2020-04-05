#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "dynamic-stack.h"

int main() 
{
    Stack *s1;
    s1 = create_stack(3);

    if (s1 == NULL)
    {
        return 0;
    }
    
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    int choice;
    #if DATATYPE == char
    char value;
    #else
    int value;
    #endif
    
    while (true)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
                printf("Enter value: ");
                #if DATATYPE == char
                scanf(" %c", &value);
                #else
                scanf("%d", &value);
                #endif
                push(s1, value); 
                break;

            case 2:
                if (isUnderflow(s1) == false)
		{
                    value = pop(s1);
                    #if DATATYPE == char
                    printf("Popped data: %c\n", value);
                    #else
                    printf("Popped data: %d\n", value);
                    #endif
                }
                else
                {
                    printf("Stack is empty");
                }
                break;

            case 3:
	        destroy_stack(s1);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    
    return 1;
}
