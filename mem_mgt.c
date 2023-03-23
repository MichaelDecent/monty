#include "monty.h"
/**
 * free_stack - frees the stack
 * @top: a pointer to the headnode
 *
 */

void free_stack(stack_t *top)
{
	stack_t *temp;

	while(top != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
    	}
	free(top);
}
