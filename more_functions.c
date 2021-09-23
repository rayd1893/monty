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

/**
 * add - Add the top two elements of the stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;
	int n1, n2, sum;

	if (*stack && (*stack)->next)
	{
		n1 = (*stack)->n;
		n2 = ((*stack)->next)->n;
		sum = n1 + n2;
		mem = (*stack)->next;
		mem->n = sum;
		mem->prev = NULL;
		mem->next = ((*stack)->next)->next;
		(*stack)->prev = mem;
		*stack = mem;
	}
	else
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
