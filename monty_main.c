#define _GNU_SOURCE
#include "monty.h"
#include "glob_v"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - interprete the monty byte codes in a file
 * @ac: number of arguments
 * @av: an array of agruments
 *
 * Return: 1 always;
 */
int main(int ac, char**av)
{
	FILE *file;
	stack_t *stack = NULL;
	char *line_content = NULL;
	size_t n = 0;
	char *opcode;
	int line_number = 1;
	int nread;
	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line_content, &n, file)) != -1)
	{
		opcode = strtok(line_content, " \n\t");
		oparg = strtok(NULL, " \n\t");
		if (opcode)
		{
			if (handle_opcode(opcode, line_number, &stack) == -1)
			{
				fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
				fclose(file);
				free(line_content);
				free(stack);
				exit(EXIT_FAILURE);
			}
			free(line_content);
		}
		line_number++;
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
