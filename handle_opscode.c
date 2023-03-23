#include "monty.h"
/**
 * handle_opcode - It executes the opcodes in the file
 * @opcode: the opcode read
 * @line_number: the line number where the opcode is found
 * @stack: a pointer to the stack
 *
 * Return: 0 if successful and -1 if failed
 */
int handle_opcode(char *opcode, int line_number, stack_t **stack)
{
	int i;

	instruction_t ops_array[] = {
		{"push", push_int},
		{"pall", print_all},
		{NULL, NULL} 
	};
	i = 0;	
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
		return (-1);
	return (-1);
}
