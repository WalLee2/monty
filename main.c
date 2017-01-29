#include "monty.h"

int errorHandling = 0;
/**
 *main - function that reads from file and looks for opcodes
 *@argc: Number of arguments passed
 *@argv: Storing the user input as an array of characters.
 *Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	char *u_input;
	FILE *fp;
	size_t num;
	int l_num;
	stack_t *head;

	head = NULL;
	fp = NULL;
	u_input = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	l_num = 1;
	num = 0;
	for (l_num = 1; (getline(&u_input, &num, fp)) != -1; l_num++)
	{
		if (strcmp(u_input, "nop"))
			keyw_check(u_input, l_num, &head);
		if (errorHandling != 0)
		{
			free_this(u_input, head, fp);
			exit(EXIT_FAILURE);
		}
	}
	free_this(u_input, head, fp);
	return (0);
}
