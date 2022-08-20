#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>

/* stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct line
{
        unsigned int number;
        char **content;
} line_t;

typedef struct meta_s
{
        char *buf;
        stack_t *stack;
        FILE *file;
} meta_t;

void (*get_op_code(line_t line, meta_t *meta))(stack_t **, unsigned int);
void readfile(FILE *file);
void readline(line_t *line, char *buffer);
void malloc_error(void);

void free_stack(stack_t **stack);
void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);

#endif
