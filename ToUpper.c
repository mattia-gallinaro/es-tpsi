/// \file ToUpper.c
/// \author Mattia Gallinaro
/// \date 18/11/2021
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

/**
 * @fn int main(int argc, char * argv[])
 * @brief funzione che controlla che il numero di argomenti in argv sia pari a 2, genera un processo figlio che converte i caratteri della stringa in argv[1] in maiuscolo ed il padre che legge la stringa dopo della modifica del figlio
 * @param argc : indica la quantità di elementi presenti in argv
 * @param argv : la matrice di elementi scritti dall'utente
 */
int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("numero degli argomenti errato");
    }
    int pid = 0;
    pid = fork();
    if(pid == 0)
    {
        printf("Processo figlio");
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            argv[1][i] = toupper(argv[1][i]);
        }
        exit(1);
    }
    else
    {
        printf("Processo padre");
        wait(&pid);
        printf("%s", argv[1]);
    }
    return 0;
}