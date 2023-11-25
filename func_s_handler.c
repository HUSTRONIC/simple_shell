#include "shell.h"

/**
 * func_sigint - This is the handler
 * 		 for SIGINT (Ctrl+C)
 * @sig: 	The required Signal number
 *
 * Return: NULL
 */
void func_sigint(int sig)
{
	(void) sig;
	_putchar('\n');
	func_prompt();
}

/**
 * func_sigquit - The handler for the
 * 		 required SIGQUIT (Ctrl+\)
 * @sig: 	The required Signal number
 *
 * Return: NULL
 */
void func_sigquit(int sig)
{
	(void) sig;
	f_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * func_sigstp - The handler for the required
 * 		 SIGTSTP (Ctrl+Z)
 * @sig: 	The required Signal number
 *
 * Return: NULL
 */
void func_sigstp(int sig)
{
	(void) sig;
	f_put("\n");
	func_prompt();
}
