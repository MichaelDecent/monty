#include "monty.h"
/**
 * free_stack - frees the stack
 * @top: a pointer to the headnode
 *
 */

void free_stack(stack_t *top)
{
	stack_t *temp;

	temp = top;
	while(top != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}
/**
* f_stack - function that prints the top
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

