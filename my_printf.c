/**
 * File: my_printf.c
 * Authors: Abenezer Kifle & Fabrice RANDRIATSIMIVONY
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * print: prints a given string on the console.
 * @str: a string to be printed on the console.
 *
 * Return: returns the number of characters.
 */
int print(char *str, ...)
{
    va_list vl;
    int i = 0, j = 0;
    char buff[100] = {0}, tmp[20];
    va_start(vl, str);
    while (str && str[i])
    {
        buff[j] = str[i];
        j++;
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    return j;
}