#include "monty_proto.h"
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
	(*stack) = (*stack)->next;
	if (temp == NULL)
	{
		printf("L<%d>: can't add, stack too short\n", num);
		errorHandling = 1;
	}
	else
	{
		(*stack)->n = temp->n + (*stack)->n;
		free(temp);
		temp = *stack;
		(*stack)->prev = NULL;
	}
}
