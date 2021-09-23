#include "monty.h"

/**
 * free_stack - Free list
 * @head: list
 *
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *h;

	while (head != NULL)
	{
		h = head->next;
		free(head);
		head = h;
	}
}
