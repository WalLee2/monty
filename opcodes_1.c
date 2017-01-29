#include "monty.h"
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
	else if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", num);
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
	if (temp != NULL)
	{
		*stack = (*stack)->next;
		free(temp);
		if (*stack != NULL)
			(*stack)->prev = NULL;
		return;
	}
	printf("L%u: can't pop an empty stack\n", num);
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
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", num);
		errorHandling = 1;
	}
	if (errorHandling != 1)
	{
		help = temp->n;
		temp->n = temp->next->n;
		temp->next->n = help;
	}
}
