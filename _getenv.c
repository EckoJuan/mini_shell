#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _getenv - get environmental variable
 * @name: name you search
 * @env: environmental variables
 * Return: return value of env-variablename
 * 
char *_getenv(const char *name, char **env)
{
	int i = 0;
	char *token2;
	char *token3;

	while (env[i])
	{
		token2 = strtok(env[i], "=");
		token3 = strtok(NULL, "=");
		if (strcmp(name, token2) == 0)
			return (token3);
		i++;
	}
	return (NULL);
}*/

/**
 * _getenv - get environmental variable
 * @name: name you search
 * @env: environmental variables
 * Return: return value of env-variablename
 */
/*char **path_split(char *path)
{
	char **sp_path;

}*/


int main(int ac, char **av, char **env)
{
	char *token1, *token2;
    int i = 0;
    
	while (env[i])
	{
		token1 = strtok(env[i], "=");
		token2 = strtok(NULL, "=");
		
		if (strcmp(av[1], token1) == 0)
		{
			printf("%s: %s\n", av[1],token2);
			token2 = strtok(token2, ":");
			while (token2 != NULL)
			{
				token2 = strtok(NULL, ":");

				if (token2 != NULL)
					printf("%s\n", token2);
			}

			/*printf("t1 -> %s\nt2 -> %s\n\n", token1, token2);*/
			return (0);
		}
		i++;
	}

	printf("Not found\n");
	return (1);
}