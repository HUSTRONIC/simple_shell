#include "shell.h"

/**
 * func_exec - This executes the required command.
 * @argv: the required array of strings that contain
 * the command and its arguments.
 *
 * Return: exit status of the command to be executed.
 */
int func_exec(char **argv)
{
	pid_t id;
	int _stat = 0;
	char *cmd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (_stat);
	if (check_built(argv))
		return (_stat);

	id = fork();
	if (id < 0)
	{
		f_puterror("fork");
		return (1);
	}
	if (id == -1)
		perror(argv[0]), f_tok(argv), f_l_put();
	if (id == 0)
	{
		envp[0] = get_path();
		envp[1] = NULL;
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = my_path(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]), f_tok(argv), f_l_put();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(id, &_stat, WUNTRACED);
		} while (!WIFEXITED(_stat) && !WIFSIGNALED(_stat));
	}
	return (_stat);
}
