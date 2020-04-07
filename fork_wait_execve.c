#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
    pid_t child_pid/*, parent_pid*/, ppid, pparent, pid;
    int status = 0, i;

    printf("\n Parent de este proceso = %d ; PID de este proceso -> %d \n\n", ppid = getppid(), pid = getpid());

    for (i = 0; i < 5; i++)
    {
        printf("loop # %d\n", i);
        if ((child_pid = fork()) == 0)
        {
            /* Child */
            printf("Before execve\n");
            /*if (execve(argv[0], argv, NULL) == -1)
            {
                perror("Error:");
            }*/
            printf("In child process - pid = %d\n", getpid());
            sleep(1);
            exit(0);
        } else
        {
             /* parent */
            pparent = getpid();
            printf("Padre -> %d PID del proceso actual %d Child -> %d\n", (int)ppid, pparent, child_pid);
            wait(&status);
        }
    }   
    /*while ((parent_pid = wait(&status)) > 0)
    {
       
    }*/
    return (0);
}