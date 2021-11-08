// \file Struct.c
// \brief mostra a schermo il più vecchio tra le 4 persone prese in input dall'utente
// \date 8/11/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 4
#define MAX 10

typedef struct{ char nome[MAX]; 
                char cognome[MAX]; 
                int eta;
}Persona_T;

/**
 * @fn Persona_T InserisciPersona()
 * @brief funzione che chiede e prende in input i dati per ciascuna persona 
 * @return Persona_T: la funzione ritorna una variabile complessa
 * @date 8/11/2021
 * @author Mattia Gallinaro
 * @file Struct.c
 */
Persona_T InserisciPersona()
{
    Persona_T persona;
    printf("inserisci il nome della persona\n");
    scanf("%s",&persona.nome);
    printf("inserisci il cognome della persona\n");
    scanf("%s",&persona.cognome);
    printf("inserisci l'eta' della persona\n");
    scanf("%i",&persona.eta);
    return persona;
}
/**
 * @fn int Vecchio(Persona_T persone[])
 * @brief funzione che trova la persona con l'età maggiore e scrive a schermo il nome della persona più vecchia
 * @param Persona_T persona[]: puntatore dell'array persone contenuto nel main
 * @date 8/11/2021
 * @author Mattia Gallinaro
 * @file Struct.c
 */
void Vecchio(Persona_T persone[])
{
    int pos = 0;
    for(int i = 1; i < DIM; i++)
    {
        if (persone[i].eta < persone[i - 1].eta)
        {
            pos = i - 1;
        }
        else
        {
            pos = i;
        }
    }
    printf("Il piu' vecchio e': %s\n", persone[pos].nome);
}

/**
 * @fn int main()
 * @brief funzione che crea l'array di persone con grandezza pari a DIM ed esegue le varie chiamate di funzioni
 * @return int: indica com'è terminato il programma
 * @date 8/11/2021
 * @author Mattia Gallinaro
 * @file Struct.c
 */
int main(){
    Persona_T persone[DIM];
    for(int i = 0; i<DIM;i++)
    {
        persone[i] = InserisciPersona();
    }
    Vecchio(persone);
    return 0;
}
