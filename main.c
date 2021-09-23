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
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	int line_size = 0;
	char raiz[98] = "./";
	char *file_name;
	FILE *fp;
	char *token, *cmd;

	lnum = 1;

	if ((argc != 2) || (*(argv[1] + strlen(argv[1]) - 2) != '.'))
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}
	file_name = _strncat(raiz, argv[1]);
	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_size = getline(&line, &len, fp)) != EOF)
	{
		line[line_size - 1] = '\0';
		token = strtok(line, " \t\n");
		cmd = token;
		if (cmd != NULL && cmd[0] != '#')
		{
			token = strtok(NULL, " \t\n");
			args = token;
			if (args)
				x = args;
			matcher(cmd)(&stack, lnum);
		}
		lnum++;
	}
	fclose(fp);
	free_stack(stack);
	return (0);
}
