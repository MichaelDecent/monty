#include "monty.h"
/**
 * handle_opcode - It executes the opcodes in the file
 * @opcode: the opcode read
 * @line_number: the line number where the opcode is found
 * @stack: a pointer to the stack
 *
 * Return: 0 if successful and 1 if failed
 */
int handle_opcode(char *line_content, stack_t **stack, unsigned int line_number, FILE *file)
{
	unsigned int i = 0;
	char *opcode;

	instruction_t ops_array[] = {
		{"push", f_push},
		{"pall", f_pall},
		{NULL, NULL} 
	};
	opcode = strtok(line_content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.oparg = strtok(NULL, " \n\t");
	while (ops_array[i].opcode && opcode)
	{
		if(strcmp(opcode, ops_array[i].opcode) == 0)
		{
			ops_array[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && ops_array[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(line_content);
		free_stack(*stack);
		exit(EXIT_FAILURE); 
	}
	return (1);
}
