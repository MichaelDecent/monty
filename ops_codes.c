#include "monty.h"
/**
 * push - An opcode that adds an element to the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number where the opcode is found
 *
 */
void push_int(stack_t **top, unsigned int line_number)
{
	stack_t *new;
	stack_t *temp;
	int n;

	if (oparg == NULL || atoi(oparg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	n = atoi(oparg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*top == NULL)
		*top = new;
	else
	{
		temp = *top;
		*top = new;
		new->next = temp;
		temp->prev = new;
	}
}

void print_all(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*top == NULL)
		return;
	else
	{
		temp = *top;
		while(temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
