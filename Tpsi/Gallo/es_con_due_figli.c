/// @file es_con_due_figli.c
/// @author Mattia Gallinaro
/// @date 18/11/2021
/// @brief file che genera due figli i quali, a loro volta, ne generano altri due e dopo aver fatto ciò i figli del padre aspettano in ordine i loro figli generati il padre, invece, attende la terminazione dei figli nell'ordine inverso con cui li crea
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * @fn int main()
 * @brief Funzione che assegna un pid iniziale, genera due figli i quali, a loro volta, ne generano altri due e dopo aver fatto ciò i figli del padre aspettano in ordine i loro figli generati il padre, invece, attende la terminazione dei figli nell'ordine inverso con cui li crea
*/
int main()
{
    int f1, f2, g, h, status, padre;
    padre = getpid();
    f1 = 0;
    f2 = 0;
    g = 0;
    h = 0;

    printf("1) padre con pid: %i\n", padre);
    f1 = fork();
    if (getpid() != padre) //verifico che il pid del figlio non sia quello del padre in modo da non scrivere righe a schermo in più
    {
        printf("2) f1 con pid %i\n", getpid());
    }
    //quindi ora controllo che il suo pid sia diverso da 0
    //in modo da generare il secondo figlio
    if (f1 != 0)
    {
        f2 = fork();
        if (getpid() != padre)
        {
            printf("3) f2 con pid %i\n", getpid());
        }
    } //else o if boh le testo entrambe
    if (f1 == 0 || f2 == 0)
    {
        g = fork();
        printf("4) nipote g con pid %i\n", getpid());
        if (g != 0)
        {
            h = fork();
            printf("5) nipote h con pid %i\n", getpid());
        }
        if (g != 0 && h != 0) //appena i due processi "nipoti" hanno valore diverso di 0, viene chiamata la waitpid per entrambi per terminarli (anche se forse serve anche una exit ma non ne sono sicuro)
        {
            waitpid(g, &status, 0);
            waitpid(h, &status, 0);
        }
    }
    else
    {
        waitpid(f2, &status, 0);
        printf("8) processo f2 terminato con pid %i\n", f2);
        waitpid(f1, &status, 0);
        printf("9) processo f1 terminato con pid %i\n", f1);
        exit(0);
    }

    return 0;
}