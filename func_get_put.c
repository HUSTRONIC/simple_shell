#include "shell.h"

static char *l_put;
/**
 * func_get_put -This Reads the required
 * line from the user.
 *
 * Return: Pointer to a buffer conatining the user's input.
*/
char *func_get_put(void)
{
	char *my_input = NULL;
	size_t my_input_size = 0;
	ssize_t nread;

	do {
		/* print shell prompt */
		func_prompt();

		/* get a line of input from user */
		nread = getline(&my_input, &my_input_size, stdin);

		/* check for EOF or error */
		if (nread == -1)
		{
			free(my_input);
			f_put("\n");
			return (NULL);
		}

		/* remove trailing newline character */
		my_input[nread - 1] = '\0';

	} while (my_input[0] == '\0' || isspace(my_input[0]));

	/* update last_input to point to the new input */
	l_put = my_input;
	return (my_input);
}

/**
 * f_l_put - this will Free the most recent input.
 *
 * This function frees the memory allocated for the most recent input string
 * entered by the user. It should be called after the input string is no longer
 * needed.
 */
void f_l_put(void)
{
	free(l_put);
	l_put = NULL;
}
