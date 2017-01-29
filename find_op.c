#include "monty.h"
/**
 *find_op - Function that finds the requested opcode
 *@tok_u_input: Tokenized user input
 *@stack: Reference to the linked list
 *@l_num: Line number of the current line being evaluated.
 *Return: 0 on success, 1 on error/failure
 */
int find_op(char *tok_u_input, stack_t **stack, unsigned int l_num)
{
	int a;
	instruction_t key[] = {
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{NULL, NULL}
	};
	for (a = 0; key[a].opcode != NULL; a++)
	{
		if (strcmp(tok_u_input, key[a].opcode) == 0)
		{
			key[a].f(stack, l_num);
			return (errorHandling);
		}
	}
	if (key[a].opcode == NULL)
	{
		printf("L%u:unknown instruction %s\n", l_num, tok_u_input);
		errorHandling = 1;
		return (errorHandling);
	}
	return (0);
}
