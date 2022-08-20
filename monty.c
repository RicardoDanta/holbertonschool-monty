#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	readfile(file)
	return (EXIT_SUCCESS);
}
void readline(line_t *line, char *buffer)
{
	unsigned int i;
	char *token = NULL;

	 line->content = malloc(sizeof(char *));
	 if (!line->content)
		 malloc_error();
	 token = strtok(buffer, " '\n'");
	  for (i = 0; token && i < 2; i++)
	  {
		   line->content[i] = token;
		   token = strtok(NULL, " \n");
	  }
	  line->content[i] = NULL;
}
void readfile(FILE *file)
{
	size_t size = 0;
	meta_t *meta = NULL;
	line_t line;

	 meta = malloc(sizeof(meta_t));
	 if (!meta)
		 malloc_error();
	 line.number = 0;
	 line.content = NULL;

	 meta->file = file;
	 meta->stack = NULL;
	 meta->buf = NULL;

	 while (getline(&(meta->buf), &size, meta->file) != -1)
	 {
		  line.number++;
		  parseline(&line, meta->buf);
		  if (line.content)
			  get_op_code(line, meta)(&(meta->stack), line.number);
	 }
	 fclose(meta->file);

}
void malloc_error(void)
{
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
}
