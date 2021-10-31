#include <stdio.h>

int ricerca(int selezione, int numeri[], int contatore)
{
    //bool terminato = false;
    for(int i = 0; i < contatore; i++)
    {
        if(selezione == numeri[i])
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char *argv[])
{
   if(argc == 1)
    {
       printf("Aggiungi anche dei numeri\n")
       return 1;
    }

    int numeri[argc];

    int Length = sizeof(numeri);
    int contatore = 0;
    for(int i = 1 ; i < Length; i++)
    {
       if(atoi(argv[i]) == NULL)
       {
           Array.Resize()
       }
       else
       {
           numeri[contatore] = atoi(argv[i]);
           contatore++;
       }
    }
    int selezione = 0;
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &selezione);
    int risultato = ricerca(selezione, numeri[], contatore);
    if(ricerca != -1)
    {
        printf("Il numero %d si trova alla posizione : %d", selezione, ricerca);
        return 0;
    }
    else
    {
        printf("Il numero non si trova nell'array");
        return 0;
    }
}