#include "monty.h"
/**
 *Chk - Checks to see if the input made by the user is an int or not
 *@key: The array of structs that looks for the opcode string.
 *@out: The next character in the same string of the user input
 *@stack: The reference to head for the doubly linked list.
 *@l_n: Line number of the user input being evaluated.
 *@a: The reference to the array of structs when finding the opcode.
 */
void Chk(instruction_t key[], const char *out, stack_t **stack, int l_n, int a)
{
	int num, i, check;

	num = i = check = 0;
	for (i = 0; out[i] != '\0'; i++)
	{
		if (!(out[i] >= '0' && out[i] <= '9'))
		{
			printf("L<%d>: usage: push integer\n", l_n);
			errorHandling = 1;
		}
	}
	num = atoi(out);
	key[a].f(stack, num);
}
