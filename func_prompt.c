#include "shell.h"

/**
 *  func_prompt - this Prints the required prompt
 *  to the output
 * Return: void.
 */
void func_prompt(void)
{
	f_put(PROMPT);
	fflush(stdout);
}
