#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	char **argin;
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i, k, j;


	argin = malloc(2 * sizeof(char *));

	if (argin == NULL)
		return (1);

	for (i = 0; i < 2; i++)
	{
		argin[i] = malloc(10 * sizeof(char));
		if (argin[i] == NULL)
		{
			for (k = 0; k < i; k++)
			{
				free(argin[k]);
			}
			free(argin);
			return (1);
		}

		for (j = 0; j < 10; j++)
		{
			argin[i][j] = 0;
		}
	}



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


		argin[0][0] = strdup(*line);
		argin[0][1] = strdup(NULL);




		if ((child_pid = fork()) == 0)
		{
			/* Child */
			if (execve(argin[0], argin, NULL) == -1)
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
