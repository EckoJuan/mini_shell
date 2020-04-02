#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
/**
  * main - Program that prints all arguments it receives.
  * @argc: count
  * @argv: array
  *
  * Return: Always 0
  **/
int main(int argc, char *argv[])
{
    char *str;

    if (argc != 3)
	{
		fprintf(stderr, "Usage: %s string delim\n", argv[0]);
		exit(EXIT_FAILURE);
	}

    str = strtok(argv[1], argv[2]);

    
    while (str !=  NULL)
    {
        printf("%s\n", str);
        str = strtok(NULL, argv[2]);
    }
    return (0);
}