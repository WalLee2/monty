#include "monty.h"
/**
 *push_func - opcode that calls add_node to start creating the linked list.
 *@stack: Reference to the linked list.
 *@num: The line number being evaluated.
 */
void push_func(stack_t **stack, unsigned int num)
{
	int outcome;

	outcome = add_node(stack, num);
	if (outcome != 0)
	{
		printf("L<%d>: usage: push integer\n", num);
		errorHandling = 1;
	}
}
/**
 *pall_func - function that is called to print everything to stdout.
 *@stack: Reference to the linked list.
 *@num: The line number being evaluated.
 */
void pall_func(stack_t **stack, unsigned int num)
{
	(void)num;
	print_list(stack);
}
/**
 *pint_func - function that prints the number in node to stdout.
 *@stack: Reference to the doubly linked list
 *@num: The line number being evaluated.
 */
void pint_func(stack_t **stack, unsigned int num)
{

	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		printf("L<%d>: can't pint, stack empty\n", num);
		errorHandling = 1;
	}
}
/**
 *pop_func - the function that removes the top element of the stack
 *@stack: Reference to the doubly linked list.
 *@num: The line number being evaluated.
 */
void pop_func(stack_t **stack, unsigned int num)
{
	stack_t *temp;

	temp = *stack;
	if (stack != NULL)
	{
		while ((*stack)->prev != NULL)
		{
			*stack = (*stack)->prev;
			printf("pop_func: %d\n", temp->n);
		}
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
		return;
	}
	printf("L<%d>: can't pop an empty stack", num);
	errorHandling = 1;
}
/**
 *swap_func - Function that swaps the number of the top two doubly linked list.
 *@stack: Reference to the doubly linked list.
 *@num: The line number being evaluated.
 */
void swap_func(stack_t **stack, unsigned int num)
{
	stack_t *temp;
	int help;

	temp = *stack;
	temp = temp->next;
	if (temp == NULL)
	{
		printf("L<%d>: can't swap, stack too short\n", num);
		errorHandling = 1;
	}
	else
	{
		help = temp->n;
		temp->n = (*stack)->n;
		(*stack)->n = help;
	}
}
