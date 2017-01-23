#include "monty_proto.h"
/**
 *
 *
 */
int main(int argc, char *argv[])
{
        char *u_input, *tok_u_input;
        FILE *fp;
        size_t num;
	int l_num;
        stack_t *head;

	head = NULL;
        if (argc != 2)
        {
                printf("USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        fp = fopen(argv[1], O_RDONLY);
        if (fp == NULL)
                printf("Error: Can't open file %s", argv[1]);
	printf("Error checked successfully after opening file\n");
/*        stack = malloc(sizeof(stack_t));
        if (stack == NULL)
                return (NULL);
        if (*head != NULL)
        {
                while ((*head)->prev != NULL)
                        *head = (*head)->prev;
                (*head)->prev = stack;
        }
        stack->prev = NULL;
*/
        l_num = 1;
	printf("I'm here before getline\n");
	num = 0;
        for (l_num = 1; (getline(&u_input, &num, fp)) != -1; l_num++)
        {
		printf("line_number = %d, user_input = %s", l_num, u_input);
		tok_u_input = strtok(u_input, "\n  \t");
                keyw_check(tok_u_input, l_num, &head);
        }
	return (0);
}
