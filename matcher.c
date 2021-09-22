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
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 2; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			return (instructions[i].f);
		}
	}

	return (NULL);
}
