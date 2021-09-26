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
