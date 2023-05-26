#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: the diff bettween s1 and s2 in int value
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
 * _atoi - convert a string that indicate a number to an int
 * @s: the string to convert
 *
 * Return: the int in the string
 * Or 0 if there are none
 */
int _atoi(char *s)
{
	int i = 0, j = 0;
	int res = 0;

	while (s[i])
	{
		if (s[i] == '-')
			j++;
		if (s[i] <= '9' && s[i] >= '0')
		{
			do {
				if (j % 2 == 0)
					res = res * 10 + (s[i] - '0');
				else
					res = res * 10 - (s[i] - '0');
				i++;
			} while (s[i] <= '9' && s[i] >= '0');
			break;
		}
		else
		{
			return (-1);
		}
	}
	return (res);
}
