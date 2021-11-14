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
}Persona_T;

void AggiungiNumero(char * argv[],Persona_T *persone[],int * argc)
{
  FILE* stream;
  if((stream  = fopen(argv[1], "r"))== NULL)
  {
    printf("Impossibile aprire il file %s", argv[1]);
    exit(2);
  }
  Persona_T nuovo;
  do
}
//funzione per controllare che il contatto che l'utente vuole inserire non esistà già all'interno della rubrica
bool ControlloRubrica(Persona_T *persone[], Persona_T new)
{ 
  bool controllo = false;
  return controllo;
}
//serve per 
void MostraRubrica(char * argv[],Persona_T persone[], int * argc)
{
  FILE* stream;
  if((stream  = fopen(argv[1], "r"))== NULL)
  {
    printf("Impossibile aprire il file %s", argv[1]);
    exit(2);
  }
  if(argc == 2)
  {
    printf("caso 1");
  }
  else
  {
    printf("caso 2");
  }
}
void EliminaContatto(char * argv[],Persona_T persone[])
{

}
int main(int argc, char * argv[])
{
    FILE* stream;
    Persona_T persone[];
    char *stringa[100];
    int numParole = 0;
    if(argc != 4 || argc != 2)
    {
      printf("il numero di argomenti e' errato");
      exit(1);
    }
    if((stream  = fopen(argv[1], "r"))== NULL)
    {
      printf("Impossibile aprire il file %s", argv[1]);
      exit(2);
    }
    while(!feof(stream))
    {
      fscanf(stream, "%s\t", stringa[numParole]);
      numParole++;
    }
    for(int i = 0; i < strlen(stringa); i++)
    {
      scanf("%s\t",stringa[i]);
    }
    int scelta;
    do
    {
      printf("Digita 1 per mostrare la rubrica\n Digita 2 per aggiungere un nuovo contatto\n Digita 3 per eliminare un contatto in base al suo numero di telefono");
      scanf("%d", &scelta);
      swicth(scelta)
      { 
      case 1:
      MostraRubrica(argv, persone)
      break;
      case 2:
      AggiungiNumero(argv, persone, &argc);
      break;
      case 3:

      break;
      case 4:
      printf("\nArrivederci\n");
      break;
      }
    }while(scelta != 4);
   return 0;
}