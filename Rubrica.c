/*Rubrica
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct{
    char nome[MAX];
    char cognome[MAX];
    int numero[MAX];
}
void AggiungiNumero()
{


}
void MostraRubrica()
{


}
void EliminaContatto()
{

}
int main(int argc, char * argv[])
{
    FILE* stream;
    if(argc != 4 || argc != 2)
    {
      printf("il numero di argomenti e' errato");
      exit(1);
    }
    if((stream  = fopen(argv[1], "r"))== NULL)
    {
      printf("Impossibile aprire il file rubrica");
    }
    switch(argc)
    {
       case 2:
        break;
       case 4:
        break;
    }
   return 0;
}