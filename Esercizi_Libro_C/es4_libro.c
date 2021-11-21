#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>


void ConvertiFirst(char stringa[])
{
    stringa[0] = toupper(stringa[1]);
    for(int i = 1; i < strlen(stringa); i++)
    {
    stringa[i] = tolower(stringa[i]);
    }
}
void ConvertiAll(char stringa[])
{
    for(int i = 0; i < strlen(stringa); i++)
    {
    stringa[i] = toupper(stringa[i]);
    }
}
int main(int argc, char * argv[])
{
    FILE *stream;
    if((stream = fopen("", "w")) == NULL)
    {
        printf("Impossibile aprire il file\n");
        exit(1);
    }
    int pid, status;
    char nome[20];
    char cognome[20];
    printf("Inserisci il nome della persona:");
    scanf("%s" nome);
    printf("\nInserisci il cognome della persona:");
    scanf("%s" persona.cognome);
    pid  = fork();
    if(pid == 0)
    {
        sleep(5);
        if((stream = fopen("", "r")) == NULL)
        {
            printf("Impossibile aprire il file\n");
            exit(3);
        }
        fpritnf(stream, "%s %s", nome, cognome);
        ConvertiAll(nome);
        ConvertiAll(cognome);
        printf("Nome e cognome letti dal figlio: %s %s\n", nome, cognome);
    }
    else
    {
        ConvertiFirst(nome);
        ConvertiFirst(cognome);
        printf("Nome e cognome modificati: %s %s\n", nome, cognome);
        fprintf("%s %s", nome, cognome);
        if(remove("") == 0)
        {
            printf("\nIl file e' stato eliminato\n");
        }
        else
        {
            printf("\nIl file non e' stato eliminato\n");
        }
        fclose(stream);
        wait(&pid);
        printf("Il figlio ha terminato l'esecuzione\n");
        exit(0);
    }
    return 0;
}