#include "monty.h"

/**
 * _strlen - Return string of length
 * @s: String
 *
 * Return: string of length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{

	}

	return (i);
}

/**
 * _strncat - Concatenate strings
 * @dest: First string
 * @src: Second string
 *
 * Return: Concatenation
 */
char *_strncat(char *dest, char *src)
{
	int l = _strlen(dest);
	int i = 0;

	while (*src)
	{
		dest[l + i] = *src;
		src++;
		i++;
	}

	dest[i + l] = '\0';
	return (dest);
}

/**
 * _isdigit - checks for a digit from 0 to 9
 * @str: the integer to be checked
 *
 * Return: 1 if is digit, 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
