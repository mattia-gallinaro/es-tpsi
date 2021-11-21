#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
//#include <ctype.h>

int main()
{
    int pid1, pid2, pid3, status;
    pid1 = fork();
    if(pid1 == 0)
    {
        printf("Ciao, io sono Qui\n");
        exit(1);
    }
    else
    {
        pid2 = fork();
        if(pid2 == 0)
        {
            printf("Ciao, io sono Qui\n");
            exit(2);
        }
        else
        {
            pid3 = fork();
            if(pid3 == 0)
            {
                printf("Ciao, io sono Qua\n");
                exit(2);
            }
            else
            {
               waitpid(pid3, &status, 0);
               printf("I miei figli hanno terminato l'esecuzione\n");
               exit(0);
            }
        }
    }
    return 0;
}