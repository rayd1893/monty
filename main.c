#include "monty.h"

/**
 * main - Main function
 * @argc: Number of arguments
 * @argv: List of arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char ch;
	char raiz[98] = "./";
	char *file_name;
	FILE *fp;
	(void)argc;

	file_name = _strncat(raiz, argv[1]);

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("The contents of %s file are:\n", file_name);

	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);
	return (0);
}
