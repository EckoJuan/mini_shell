#include "h.h"

/*int is_only_space(char *space)
{
	int i = 0;

	while(space)
	{
		if (space[i] != 32 && space != NULL)
		{
			printf("Cantidad de espacios -> %d\n", i);
			return(-1);
		}
		i++;
	}
	printf("value -1 \n");
	return (0);
}*/



/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(int ac, char *av[], char *env[])
{
	char *line = NULL, *token = NULL, *argv[32], *tmp = NULL;
	size_t len = 0;
	ssize_t read;
	struct stat st;
	int i, status, interactive = 1, cnt_lines = 0;
	pid_t child_pid;

	while (1)
	{
		isatty(STDIN_FILENO) == 0 ? interactive = 0 : interactive;
		interactive == 1 ? write(STDIN_FILENO, "#cisfun$ ", 9) : interactive;
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			interactive == 1 ? write(STDIN_FILENO, "\n", 1) : read;
			free(line);
			return (0);
		}
		if (*line != '\n')
		{
			token = strtok(line, " \t\n\r");
			for (i = 0; i < 32 && token != NULL; i++)
			{
				argv[i] = token;
				token = strtok(NULL, " \t\n\r");
			}
			argv[i] = NULL;
			tmp = linked_path(argv[0], env);
			if (stat(tmp, &st) == 0)
			{
				if ((child_pid = fork()) == 0)
				{
					if (execve(tmp, argv, env) == -1)
					{
						perror("->Error:");
						exit(127);
					}
				}
				else
					wait(&status);
			}
			for (i = 0; i < 32; i++)
				argv[i] = 0;
		}
		cnt_lines++;
	}
	for (i = 0; i < 32; i++)
		free(argv[i]);
	/*free(argv);
	free(token);
	free(line);*/
	return (0);
}
