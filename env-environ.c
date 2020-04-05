#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char *environ[];
int main(int ac, char **av, char **env)
{
    unsigned int i;
    char **env_gb = (char **)environ[0];

	i = 0;
	while (env[i] != NULL || env_gb[i] != NULL)
	{
		printf("input main[%d]:%s\n input gb[%d]:%s\n", i, env[i], i, env_gb[i]);
		i++;
	}
	return (0);
}