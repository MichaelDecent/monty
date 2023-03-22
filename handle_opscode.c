#include "monty.h"

int handle_opcode(char *opcode, int line_number, stack_t *stack)
{
	int i;

	instruction_t ops_array[] = {
		{"push", push_int},
		{"pall", print_all},
		{NULL, NULL} 
	};
	
	while (ops_array[i].opcode != NULL)
	{
		if(strcmp(opcode, ops_array[i].opcode) == 0)
		{
			ops_array[i].f(&stack, line_number);
			return (1);
		}
		i++;
	}
	return (-1);
}
