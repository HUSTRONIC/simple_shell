#include "shell.h"

/**
 * tokennz - pasing input to arguments.
 * @str: the string to tokeniz.
 * @delim:  delimiter.
 *
 * Return: an array of pointers,
 *         or NULL.
 */
char **tokennz(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (i + 1));
		if (ret == NULL)
			return (NULL);

		ret[i] = malloc(_strlen(token) + 1);
		if (!(ret[i]))
			return (NULL);

		_strcpy(ret[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size of the array*/
	ret = realloc(ret, (i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[i] = NULL;
	return (ret);
}

/**
 * tokennz_put - splits a user input.
 * @input: the user input string to be tokenized
 *
 * Return: an array of pointers, or NULL
 */
char **tokennz_put(char *input)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = _strdup(input);
	if (tmp == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}
