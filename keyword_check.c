#include "monty.h"
/**
 *keyw_check - Function that looks for the opcode.
 *@u_input: The user input passed from the getline function.
 *@l_num: Line number of the user input being evaluated.
 *@stk: The head pointer for doubly linked list.
 */
void keyw_check(char *u_input, int l_num, stack_t **stk)
{
	char *output, *tok_u_input; int a;
	instruction_t key[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{NULL, NULL}
	};
	tok_u_input = strtok(u_input, "\n \t");
	for (a = 0; tok_u_input != NULL && key[a].opcode != NULL; a++)
	{
		if (strcmp(tok_u_input, key[a].opcode) == 0)
		{
			if (strcmp(tok_u_input, "push") == 0)
			{
				output = strtok(NULL, "\n \t");
				if (output == NULL)
				{
					printf("L%d: usage: push ", l_num);
					printf("integer\n");
					errorHandling = 1;
				}
				else if (output != NULL)
					Chk(key, output, stk, l_num, a);
			}
			else if (strcmp(tok_u_input, "nop") == 0)
				continue;
			else
				key[a].f(stk, l_num);
			break;
		}
	}
	if (key[a].opcode == NULL)
	{
		printf("L%d:unknown instruction %s\n", l_num, u_input);
		errorHandling = 1;
	}
}
