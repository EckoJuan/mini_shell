#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
extern char *environ[];

int main(int argc, char *argv[])
{
	
    int index = 0;
    char **env = (char **)environ[0];

	/**
	 * The differences between a char ** and a char *[] are eroded, and thus made confusing, 
	 * by the fact that C won't allow an array to be passed to a function. All arguments to 
	 * functions are a single number -- either an primitive like an integer or float, or the
	 *  address of something. If you try to pass an array (that is, a block of data), the address
	 *  of the start of the block is passed instead. This means that in most code, you can
	 *  actually use char ** and char *[] as if they were the same thing. 
	 * You get problems -- as in this question -- when the data is arranged in memory in a 
	 * certain way, and the compiler cannot work out what that 
	 * way is unless the programmer tells it by using the proper type declaration.
	 * 
	 */
    printf("Environment variables:\n");
    index = 0;
    while (env[index])
    {
        printf("envp[%d]: %s\n", index, env[index]);
        ++index;
    }
    return 0;
}