#include <studio.h>
#define DIM 4
#define MAX 10

//TYPEDEF struct{ char nome[MAX]; char cognome[MAX]; int eta;
//}Persona_T;
Persona_T InserisciPersona();//ritorna la persona appena inserita in base ai valori inseriti dall'utente
int Vecchio(Persona_T[], DIM);//ritorna l'indice dell'array che rappresenta la persona più vecchia 

int main(){
Persona_T persone[DIM];
for(int i = 0; i<DIM;i++)
{
persone[i] = InserisciPersona();//aggiungo nella lista delle 
}
int i = Vecchio(Persona_T, DIM);// passo l'indirizzo dell'array in modo da poter lavorare direttamente con l'array di persone del main
printf("La persona più vecchia e' %");
return 0;
}
