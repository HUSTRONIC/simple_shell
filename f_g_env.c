#include "shell.h"

/**
 * f_g_env - This gets the value of
 * the required environment.
 * @name: The environment name
 *
 * Return: the environment variable name, else NULL
 */
char *f_g_env(const char *name)
{
	char **env;
	size_t nm_len = f_strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (f_strncmp(*env, name, nm_len) == 0 && (*env)[nm_len] == '=')
		{
			return (&(*env)[nm_len + 1]);
		}
	}

	return (NULL);
}
