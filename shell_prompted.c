#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define WORD_LIMIT 124

/**
 * main - entry point
 *
 * Return: void
 */
int main(void)
{
	int t;
	pid_t mypid;
	char word[WORD_LIMIT];
	char *s[2];
	char *environ[] = {NULL};

	while (1)
	{
	fprintf(stdout, "cisfun$ ");
	fflush(stdout);

	if (fgets(word, WORD_LIMIT, stdin) == NULL)
	{
		fprintf(stdin, "\n");
		break;
	}
	word[strcspn(word, "\n")] = '\0';
	mypid = fork();

	if (mypid == -1)
	{
	fprintf(stderr, "fork failed");
	exit(98);
	}
	else if (mypid == 0)
	{	s[0] = word;
		s[1] = NULL;
		if (execve(s[0], s, environ) == -1)
		{
		fprintf(stderr, "./shell_prompted: No such file or directory\n");
		exit(99);
		}
	}
	else
	{
		waitpid(mypid, &t, 0);
	}
	}
	return (0);
}
