#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	/* char **argin = malloc(10 * sizeof(char*));*/
	char *argin[];
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status; 

	

	printf("#cisfun$ ");
	while (1)
	{
		read = getline(&line, &len, stdin);
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			return (EXIT_FAILURE);
		}
		printf("%s", line);
		printf("#cisfun$ ");

		*(*(argin)) = *line;
		*(*(argin + 1)) = '\0';

		if ((child_pid = fork()) == 0)
		{
			/* Child */
			if (execve(line, argin, NULL) == -1)
			{
				perror("Error:");
			}

		} else
		{
			/* Parennt */
			wait(&status);
		}
	}


	free(argin);
	free(line);
	exit(EXIT_SUCCESS);
}
