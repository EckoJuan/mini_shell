#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid, ppid, ch_ppid;
    int status;

    ppid = getppid();

    child_pid = fork();
    printf("Parent id = %d, chiild = %d\n", ppid, child_pid);
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        /* Child */
        ch_ppid = getpid();
        sleep(3); /*sleep duerme al hijo por un tiempo */
        printf("Wait for me, wait for me,\n", ch_ppid);    
    }
    else
    {
        /* Parent */
        printf("Oh, it's all better now, parent id %d,  my child se creo bien valor del fork = %d, \n", ppid);
        wait(&status); /* State of the child process when has finished   */
                       /* el kernel pone el estado de la finalización en */
                       /* la referencia a la variable status, solo se debe definir*/
                       /* el kernel es quien define su valor */
                       /* forma de tomar el reporte cuando el procesos termine si no */
                       /* se hace el proceso queda zombie */
    }
    return (0);
}