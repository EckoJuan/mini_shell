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
int main(int ac, char *av[], char *env[])
{
	char *line = NULL;
	char *token = NULL, *argv[32];
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i = 0;

	/* Crear una función que retorne un doble puntero a argv*/
	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			return (EXIT_FAILURE);
		}

		if (*line != '\n')  /* Valida enter \n*/
		{

			token = strtok(line, " \t\n\r");
			for (i = 0; i < 32 && token != NULL; i++)
			{
				argv[i] = token;
				token = strtok(NULL, " \t\n\r");
			}
			argv[i] = NULL;


			i = 0;
			while (argv[i])
			{
				printf("argv[%d] -> %s\n", i, argv[i]);
				i++;
			}
			if ((child_pid = fork()) == 0)
			{
				/* Child */
				if (execve(argv[0], argv, env) == -1)
				{
					perror("->Error:");
				}
			}
			else
			{
				/* Parennt */
				wait(&status);
			}

			i = 0;

			while (i < 32)
			{
				argv[i] = 0;
				i++;
			}
		}
	}

	i = 0;
	while (i < 32)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	free(line);
	exit(EXIT_SUCCESS);
}
