#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int f1, f2, g1, h1, g2, h2, status;
    f1 = fork();
    if (f1 == 0)
    {
        printf("sono il figlio f1 del padre che mi vuole male\n");
        g1 = fork();
        if (g1 == 0)
        {
            printf("sono il figlio g1 di f1\n");
            exit(0);
        }
        else
        {
            h1 = fork();
            if (h1 == 0)
            {
                printf("creo spazio 1\n");
                exit(0);
            }
        }
        waitpid(g1, &status, 0);
        printf("il processo g1 è terminato\n");
        waitpid(h1, &status, 0);
        printf("il processo h1 è terminato\n");
        exit(0);
    }
    else
    {
        printf("sono il figlio f2 del padre che mi vuole male\n");
        f2 = fork();
        if (f2 == 0)
        {
            g2 = fork();
            if (g2 == 0)
            {
                printf("sono il figlio g2 di f2\n");
                exit(1);
            }
            else
            {
                h2 = fork();
                if (h2 == 0)
                {
                    printf("creo spazio 2\n");
                    exit(0);
                }
            }
            printf("AHHHHHHH\n");
            waitpid(g2, &status, 0);
            printf("OHHHHHHH\n");
            waitpid(h2, &status, 0);
            exit(0);
        }
        else
        {
            printf("so el padre\n");
            waitpid(f2, &status, 0);
            printf("il secondo processo è terminato\n");
            waitpid(f1, &status, 0);
            printf("il primo processo è terminato\n");
            return 0;
        }
    }
}