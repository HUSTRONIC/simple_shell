#include "shell.h"

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

	ln = _strlen(str);
	n_write = write(STDOUT_FILENO, str, ln);
	if (n_write == -1)
	{
		perror("write");
	}
}

/**
 * f _puterror - this Prints the error message to output
 * @err:  message to print
 *
 * Return: Void
 */
void f_puterror(char *err)
{
	size_t ln;
	ssize_t n_write;

	ln = _strlen(err);
	n_write = write(STDERR_FILENO, err, ln);
	if (n_write == -1)
	{
		perror("write");
	}
}
