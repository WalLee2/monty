#include "monty.h"
/**
 *add_func - Giving the opcode add the ability to add the numbers stored
 *in the linked list and removing the first node on top of the stack.
 *@stack: The reference to the entire doubly linked list.
 *@num: Line number currently being evaluated.
 */
void add_func(stack_t **stack, unsigned int num)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", num);
		errorHandling = 1;
	}
	if (errorHandling != 1)
	{
		temp->next->n = temp->next->n + temp->n;
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
	}
}
