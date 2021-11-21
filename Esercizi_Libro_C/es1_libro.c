#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int pid;
    pid  = fork();
    if(pid == 0)
    {
        printf("Ciao sono il figlio con pid:  %i \n", getpid());
        exit(1);
    }
    else
    {
        wait(&pid);
        printf("Ciao sono il padre con pid: %i \n", getpid());
        exit(0);
    }
    return 0;
}
