#include "monty.h"

/**
 * push - Function to add element
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;
	(void) line_number;

	if (x == 0 && *args != '0')
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lnum);
		exit(EXIT_FAILURE);
	}
	mem = malloc(sizeof(stack_t));
	if (mem == NULL)
	{
		fputs("Error: malloc failed\n", stderr);
		exit(EXIT_FAILURE);
	}
	mem->n = x;
	mem->next = *stack;
	mem->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = mem;
	}
	*stack = mem;
}

/**
 * pall - Function to print elements form stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
