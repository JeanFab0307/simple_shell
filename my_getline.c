#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 255

size_t my_getline(char *buf, FILE *stream, size_t size)
{
    size_t count = 0;
    char c;
    while ((c = (char)getc(stream)) != '\n' && count < size - 1)
    {
        buf[count++] = c;
    }
    buf[count] = '\0';
    return count;
}

int main(void)
{
    char input[MAX_LINE_LENGTH]; // a string to hold an input
    while (1)
    {
        printf("$ "); // shows that a system is waiting for an input.
        size_t count = my_getline(input, stdin, MAX_LINE_LENGTH);
        // custome getline method is called.
        // count stores the length of chars on an input.
        printf("Input: \"%s\" \n", input);
    }

    return (0);
}