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
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	newnode->next = *stack;
	newnode->prev = NULL;
	newnode->n = number;
	if (*stack)
		(*stack)->prev = newnode;
	*stack = newnode;
}
void pall(stack_t **stack, unsigned int nline)
{
        stack_t *temp;
        (void)nline;

        temp = *stack;
        while (temp)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }
}
