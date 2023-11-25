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
	char **r = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		r = realloc(r, sizeof(char *) * (i + 1));
		if (r == NULL)
			return (NULL);

		r[i] = malloc(f_strlen(token) + 1);
		if (!(r[i]))
			return (NULL);

		f_strcpy(r[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size of the array*/
	r = realloc(r, (i + 1) * sizeof(char *));
	if (!r)
		return (NULL);

	r[i] = NULL;
	return (r);
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

	tmp = f_strdup(input);
	if (tmp == NULL)
	{
		f_put("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokennz(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}
