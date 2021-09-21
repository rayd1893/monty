#include "monty.h"

int main (int argc, char **argv)
{
	char ch;
	char *file_name;
	FILE *fp;
	(void)argc;

	file_name = "./bytecodes/00.m";

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("The contents of %s file are:\n", file_name);

	while((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);
	return 0;
}
