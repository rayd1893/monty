#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	printf("Se ingresó como parametro: %d\n", (**stack).n);
}


int main(void)
{
	void (*match)(stack_t **stack, unsigned int line_number);
	char *ins = "pall";
	stack_t *st = malloc(sizeof(stack_t *));
	unsigned int ln;

	ins = "pas";


        st->n = 1;
	st->next = NULL;

	ln = 1;

	match = matcher(ins);
	if (match == NULL)
	{
		printf("No cruza");
		return (1);
	}
	else
	{
		match(&st, ln);
	}

	return (0);
}
