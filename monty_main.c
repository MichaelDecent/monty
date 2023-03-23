#define _GNU_SOURCE
#include "monty.h"
#include "glob_v"
#include <stdio.h>
#include <stdlib.h>

bus_t bus = {NULL, NULL, NULL, 0};

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
	size_t n = 0;
	char *opcode;
	int line_number = 1;
	ssize_t nread = 1;
	char* line_content = NULL;
	
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
	while (nread > 0)
	{
<<<<<<< HEAD
		nread = getline(&line_content, &n, file)
		bus.content = line_content;
		line_number++;
		if (nread > 0)
=======
		/*printf("line_content => %s", line_content);*/
		if (line_content)
>>>>>>> 019a7f6b4bcb8d7228ddf9b2fc036c3271587e35
		{
			handle_opcode(line_content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
