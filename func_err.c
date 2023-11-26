#include "shell.h"
#include <stdio.h>

/**
 * f_put - display a string to the stream
 * @str: required string to be output
 *
 * Return: Void
 */
void f_put(char *str)
{
	size_t ln;
	ssize_t n_write;

	ln = f_strlen(str);
	n_write = write(STDOUT_FILENO, str, ln);
	if (n_write == -1)
	{
		perror("write");
	}
}

/**
 * f_puterror - this prints the error message to the  output.
 * @err:  message to be printed.
 *
 * Return: Void
 */
void f_puterror(char *err)
{
	size_t ln;
	ssize_t n_write;

	ln = f_strlen(err);
	n_write = write(STDERR_FILENO, err, ln);
	if (n_write == -1)
	{
		perror("write");
	}
}
