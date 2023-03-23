#include "monty.h"

void free_stack(stack *top)
{
    while(top != NULL)
    {
        temp = top->next;
        free(top);
        top = temp;
    }
    free(top);
}
