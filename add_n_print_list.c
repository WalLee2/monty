#include "monty.h"
/**
 *add_node - Making the doubly linked list.
 *The framework for the stack and queue.
 *@head: The pointer that will hold reference to the list.
 *@num: The line number currently being evaluated.
 *Return: 0 on success.
 */
int add_node(stack_t **head, unsigned int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		errorHandling = 1;
	}
	if (*head != NULL)
	{
		while ((*head)->prev != NULL)
			*head = (*head)->prev;
		(*head)->prev = new;
	}
	new->n = num;
	new->prev = NULL;
	new->next = *head;
	*head = new;
	return (0);
}
/**
 *print_list - Function that prints the entire stack / queue to stdout.
 *@head: A pointer that holds reference to the entire linked list.
 */
void print_list(stack_t **head)
{
	stack_t *temp;

	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
