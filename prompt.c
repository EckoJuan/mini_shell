#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer;
    size_t bufsize = 1;
	int characters;

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
    printf("%s",buffer);
    free(buffer);
    return(0);
}