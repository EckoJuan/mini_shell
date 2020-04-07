#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int is_only_space(char *space)
{
	int i = 0;

	while(space)
	{
		if (space[i] != 32 && space != NULL)
		{
			printf("value 0 and space -> %c\n", space[i]);
			return(0);
		}
		i++;
	}

	printf("value -1 \n");

	return (-1);
}



/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(int ac, char *av[], char *env[])
{
	char *line = NULL;
	char *token = NULL, *argv[2];
	size_t len = 0;
	ssize_t read;
	struct stat st;
	int i, status;
	pid_t child_pid;


	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			return (EXIT_FAILURE);
		}

		if (*line != '\n' && is_only_space(line) != -1)
		{

			token = strtok(line, " \t\n\r");
			for (i = 0; i < 32 && token != NULL; i++)
			{
				argv[i] = token;
				token = strtok(NULL, " \t\n\r");
			}
			argv[i] = NULL;


			if (stat(argv[0], &st) == 0)
			{
				printf(" FOUND\n");
				if ((child_pid = fork()) == 0)
				{
					if (execve(argv[0], argv, env) == -1)
					{
						perror("->Error:");
					}
				}
				else
				{

					wait(&status);
				}
			}
			else
			{
				printf(" NOT FOUND\n");
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
	free(token);
	free(line);
	return (0);
}
