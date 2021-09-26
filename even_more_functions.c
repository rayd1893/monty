#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;
	stack_t *mem2;
	int mod = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		mem2 = (*stack)->next;
		mod = mem2->n % (*stack)->n;
		mem = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(mem);
		(*stack)->n = mod;
	}
	else
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;

	mem = *stack;
	if (mem == NULL)
	{
		free_stack(*stack);
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (mem->n >= 128 || mem->n < 0)
	{
		free_stack(*stack);
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", mem->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;

	mem = *stack;
	if (line_number)
	while (mem)
	{
		printf("%c", mem->n);
		mem = mem->next;
	}
	printf("\n");
}
