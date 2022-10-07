#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void GeneraNumeri(int array[], int grandezza){
    for(int i = 0; i < grandezza; i++){
        array[i] = rand() % 200;
        printf("\n%d", array[i]);
    }
}
void InserisciNumero(int array[], int *grandezza, int numero){
    (*grandezza)++;
    array = realloc(array, (*grandezza) *sizeof(int));
    array[(*grandezza)-1] = numero;

}

int VerificaNumero(int array[], int grandezza, int numero){
    int response =0;
    for(int i =0 ; i < grandezza; i++){
        if(array[i] == numero){
            response++;
            break;
        }
    }
    return response;
}

void EliminaNumero(int array[], int *grandezza, int numero){
    int counter = 0;
    for(int i = 0; i < ((*grandezza)- counter); i++){
        if(array[i] == numero){
            for(int j=i ;j < ((*grandezza)- counter -1); j++){
                array[j] = array[j+1];
            }
            counter++;
        }
    }
    (*grandezza) -= counter;
    array = realloc(array, (*grandezza) * sizeof(int));
}
void StampaArray(int array[], int grandezza){
    for(int i = 0; i < grandezza; i++){
        printf("\n%d", array[i]);
    }

}

void Ordina(int array[], int grandezza){
    for(int i = 0; i < grandezza; i++){
        for(int j = i+1; j < grandezza; j++){
            if(array[i] > array[j]){
                int num = array[j];
                array[j] = array[i];
                array[i] = num;
            }   
        }
    }
}

int main(){
    srand(time(NULL));
    int grandezza =0;
    int numero = 1;
    int risposta = 0;
    do{
        printf("Inserisci la grandezza dell'array: ");
        scanf("%d", &grandezza);
    }while(grandezza <= 0);

    int *array = malloc(grandezza *sizeof(int));
    GeneraNumeri(array, grandezza);

    while(1){
        printf("\n1 per aggiungere un numero\n2 per verificare un numero\n3 per eliminare un numero\n4 per ordinare l'array\nSelezione: ");
        scanf("%d", &numero);
        switch(numero){
            case 1:
                printf("Inserisci un numero da aggiungere all'array: ");
                scanf("%d", &risposta);
                InserisciNumero(array, &grandezza, risposta);
                StampaArray(array, grandezza);
                break;
            case 2:
                printf("Inserisci un numero da controllare nell'array: ");
                scanf("%d", &risposta); 
                if(VerificaNumero(array, grandezza, risposta) == 1){
                    printf("Il numero e' presente");
                }else{
                    printf("Il numero non e' presente\n");
                }
                break;
            case 3:
                printf("Inserisci un numero da togliere dall'array: ");
                scanf("%d", &risposta);
                EliminaNumero(array, &grandezza, risposta);
                StampaArray(array, grandezza);
                break;
            case 4:
                Ordina(array, grandezza);
                StampaArray(array, grandezza);
                break;
        }
        if(numero > 4 ){
            break;
        }
    }
    free(array);
    return 0;
}