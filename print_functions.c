#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - print a single char
 * @c: the character
 * @fd: the file descriptor where the char is printed
 *
 * Return: 1 on success
 * Or 0 on failure
 */
int _putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * print_string - print an array of character
 * @str: the array of char
 * @fd: the file descriptor where the char is printed
 *
 * Return: the number of char printed
 */
int print_string(char *str, int fd)
{
	int len = _strlen(str) - 1;

	return (write(fd, str, len));
}

/**
 * print_number - print an int
 * @n: the int
 * @fd: the file descriptor where the char is printed
 *
 * Return: the number of char printed
 */
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
	if (n < 0)
		digit_count++;
	num = malloc(sizeof(char) * digit_count + 1);

	i = 0;
	tmp = n;
	while (n)
	{
		if (tmp > 0)
			num[digit_count - 1 - i] = n % 10 + '0';
		else if (tmp < 0)
			num[digit_count - 1 - i] = -(n % 10) + '0';
		n /= 10;
		i++;
	}
	if (tmp < 0)
		num[0] = '-';
	num[digit_count] = '\0';
	tmp = write(fd, num, digit_count);
	free_arr(num);
	return (tmp);
}

/**
 * _fprintf - print on a file descriptor
 * @fd: the file descriptor where the char is printed
 * @format: the format of the print, order of arguments
 *
 * Return: the number of char printed
 */
int _fprintf(int fd, char *format, ...)
{
	int printed = 0, i = 0;
	va_list arg;

	va_start(arg, format);
	while (format[i])
	{
		switch (format[i])
		{
		case 's':
			printed += print_string(va_arg(arg, char*), fd);
			break;
		case 'd':
			printed += print_number(va_arg(arg, int), fd);
			break;
		default:
			break;
		}
		i++;
	}
	va_end(arg);
	return (printed);
}
