#include "monty.h"

/**
 * nopen - Prints error if file doesn't open
 * @fp: file
 * @str: name of file
 *
 * Return: 0
 */

void nopen(FILE *fp, char *str)
{
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
}
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

	global.lnum = 1;
	if ((argc != 2) || (*(argv[1] + strlen(argv[1]) - 2) != '.'))
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}
	file_name = _strncat(raiz, argv[1]);
	fp = fopen(file_name, "r");
	nopen(fp, argv[1]);
	while ((line_size = getline(&line, &len, fp)) != EOF)
	{
		line[line_size - 1] = '\0';
		token = strtok(line, " \t\n");
		cmd = token;
		if (cmd != NULL && cmd[0] != '#')
		{
			token = strtok(NULL, " \t\n");
			global.args = token;
			matcher(cmd)(&stack, global.lnum);
		}
		global.lnum++;
	}
	fclose(fp);
	free_stack(stack);
	return (0);
}
