#include "monty.h"
void (*get_op_code(line_t line, meta_t *meta))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
                {"push", push},
                {NULL, NULL}
        };

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[o]) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line.number, line.content[0]);
	exit(EXIT_FAILURE);
}
