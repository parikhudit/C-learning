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
        // printf("Size of Stack: %d\n", size(s1));

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
	        destroy_stack(s1);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
