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

	if (x == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lnum);
		exit(EXIT_FAILURE);
	}

	if (atoi(x) == 0 && *args != '0' && *x != '0')
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
	mem->n = atoi(x);
	mem->next = *stack;
	mem->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = mem;
	}
	*stack = mem;
	x = NULL;
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

/**
 * pop - Removes the top element of the stack
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{

    stack_t *tmp;

    if (*stack == NULL || stack == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
    }
    tmp = *stack;

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

    free(tmp);
    tmp = NULL;
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - Doesn’t do anything.
 * @stack: Linked list
 * @line_number: Line number
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
