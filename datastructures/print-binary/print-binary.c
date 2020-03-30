
#include <stdio.h>
#include <stdlib.h>
#include "dynamic-stack/dynamic-stack.h"

void printBinary(unsigned int);

void printBinary(unsigned int n)
{
    Stack *s;
    s = create_Stack(10);
    if (s == NULL)
    {
        printf("Failed to create stack\n");
    }
    int temp = n;
    const int BASE = 2;
    
    while (n > 0)
    {
        int rem = n % BASE;
        push(s, rem);
        n /= BASE;
    }
    printf("Binary equivalent of %d is: \n", temp);
    while (isUnderflow(s) == 0)
    {
        printf("%d", pop(s));
    }
    destroy_Stack(s);
    printf("\n");
    
}

int main() 
{
    
    printBinary(18);
    return 0;
}

