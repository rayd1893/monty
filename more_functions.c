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
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - Multiplies the second top element of the stack with the top elements
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;
	int n1, n2, mult;

	if (*stack && (*stack)->next)
	{
		n1 = (*stack)->n;
		n2 = ((*stack)->next)->n;
		mult = n1 * n2;
		mem = (*stack)->next;
		mem->n = mult;
		mem->prev = NULL;
		mem->next = ((*stack)->next)->next;
		(*stack)->prev = mem;
		*stack = mem;
	}
	else
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * div - Divides the second top element of the stack
 * sub - Substract the second top element of the stack
 * with the top element of the stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */

void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;
	stack_t *mem2;
	int div = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		mem2 = (*stack)->next;
		div = mem2->n / (*stack)->n;
		mem = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(mem);
		(*stack)->n = div;
	}
	else
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * sub - Substract the second top element of the stack
 * with the top element of the stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *mem;
	int n1, n2, sub;

	if (*stack && (*stack)->next)
	{
		n1 = (*stack)->n;
		n2 = ((*stack)->next)->n;
		sub = n2 - n1;
		mem = (*stack)->next;
		mem->n = sub;
		mem->prev = NULL;
		mem->next = ((*stack)->next)->next;
		(*stack)->prev = mem;
		*stack = mem;
	}
	else
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
