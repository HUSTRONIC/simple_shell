#include "shell.h"

/**
 * my_path - checks for the command in a directory in a given path.
 * @command: this points to the looked for command.
 *
 * Return: pointer to string path (success),
 * else  NULL.
*/
char *my_path(char *command)
{
	struct stat st;
	int stat_ret, i;
	char buf[PATH_MAX_LENGTH], *path, *r, **dir;

	path = func_g_path();
	if (!path)
		return (NULL);
	dir = tokennz(path, PATH_SEPARATOR);
	if (!dir)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		f_memset(buf, 0, PATH_MAX_LENGTH);
		f_strcpy(buf, dir[i]);
		f_strcat(buf, "/");
		f_strcat(buf, command);
		stat_ret = stat(buf, &st);
		if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			f_tok(dir);
			r = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!r)
				return (NULL);
			strcpy(r, buf);
			return (r);
		}
	}
	if (stat_ret == -1)
		f_tok(dir);
	return (NULL);
}
