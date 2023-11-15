#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * ma_getline - reads a line of text from  the input stream.
 * @lineptr: A pointer to buffer store for the line.
 * @n: A pointer to the buffer size.
 * @stream: the file to read the text from.
 *
 * Return: Number of bytes read, otherwise -1 on error.
 */
ssize_t ma_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t x = 0;
	int c;
	ssize_t byte_count;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 1024;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		return (-1);
	}
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF)
		{
			if (x == 0)
				return (0);
			break;
		}
		if (x >= *n - 1)
		{
			*n *= 2;
			char *lineptr2 = (char *)realloc(*lineptr, *n);
			if (lineptr2 == NULL)
				return (-1);
			*lineptr = lineptr2;
		}
		(*lineptr)[x++] = (char)c;
		if (c == '\n')
			break;
	}
	(*lineptr)[x] = '\0';
	byte_count = x;
	return (byte_count);
}
/**
 * main - entry point.
 *
 * return: 0 on success.
 */
int main(void)
{
	char *linptr = NULL;
	size_t count = 0;
	ssize_t txt_read;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		txt_read = ma_getline(&linptr, &count, stdin);
		if (txt_read == -1)
		{
			printf("Error while reading input\n");
			break;
		}
		else if (txt_read == 0)
			break;
		printf("%s", linptr);
	}
	free(linptr);
	return (0);
}
