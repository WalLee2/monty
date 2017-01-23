#include "monty_proto.h"
/**
 *
 *
 */
int add_node(stack_t **head, int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (-1);
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
