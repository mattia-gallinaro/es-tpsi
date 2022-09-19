#include <stdio.h>

int somma(int numeri[], int contatore)
{
    for(int i = 0; i < contatore; i++)
    {
         
    }
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
    int sommanum = somma(numeri, contatore);
    printf("La somma dei numeri inseriti da riga di comando e': %d\n", sommanum);
    return 0;
}