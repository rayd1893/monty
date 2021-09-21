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
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("The contents of %s file are:\n", file_name);

	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);
	return (0);
}
