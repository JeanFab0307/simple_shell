#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strlen - gets the lenght of a string
 * @str: the string
 *
 * Return: the lenght of the string with the null terminated byte '\0'
 */
int _strlen(char *str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
			i++;
	}
	return (i + 1);
}

/**
 * strtow - splits a string into words
 * @str: the string to split by a given character
 * @c: a given character to split th string
 *
 * Return: an array of the strings splited
 * Or NULL if failed
 */

char **strtow(char *str, char c)
{
	int i = 0, j = 0, size = 0, n = 0;
	char **buffer = NULL;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != c && i == 0) ||
		    (str[i] != c && str[i - 1] == c))
			size++;
	}
	if (size == 0)
		return (NULL);
	buffer = malloc(sizeof(*buffer) * ++size);
	if (buffer == NULL)
		return (NULL);
	buffer[--size] = '\0', size = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != c)
			size++;
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			buffer[n] = NULL;
			buffer[n] = malloc(sizeof(char) * size + 1);
			if (buffer[n] == NULL)
			{
				for (j = 0; j <= n; j++)
					free(buffer[j]);
			}
			while (j < size)
			{
				buffer[n][j] = str[i - size + 1 + j];
				j++;
			}
			buffer[n][size] = '\0';
			size = 0, j = 0, n++;
		}
	}
	return (buffer);
}

/**
 * _strdup - returns a pointer to a new space in mem which a given string
 * @str: the string to return
 *
 *Return: a duplicate of str or NULL if str =null or insufficient in memory
 */
char *_strdup(char *str)
{
	char *buffer = NULL;
	unsigned int i;
	unsigned int len;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);

	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		buffer[i] = str[i];
	return (buffer);
}

/**
 * _strcat - concatenates two strings
 * @dest: the string where we concatenates
 * @src: the string concatenated
 *
 *Return: the concatenation of dest and src
 */
char *_strcat(char *dest, char *src)
{
	int len1;
	int len2;
	int i;

	len1 = _strlen(dest);
	len2 = _strlen(src);
	i = 0;
	while (i < len2)
	{
		dest[i + len1] = src[i];
		i++;
	}
	return (dest);
}

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 *Return: the concatenated string or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *buffer;
	unsigned int i;
	unsigned int len1;
	unsigned int len2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = _strlen(s1) - 1;
	len2 = _strlen(s2) - 1;

	buffer = malloc(len1 + len2 + 1);
	if (buffer == NULL)
		return (NULL);
	for (i = 0; s1[i]; i++)
		buffer[i] = s1[i];
	for (i = 0; s2[i]; i++)
		buffer[len1 + i] = s2[i];
	buffer[len1 + len2] = '\0';
	free_arr(s1);
	return (buffer);
}
