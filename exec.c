#include <stdio.h>
#include <unistd.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
/*int main(void)*/
int main(int ac, char **av, char **env)
{
    char *argv[] = {"/bin/ls", "-l", "/etc/", NULL}; /* NULL igual a final de los argumentos */
    (void)ac;
    (void)av;

    printf("Before execve\n");
    /* en este codigo es necesario definir el environent para que se tenga en cuannta al momento de invocar los */
    /* comandos que se le envien mediante el argv[0] -> path y argv-> que es el puntero con los argumentos a leer*/
    if (execve(argv[0], argv, env) == -1) /* Null del del execve es la estructura que apunta al eviroment */
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}