#include "monty.h"
int number;
void push(stack_t **stack, unsigned int nline)
{
	stack_t *newnode;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		malloc_error();
	}

	newnode->next = *stack;
	newnode->prev = NULL;
	newnode->n = number;
	if (*stack)
		(*stack)->prev = newnode;
	*stack = newnode;
}
