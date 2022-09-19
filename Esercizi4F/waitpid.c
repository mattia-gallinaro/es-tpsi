/// \file waipid.c
/// \brief es con scrittura su file di una fork e lettura dal file del padre
/// \author Mattia Gallinaro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

/**
 * @fn int main()
 * @brief funzione che si occupa di creare un figlio per la scrittura su file ed il padre che si occupa di leggere dal file
 * @param
 * @param
 * @return
 */
int main(int argc, char *argv[])
{
    FILE *stream;
    int pid1, pid2, pid3, statuts;
    char fileinput[10];
    sprintf(fileinput, "Testo.txt");
    if ((stream = fopen(fileInput, "w+")) == NULL)
    {
        printf("Impossibile aprire il file in cui scrivere la frase");
        exit(4);
    }
    pid1 = fork();
    if (pid1 == 0)
    {
        printf("Sono il primo figlio");
        exit(1);
    }
    else
    {
        pid2 = fork();
        if(pid2 == 0)
        {
            printf("Sono il secondo figlio");
            exit(1);
        }
        else
        {
            pid3 = fork();
            if(pid3 == 0)
            {
                printf("Sono il terzo figlio");
                fpritnf(stream,"");
                exit(1);
            }
            else
            {
                waitpid(pid3, &status, 0);
                printf("\nSono il padre\n");
                wait(0);
                char stringa[100][100];
                FILE *stream;
                if ((stream = fopen(fileinput, "r")) == NULL)
                {
                printf("Impossibile aprire il file da cui leggere la frase");
                exit(5);
                }
                int numParole = 0;
                while (!feof(stream))
                {
                fscanf(stream, "%s\t", stringa[numParole]);
                numParole++;
                }
                for (int i = 0; i < numParole; i++)
                    printf("%s ", stringa[i]);

                 fclose(stream);
                return (0);
            }
        }
    }
}