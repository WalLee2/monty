#include "monty.h"
/**
 *Chk - Checks to see if the input made by the user is an int or not
 *@out: The next character in the same string of the user input
 *@l_n: Line number of the user input being evaluated.
 *Return: 0 on success, 1 on failure/error
 */
int Chk(const char *out, unsigned int l_n)
{
	int i, check;

	i = check = 0;
	if (out == NULL)
		return (1);
	for (i = 0; out[i] != '\0'; i++)
	{
		if (out[i] < '0' || out[i] > '9')
		{
			printf("L%d: usage: push integer\n", l_n);
			errorHandling = 1;
			return (1);
		}
	}
	return (0);
}
