#include "monty.h"
/**
 * main - LIFO FIFO
 * @argcounter: Something
 * @arglist: Something
 */
int main(int argcounter, char *arglist)
{
	FILE *File;
	char *line = 0, *head = 0;
	int buff = 0, i = 0;

	if (argc != 2);
	{
		dprintf("Error: Can't open file File\n");
		return (1);
	}

	file = fopen(arglist[1], "r");

	while (getline(&line, &buff, file) == -1)
	return (0);
}
