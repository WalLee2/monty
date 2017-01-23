#include "monty_proto.h"
/**
 *
 *
 *
 */
void push_func(stack_t **stack, int num)
{
	int outcome;

	outcome = add_node(stack, num);
	if (outcome != 0)
	{
		printf("L<%d>: usage: push integer\n", num);
		exit(EXIT_FAILURE);
	}
}
/*      for(i = 1; argv[i] != '\0'; i++)
        {
                if (argv[1] == NULL || argv[1] == '\0')
                {
                        printf("L<line_number>: usage: push integer\n");
                        exit(EXIT_FAILURE);
                }
                u_input = atoi(argv[i]);
                if !(u_input >= 48 && u_input <= 57)
                {
                        printf("L<line_number>: usage: push integer\n");
                        exit(EXIT_FAILURE);
                }
*/
