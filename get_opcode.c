#include "monty.h"
void (*get_op_code(line_t line, meta_t *meta))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
                {"push", push},
		{"pall", pall},
                {NULL, NULL}
        };

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
	line.content[0]);
	free_stack(&(meta->stack));
	exit(EXIT_FAILURE);
}
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

        if (stack == NULL || *stack == NULL)
                return;

        while (*stack != NULL)
        {
                temp = (*stack)->next;
                free(*stack);
                *stack = temp;
        }
}
