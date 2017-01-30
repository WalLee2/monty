#include "monty.h"
/**
 *keyw_check - Function that looks for the opcode.
 *@u_input: The user input passed from the getline function.
 *@l_num: Line number of the user input being evaluated.
 *@stk: The head pointer for doubly linked list.
 *Return: 0 on success, 1 on failure/error
 */
int keyw_check(char *u_input, unsigned int l_num, stack_t **stk)
{
	char *output, *tok_u_input;
	int check, num;

	check = num = 0;
	tok_u_input = strtok(u_input, "\n \t");
	if (tok_u_input == NULL || strcmp(tok_u_input, "nop") == 0)
		return (1);
	if (strcmp(tok_u_input, "push") == 0)
	{
		output = strtok(NULL, "\n \t");
		if (output == NULL)
		{
			printf("L%u: usage: push integer\n", l_num);
			errorHandling = 1;
			return (1);
		}
		if (Chk(output, l_num) == 0)
		{
			num = atoi(output);
			check = add_node(stk, num);
			if (check != 0)
				return (1);
		}
	}
	else
	{
		check = find_op(tok_u_input, stk, l_num);
		if (check != 0)
			return (1);
	}
	return (0);
}
