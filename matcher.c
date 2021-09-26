#include "monty.h"

/**
 * matcher - Function to compare instructions
 * @opcode: Instruction
 *
 * Return: Nothing
 */
void (*matcher(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"mul", mul},
		{"sub", sub},
		{"div", divi},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i;
	unsigned int line_number = global.lnum;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			return (instructions[i].f);
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
