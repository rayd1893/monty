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
 * @n: bytes
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
