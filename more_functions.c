#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;

	if (*stack && (*stack)->next)
	{
		mem = (*stack)->next;
		(*stack)->next = mem->next;
		(*stack)->prev = mem;
		mem->next = *stack;
		mem->prev = NULL;
		*stack = mem;
	}
	else
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

