#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @stack: Something
 * @line_number: Something
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	int line_number = 0;

	newNode = malloc(sizeof(stack_t));

	newNode->n = line_number;
	newNode->next = *stack;
	newNode->prev = NULL;

	if ((*stack) !=NULL)	
		(*stack)->prev = newNode;
	(*stack) = newNode;
}
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *valnode = *stack;

	while (valnode !=NULL)
	{
		printf("%d/n", valnode->n);
	}
}
