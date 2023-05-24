/**
 * File: print_array.c
 * Authers: Abeniezer kifle & Fabrice RANDRIATSIMIVONY
 */
#include "my_printf.c"

/**
 * print_array: a method takes an array of string as an input and
 *              prints it using custome print method.
 *
 * @stringArray: an array of string to be printed.
 * @count: the count of strings on the array.
 */

void print_array(char **stringArray, int count)
{
    for (int i = 0; i < count; i++)
    {
        print(stringArray[i]);
    }
}