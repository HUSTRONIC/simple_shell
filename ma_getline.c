#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define WORD_LIMIT 100

/**
 * my_prompt - Display the shell prompt.
 */
void my_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * main - Simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char read[WORD_LIMIT];
	pid_t my_d = fork();

	while (1)
	{
		my_prompt();
		if (fgets(read, sizeof(read), stdin) == NULL)
		{
			printf("\nsleep time. :)\n");
			break;
		}

		read[strcspn(read, "\n")] = '\0';

		if (my_d < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (my_d == 0)
		{
			if (execlp(read, read, (char *)NULL) == -1)
			{
				fprintf(stderr, "Error: Command '%s' not found.\n", read);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(my_d, NULL, 0);
		}
	}

	return (0);
}

