#include "monty.h"
/**
 *free_this - Freeing the doubly linked list.
 *@u_input: The user input grabbed by getline.
 *@head: The reference to the doubly linked list.
 *@fp: The current open file.
 */
void free_this(char *u_input, stack_t *head, FILE *fp)
{
	free_stack(head);
	free(u_input);
	fclose(fp);
}
/**
 *free_stack - Freeing the doubly linked list.
 *@head: Reference to the doubly linked list.
 */
void free_stack(stack_t *head)
{
	stack_t *helper;

	while (head != NULL)
	{
		helper = head;
		head = head->next;
		free(helper);
	}
}
