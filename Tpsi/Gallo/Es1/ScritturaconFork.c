/// \file ScritturaconFork.c
/// \brief
/// \date 18/11/2021
/// \author Mattia Gallinaro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

/**
 * @fn int main()
 * @brief funzione che si occupa di generare tre figli i quali scirvono in modo consecutivo su file, in seguito il padre legge il contenuto del file e lo mostra a schermo
 */
int main()
{
    FILE *stream;
    int pid1, pid2, pid3, status;
    char fileinput[10];
    sprintf(fileinput, "Testo.txt");
    if ((stream = fopen(fileinput, "w")) == NULL)
    {
        printf("Impossibile aprire il file in cui scrivere la frase");
        exit(4);
    }
    pid1 = fork();
    if (pid1 == 0)
    {
        printf("Sono il primo figlio\n");
        fprintf(stream, "Ciao, sono Mattia");
        sleep(1);
        exit(1);
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("Sono il secondo figlio\n");
            fprintf(stream, ", ho diciasette anni ");
            sleep(2);
            exit(2);
        }
        else
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                printf("Sono il terzo figlio\n");
                fprintf(stream, "e sono uno studente");
                sleep(3);
                exit(3);
            }
            else
            {
                waitpid(pid3, &status, 0);
                fclose(stream);
                printf("\nSono il padre\n");
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
                {
                    printf("%s ", stringa[i]);
                }
                fclose(stream);
                exit(5);
            }
        }
    }
    return 0;
}