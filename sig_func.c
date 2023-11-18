#include "shell.h"

/**
 * func_sigint - the required Signal handler
 * @sig: required Signal number
 *
 * Return: Nothing
 */
void func_sigint(int sig)
{
	(void) sig;
	_putchar('\n');
	func_prompt();
}

/**
 * func_sigquit - the required Signal handler for quiting
 * @sig: Signal number
 *
 * Return: Nothing
 */
void func_sigquit(int sig)
{
	(void) sig;
	f_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * func_sigstp - the required Signal handler for stoping
 * @sig: Signal number
 *
 * Return: Nothing
 */
void func_sigstp(int sig)
{
	(void) sig;
	f_put("\n");
	func_prompt();
}
