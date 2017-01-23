#include "monty_proto.h"
void keyw_check(char *tok_u_input, int l_num, stack_t **stk)
{
        char *output;
        int a, result;
	instruction_t key[] = {
		{"push", push_func},
                {NULL, NULL}
        };

        /*tok_u_input = strtok(u_input, "\n  \t");*/
	printf("I'm here before the struct loop\n");
        for (a = 0; key[a].opcode != NULL;)
        {
                if (strcmp(tok_u_input, key[a].opcode) == 0)
		{
			if (result == 0 && strcmp(tok_u_input, "push") == 0)
			{
				output = strtok(NULL, "\n \t");
				Chk(key, output, stk, l_num, a);
			}

/*                        if ((output[i] >= '0' && output[i] <= '9')
                            && output[i] != '\0' &&
                            output[i + 1] != >= 'a'  <= 'z' )
                        {
                                num = atoi(output);
                                funcs[a].f(stack, num);
                        }
                        else
                        {
				printf("L%d: usage: push integer", l_num);
				exit(EXIT_FAILURE);
                        }
                }
                else if (result == 1 && strcmp(tok_u_input, "pall") == 1)
                {
                        funcs[a].f();
		}
*/
		else if (result == -1)
			a++;
		}
	}
}
