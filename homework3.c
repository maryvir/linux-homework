#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *arg[]) 
{

    pid_t pid = fork();

    if (pid == 0) 
    {
        char *args1[] = {"./rectangle", arg[1], arg[2], NULL};
        execvp(args1[0], args1);
        perror("exec rectangle failed");
        exit(1);
    } 
    else 
    {
        wait(NULL);

        char *args2[] = {"./triangle", arg[3], arg[4], NULL};
        execvp(args2[0], args2);
        perror("exec triangle failed");
        exit(1);
    }

    return 0;
}
