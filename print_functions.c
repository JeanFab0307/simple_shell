#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

int _putchar(char c, int fd)
{
        return (write(fd,_FILENO, c, 1));
}

int print_string(char *str, int fd)
{
        int len = _strlen(str) - 1;

        return (write(fd, str, len));
}

int print_number(int n, int fd)
{
        int digit_count = 0, i;
        int tmp;
        char *num;

        if (n == 0)
                return (_putchar('0', fd));

        tmp = n;
        while (tmp)
        {
                digit_count++;
                tmp /= 10;
        }
        num = malloc(sizeof(char) * digit_count + 1);

        i = 0;
        while (i < digit_count)
        {
                num[digit_count - 1 - i] = n + '0';
                i++;
        }
        num[digit_count] = '\0';
        tmp = write(fd, num, digit_count);
        free_arr(num);
        return (tmp);

}