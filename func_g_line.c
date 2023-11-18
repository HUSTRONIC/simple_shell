#include "shell.h"

/**
 * func_g_line - Receive input from user.
 *
 * Return: input from the user.
*/
void *func_g_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int bf_ps, buf_size;
	char *input_str = NULL;
	char c_char;
	int in_len = 0;

	while (1)
	{
		if (bf_ps >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			bf_ps = 0;
			if (buf_size == 0)
				return (input_str);
			else if (buf_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		c_char = buffer[bf_ps];

		bf_ps++;

		if (c_char == '\n')
		{
			input_str = realloc(input_str, in_len + 1);
			input_str[in_len] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, in_len + 1);
			input_str[in_len] = c_char;
			in_len++;
		}
	}
}
