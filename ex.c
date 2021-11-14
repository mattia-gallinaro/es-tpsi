///  \file   rubrica.c
///  \brief  gestisce una rubrica, mostra, aggiunge e rimuove contatti dalla rubrica
///  \date   Il file è stato creato l'12/11/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// \param  MAX_CHAR: dimensione massima dei caratteri che il nome e cognome possono avere
#define MAX_CHAR 10
/// \param  SINGLE_LINE: dimensione massima di una riga, sul file (\n incluso)
#define SINGLE_LINE 33

/**
 *  \brief  struct di nome: "PERSONA_T", ogni persona ha un nome, cognome e un numero di telefono
 *  \param  char nome[MAX_CHAR]: indica il nome della persona
 *  \param  char cognome[MAX_CHAR]: indica il cognome della persona
 *  \param  char numeroTelefonico[10]: indica il numero di telefono della persona
 */

typedef struct
{
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
    char numeroTelefonico[10];
} PERSONA_T;

/**
 *  \fn     int ContaRighe(FILE *rubrica, char filename[])
 *  \brief  funzione che ricevendo come parametro il puntatore "rubrica" e il nome del file, restituisce il numero di righe di cui il file è composto
 *  \param  FILE *rubrica: puntatore di tipo FILE
 *  \param  char filename[]: nome del file da leggere
 *  \return righe: ritorna il numero di righe presente nel file
 */

int ContaRighe(FILE *rubrica, char filename[])
{
    if ((rubrica = fopen(filename, "r")) == NULL)
    {
        printf("Impossibile aprire il file\n");
        exit(1);
    }
    int righe = 0;
    //int cLetti = 0;
    char c;
    while (!feof(rubrica))
    {
        c = fgetc(rubrica);
        if (c == '\n')
            righe++;
        //cLetti++;
        //printf("Carattere n°%d: %c\n", cLetti, c);
    }
    if (c == EOF && righe != 0)
        righe++;
    fclose(rubrica);
    //printf("Il file possiede %d righe\n", righe);
    return righe;
}

/**
 *  \fn     void MostraRubrica(FILE *rubrica, char filename[], int righe)
 *  \brief  mostra a schermo la lista dei contatti presente nel file passato per parametro al'esecuzione del programma
 *  \param  FILE *rubrica: puntatore di tipo FILE
 *  \param  char filename[]: nome del file da leggere
 *  \param  int righe: numero di righe presenti nel file
 */

void MostraRubrica(FILE *rubrica, char filename[], int righe)
{
    if ((rubrica = fopen(filename, "r")) == NULL)
    {
        printf("Impossibile aprire il file\n");
        exit(1);
    }
    PERSONA_T persone[righe];
    for (int i = 0; !feof(rubrica); i++)
    {
        fscanf(rubrica, "%s %s %s", persone[i].nome, persone[i].cognome, persone[i].numeroTelefonico);
        printf("%s %s %s\n", persone[i].nome, persone[i].cognome, persone[i].numeroTelefonico);
    }
    fclose(rubrica);
}

/**
 *  \fn     void AggiungiContatto(FILE *rubrica, char filename[], int righe, PERSONA_T nuovoContatto, char filenameOut[], int argc)
 *  \brief  aggiunge alla lista un nuovo contatto, che l'utente vuole aggiungere
 *  \param  FILE *rubrica: puntatore di tipo FILE
 *  \param  char filename[]: nome del file da leggere
 *  \param  int righe: numero di righe presenti nel file
 *  \param  PERSONA_T nuovoContatto: dati del contatto che l'utente vuole aggiungere
 *  \param  char filenameOut[]: nome dell'eventuale file di output dove aggiornare la lista
 *  \param  int argc: numero di argomenti che il programma, all'avvio ha ricevuto coem parametro
 */

void AggiungiContatto(FILE *rubrica, char filename[], int righe, PERSONA_T nuovoContatto, char filenameOut[], int argc)
{
    if ((rubrica = fopen(filename, "r")) == NULL)
    {
        printf("Impossibile aprire il file\n");
        exit(1);
    }
    PERSONA_T persone[righe];
    char str[SINGLE_LINE * righe];
    for (int i = 0; !feof(rubrica); i++)
    {
        char tmp[SINGLE_LINE];
        fscanf(rubrica, "%s %s %s", persone[i].nome, persone[i].cognome, persone[i].numeroTelefonico);
        sprintf(tmp, "%s %s %s\n", persone[i].nome, persone[i].cognome, persone[i].numeroTelefonico);
        if (i == 0)
        {
            strcpy(str, tmp);
            //printf("Questa è la riga copiata: %s\n\n\n", str);
        }
        else
            strcat(str, tmp);
    }
    fclose(rubrica);
    //printf("tutta la rubrica:\n%s\n", str);
    persone[righe - 1] = nuovoContatto;
    //printf("nuovo contatto: %s %s %s\n", persone[righe - 1].nome, persone[righe - 1].cognome, persone[righe - 1].numeroTelefonico);
    if (argc != 4)
    {
        if ((rubrica = fopen(filename, "w")) == NULL)
        {
            printf("Impossibile aprire il file\n");
            exit(2);
        }
    }
    else
    {
        if ((rubrica = fopen(filenameOut, "w")) == NULL)
        {
            printf("Impossibile aprire il file\n");
            exit(2);
        }
    }
    char tmp[SINGLE_LINE];
    sprintf(tmp, "%s %s %s", persone[righe - 1].nome, persone[righe - 1].cognome, persone[righe - 1].numeroTelefonico);
    strcat(str, tmp);
    fprintf(rubrica, "%s", str);
    fclose(rubrica);
    printf("\n");
}

/**
 *  \fn     void RimuoviContatto(FILE *rubrica, char filename[], int righe, PERSONA_T cancContatto, char filenameOut[], int argc)
 *  \brief  rimuove dalla lista dei un contatto, che l'utente vuole eliminare
 *  \param  FILE *rubrica: puntatore di tipo FILE
 *  \param  char filename[]: nome del file da leggere
 *  \param  int righe: numero di righe presenti nel file
 *  \param  PERSONA_T cancContatto: dati del contatto che l'utente vuole rimuovere
 *  \param  char filenameOut[]: nome dell'eventuale file di output dove aggiornare la lista
 *  \param  int argc: numero di argomenti che il programma, all'avvio ha ricevuto coem parametro
 */

void RimuoviContatto(FILE *rubrica, char filename[], int righe, PERSONA_T cancContatto, char filenameOut[], int argc)
{
    if ((rubrica = fopen(filename, "r")) == NULL)
    {
        printf("Impossibile aprire il file\n");
        exit(1);
    }
    PERSONA_T contatto;
    PERSONA_T persone[righe];
    int contattoTrovato = -1, pos = 0;
    for (int i = 0; !feof(rubrica); i++)
    {
        fscanf(rubrica, "%s %s %s", contatto.nome, contatto.cognome, contatto.numeroTelefonico);
        persone[i] = contatto;
        if (strcmp(cancContatto.nome, contatto.nome) == 0 && strcmp(cancContatto.cognome, contatto.cognome) == 0 && strcmp(cancContatto.numeroTelefonico, contatto.numeroTelefonico) == 0)
        {
            contattoTrovato = 0;
            pos = i;
            i--;
        }
    }
    fclose(rubrica);
    if (contattoTrovato == -1)
        printf("Contatto non trovato\n");
    else
    {
        printf("Contatto trovato\n");
        char str[SINGLE_LINE * righe];
        for (int i = 0; i < righe; i++)
        {
            char tmp[SINGLE_LINE];
            sprintf(tmp, "%s %s %s\n", persone[i].nome, persone[i].cognome, persone[i].numeroTelefonico);
            if (i == 0)
                strcpy(str, tmp);
            else
                strcat(str, tmp);
        }
        if (argc != 4)
        {
            if ((rubrica = fopen(filename, "w")) == NULL)
            {
                printf("Impossibile aprire il file\n");
                exit(2);
            }
        }
        else
        {
            if ((rubrica = fopen(filenameOut, "w")) == NULL)
            {
                printf("Impossibile aprire il file\n");
                exit(2);
            }
        }
        fprintf(rubrica, "%s", str);
        fclose(rubrica);
    }
    printf("\n");
}

/**
 *  \fn     int main()
 *  \brief  funzione principale, che si occupa della gestione della rubrica
 *  \return int: indica come è terminato il programma
 */

int main(int argc, char *argv[])
{
    if ((argc != 2 && argc != 4) || (argc == 4 && strcmp(argv[2], "-f") != 0))
    {
        printf("Argomenti errati\n");
    }
    else
    {
        FILE *rubrica;
        PERSONA_T nuovoContatto;
        PERSONA_T cancContatto;
        int righe, risposta;
        system("clear"); //solo per LINUX
        do
        {
            printf("Digita il numero corrispondente a quello che vuoi fare:\n1) Mostra rubrica\n2) Salva contatto\n3) Elimina contatto\n4) Pulisci la console\n5) Esci dal programma\n\n");
            scanf("%d", &risposta);
            printf("\n");
            switch (risposta)
            {
            case 1:
                righe = ContaRighe(rubrica, argv[1]);
                MostraRubrica(rubrica, argv[1], righe);
                printf("\n\n");
                break;
            case 2:
                printf("Inserisci il nome del contatto che vuoi aggiungere\n");
                scanf("%s", nuovoContatto.nome);
                printf("Inserisci il cognome del contatto che vuoi aggiungere\n");
                scanf("%s", nuovoContatto.cognome);
                printf("Inserisci il numero telefonico del contatto che vuoi aggiungere\n");
                scanf("%s", nuovoContatto.numeroTelefonico);
                righe = ContaRighe(rubrica, argv[1]);
                AggiungiContatto(rubrica, argv[1], righe + 1, nuovoContatto, argv[3], argc);
                break;
            case 3:
                printf("Inserisci il nome del contatto che vuoi rimuovere\n");
                scanf("%s", cancContatto.nome);
                printf("Inserisci il cognome del contatto che vuoi rimuovere\n");
                scanf("%s", cancContatto.cognome);
                printf("Inserisci il numero telefonico del contatto che vuoi rimuovere\n");
                scanf("%s", cancContatto.numeroTelefonico);
                righe = ContaRighe(rubrica, argv[1]);
                RimuoviContatto(rubrica, argv[1], righe - 1, cancContatto, argv[3], argc);
                break;
            case 4:
                system("clear");
                break;
            case 5:
                system("clear");
                break;
            default:
                printf("comando non valido\n");
                break;
            }
        } while (risposta != 5);
    }
    return 0;
}