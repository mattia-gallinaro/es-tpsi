#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define DIM 11

void ContaAscii(char stringa[]){
    int totale = 0;
    for(int i = 0; i < strlen(stringa); i++){
        totale +=  stringa[i];

    }
    printf("Il totale ascii e':%d", totale);
}

void GeneraStringa(char stringa[]){
    for(int i = 0;i < DIM; i++){
        char c = 32 + rand() % 95;
        if(strchr(stringa, c) == 0|| i == 0){
            stringa[i] = c;
        }
        else{
            i--;
        }
    }

}
void StampaArray(char stringa[]){
    printf("\nEcco la tua stringa: %s\n", stringa);
}

void RiordinaAlfebiticoStringa(char stringa[]){
    for(int i = 0; i < strlen(stringa); i++){
        if(isalpha(stringa[i]) != 0){
            for(int j = i + 1; j < strlen(stringa); j++){
                    if(tolower(stringa[i]) > tolower(stringa[j]) && isalpha(stringa[j]) != 0){
                    int c = stringa[i];
                    stringa[i] = stringa[j];
                    stringa[j] = c;
                }
            }
        }
    }
}

void ContaNumeri(char stringa[]){
    int contatore = 0;
    for(int i = 0; i< strlen(stringa); i++){
        if(isdigit(stringa[i]) != 0){
            contatore++;
        }
    }
    printf("\nNumeri trovati all'interno della stringa: %d\n", contatore);
}

void ContaCaratteriSpeciali(char stringa[]){
    int contatore = 0;
    for(int i = 0; i< strlen(stringa); i++){
        if(isdigit(stringa[i]) == 0 && isalpha(stringa[i]) == 0){
            contatore++;
        }
    }
    printf("\nCaratteri speciali trovati all'interno della stringa: %d\n", contatore);
}

void StampaNumeriParieDispari(char stringa[]){
    for(int i = 0; i < strlen(stringa); i++){
        if(isdigit(stringa[i]) != 0){
            char numero[1];
            numero[0] = stringa[i];
            if(atoi(numero) %2 == 0){
                printf("\nNumero pari: %c\n", stringa[i]);
            }
            else{
                printf("\nNumero dispari: %c\n", stringa[i]);
            }
        }
    }
}

void RicercaCarattere(char stringa[]){

    char c;
    printf("\nInserisci un carattere da controllare nell'array: ");
    c = getc(stdin);

    if(strchr(stringa, c) != 0){
        printf("\nNon ghe credo, ghe s'e il carattere in te array\n");
    }
    else{
        printf("\nTe si orbo\n");
    }
}

void ScambiaPosizioni(char stringa[]){
    char *copia = stringa;
    for(int i = 0; i < strlen(copia); i += 2){
        if((i + 1) >= strlen(copia)){
            break;
        }
        int c = copia[i];
        copia[i] = copia[i+1];
        copia[i+1] = c;
    }
    printf("\nStringa con posizioni scambiate e': %s\n", copia);
}
int main(){
    srand(time(NULL));
    printf("Ora generero' una stringa randomica");
    char stringa[DIM];
    GeneraStringa(stringa);
    StampaArray(stringa);
    ContaAscii(stringa);
    StampaArray(stringa);
    RiordinaAlfebiticoStringa(stringa);
    StampaArray(stringa);
    ContaNumeri(stringa);
    ContaCaratteriSpeciali(stringa);
    StampaNumeriParieDispari(stringa);
    RicercaCarattere(stringa);
    ScambiaPosizioni(stringa);
    return 0;
}