#include "monty_proto.h"
/**
 *Chk - Checks to see if the input made by the user is an int or not
 *
 *
 */
void Chk(instruction_t key[], const char *out, stack_t **stack, int l_n, int a)
{
	int num, i, check;

	num = i = check = 0;
	for (i = 0; (out[i] >= '0' && out[i] <= '9') && out[i] != '\0'; i++)
	{
		if (out[i + 1] >= 'a' && out[i + 1] <= 'z')
			check = 1;
	}
	if (check == 0)
	{
		num = atoi(out);
		key[a].f(stack, num);
	}
	printf("L<%d>: usage: push integer", l_n);
	exit(EXIT_FAILURE);
}
