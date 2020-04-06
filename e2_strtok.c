#include <stdio.h>
#include <string.h>
 
#define LINE_LEN 100
 
int main(void)
{
    char line[LINE_LEN], *token1;
    FILE *que;
 
    que = fopen("foo.txt", "r");
    if (que == NULL) {
        perror("fopen");
        return 1;
    }
 
    while(fgets(line,sizeof(line),que)!=NULL && strcmp(line,"quit") !=0)//when the command is not eof
    {
        printf("line  == %s\n", line);
        token1=strtok(line," \n\t");//get the command
        while(token1 != NULL)//when command is not quit
        {
            printf("token1 = %s\n",token1);
            if(strcmp("count\0",token1) ==0)//when command is count
            {
                printf("Equal!\n");
            }
            token1 = strtok(NULL, " \n\t");
        }
    }
 
    fclose(que);
 
    return 0;
}