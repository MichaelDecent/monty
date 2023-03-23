#include "monty.h"

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
	if (ops_array[i].opcode && opcode == NULL)
		return (-1);
	return (-1);
}
