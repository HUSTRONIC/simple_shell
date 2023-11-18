#include "shell.h"

/**
 * main - implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *my_input;
	char **args;
	int _stat;

	/* Register signal handlers */
	signal(SIGINT, func_sigint);
	signal(SIGQUIT, func_sigquit);
	signal(SIGTSTP, func_sigstp);

	do {
		my_input = func_get_put();
		if (!my_input || !*my_input)/* EOF detected, exit the loop */
			break;

		args = tokennz_put(my_input);
		if (!args || !*args)
		{
			free(my_input);
			f_tok(args);
			continue;
		}
		_stat = func_exec(args);
		free(my_input);
		f_tok(args);

		/* Set status to 1 to continue the loop */
		_stat = 1;
	} while (_stat);

	return (EXIT_SUCCESS);
}
