#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
    char *str, *token;
    char *buffer;
    size_t bufsize = 1;
	int characters;

    token = (char *)malloc(1 * sizeof(char));
    if( token == NULL)
    {
        perror("Unable to allocate token");
        return (1);
    }

    *token = " ";

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        return (1);
    }

    printf("$");
    characters = getline(&buffer,&bufsize,stdin);
	if (characters < 0)
		return (-1);

    /*if (argc != 3)
	{
		fprintf(stderr, "Usage: %s string delim\n", argv[0]);
		exit(EXIT_FAILURE);
	}*/

    printf("Buffer -> %s\n",buffer);
    str = strtok(buffer, token);

    
    while (str !=  NULL)
    {
        printf("%s\n", str);
        str = strtok(NULL, token);
    }
    free(buffer);
    return(0);
}