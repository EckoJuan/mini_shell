/*get_exitstatus.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t c_pid, pid = 0, ppid;
	int status;

	c_pid = fork(); /* duplicate */
    ppid = getppid();
    printf("Prev ->Child: %d: I'm the child ,Parent: %d: I'm parent process, fork: %d: I am the forked process.\n", pid, ppid,c_pid);
	if( c_pid == 0 ){
		/* child*/
		pid = getpid();
        ppid = getppid();

		printf("Before ->Child: %d: I'm the child ,Parent: %d: I'm parent process, fork: %d: I was the forked process.\n", pid, ppid,c_pid);
		printf("Child: sleeping for 2-seconds, then exiting with status 12\n");

		/* sleep for 2 seconds*/
		sleep(2);

		/* exit with statys 12 */
		exit(12);

	}else if (c_pid > 0){
		/* parent */
        pid = getpid();
        /* printf("Child: %d: I'm the child ,Parent: %d: I'm the parent.\n", pid, c_pid);*/
		/* waiting for child to terminate */
		pid = wait(&status);

		if ( WIFEXITED(status) ){
			printf("Parent: Child exited with status: %d\n", WEXITSTATUS(status));
		}

	}else{
		/* error: The return of fork() is negative */
		perror("fork failed");
		_exit(2); /* exit failure, hard */
	}

	return 0;                                                                                                                                                     
}
