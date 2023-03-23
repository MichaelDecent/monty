#include "monty.h"
/**
 * push - An opcode that adds an element to the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number where the opcode is found
 *
 */
void push_int(stack_t **top, unsigned int line_number)
{
	int i, m = 0, flag = 0;

	if (bus.oparg)

	if (oparg == NULL && atoi(oparg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line_content);
		free(*top);
		exit(EXIT_FAILURE);
	}
	
	n = atoi(oparg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)

	{
		if (bus.oparg[0] == '-')
			m++;
		for (; bus.oparg[m] != '\0'; m++)
		{
			if (bus.oparg[m] > 57 || bus.oparg[m] < 48)
				flag = 1; 
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); 
		}
	}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); 
	}
	i = atoi(bus.oparg);
	if (bus.lifi == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
/**
 * print_all - An opcode that prints all the elements in the file
 * @stack: a pointer to the head of the stack
 * @line_number: the line number where the opcode is found
 */
void print_all(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *top;
	if (temp == NULL)
		return;
	else
	{
		while(temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
