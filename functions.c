#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @queue: Something
 * @num: Something
 */
void push(stack_t **stack, unsigned int num)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	newNode->n = num;
	newNode->next = *stack;
	newNode->prev = NULL;

	if ((*stack) !=NULL)	
		(*stack)->prev = newNode;
	(*stack) = newNode;
}
void pall(stack_t **stack, unsigned int num)
{
	stack_t *valnode = *stack;

	while (valnode !=NULL)
	{
		printf("%d/n", valnode->n);
	}
}
