#include "monty.h"
/**
 * push - An opcode that adds an element to the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the line number where the opcode is found
 *
 */
void f_push(stack_t **top, unsigned int line_number)
{
	int i, m = 0, flag = 0;

	if (bus.oparg)
	{
		if (bus.oparg[0] == '-')
			m++;
		for (; bus.oparg[m] != '\0'; m++)
		{
			if (bus.oparg[m] > 57 || bus.oparg[m] < 48)
				flag = 1; 
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*top);
			exit(EXIT_FAILURE); 
		}
	}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n",line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE); 
	}
	i = atoi(bus.oparg);
	if (bus.lifi == 0)
		addnode(top, i);
	else
		addqueue(top, i);
}
/**
 * print_all - An opcode that prints all the elements in the file
 * @stack: a pointer to the head of the stack
 * @line_number: the line number where the opcode is found
 */
void f_pall(stack_t **top, unsigned int line_number)
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
/**
* f_swap - function that swaps the top two elements of the stack
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}

