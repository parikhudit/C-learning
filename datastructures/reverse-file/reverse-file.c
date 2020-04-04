#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../dynamic-stack/dynamic-stack.h"

int reverseFile(char source[], char dest[])
{
    FILE *fps, *fpd;
    const int SIZE = 50;
    fps = fopen(source, "r");

    if (fps == NULL)
    {
        printf("Error opening file %s\n", source);
        return 0;
    }

    fpd = fopen(dest, "w");
    if (fpd == NULL)
    {
        printf("Error opening file %s\n", dest);
        return 0;
    }

    Stack *s;
    s = create_stack(SIZE);
    char buff = fgetc(fps);

    while (feof(fps) == 0)
    {
        push(s, buff);
        buff = fgetc(fps);
    }

    while (isUnderflow(s) == 0)
    {
        fputc(pop(s), fpd);
    }

    fclose(fps);
    fclose(fpd);
    destroy_stack(s);
    return 1;
}

int main()
{
    int f = reverseFile("input_text.txt", "rev_text.txt");

    if (f != 0)
    {
        printf("File copied successfully\n");
    }
    else
    {
        printf("Error -- copy failed\n");
    }

    return 1;
}

