/// \file waipid.c
/// \brief es con scrittura su file di una fork e lettura dal file del padre
/// \author Mattia Gallinaro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

void ScriviSuFile(char fileInput[10])
{
    FILE *stream;
    if ((stream = fopen(fileInput, "w")) == NULL)
    {
        printf("Impossibile aprire il file in cui scrivere la frase");
        exit(4);
    }
    char stringa[100];
    sprintf(stringa, "Ciao sono una persona");
    fprintf(stream, "%s", stringa);
    fclose(stream);
}

/**
 * @fn int main()
 * @brief funzione che si occupa di creare un figlio per la scrittura su file ed il padre che si occupa di leggere dal file
 * @param
 * @param
 * @return
 */
int main(int argc, char *argv[])
{
    char fileinput[10];
    sprintf(fileinput, "Testo.txt");
    int pid = fork();
    if (pid == 0)
    {
        printf("So er figlio pazzo sgravato");
        //ScriviSuFile(fileinput);
        exit(1);
    }
    else
    {
        printf("\nIo so er padre del figlio e leggo dal file del figlio fatto\n");
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