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
	/*printf("I'm here before tokenizing user input\n");*/
	tok_u_input = strtok(u_input, "\n \t");
	if (tok_u_input == NULL || strcmp(tok_u_input, "nop") == 0)
		return (1);
	/*printf("tok_u_input: %s\n", tok_u_input);*/
	if (strcmp(tok_u_input, "push") == 0)
	{
		output = strtok(NULL, "\n \t");
		if (output == NULL)
		{
			printf("L%d: usage: push integer\n", l_num);
			errorHandling = 1;
			return (1);
		}
		/*printf("I'm here after output, output value: %s\n", output);*/
		if (Chk(output, l_num) == 0)
		{
			num = atoi(output);
			/*printf("evaluation of num: %d\n", num);*/
			check = add_node(stk, num);
			/*printf("I'm here after check, value of check: %d\n", check);*/
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
