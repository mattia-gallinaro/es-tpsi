#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <ctype.h>

#define DIM 100


int CheckArray(int array[], int lunghezza, int numero){
    int controllo = 0;
    for(int i = 0; i < lunghezza; i++){
        if(array[i] == numero){
            controllo = 1;
            break;
        }
    }
    return controllo;
}

int ControllaNumero(int array[], int numero, int grandezza){
    int controllo = 0;
    if(grandezza == 0){
        return controllo;
    }

    for(int i = 0; i < grandezza; i++){
        if(array[i] == numero){
            controllo++;
            break;
        }
    }
    return controllo;
} 

void PrintArray(int array[], int grandezza){
    for(int i = 0; i < grandezza; i++){
        printf("[%d]: %d\n" , i , array[i]);
    }

}

void Riordina(int *array){
    for(int i = 0; i < DIM; i++){
        for(int j = i+1; j< DIM; j++){
            if(array[i] > array[j]){
                int numero = array[j];
                array[j] = array[i];
                array[i] = numero;
            }
        }
    }
}


void RiordinaInverso(int array[], int grandezza){
    for(int i = 0; i < grandezza; i++){
        for(int j = i+1; j< grandezza; j++){
            if(array[i] < array[j]){
                int numero = array[j];
                array[j] = array[i];
                array[i] = numero;
            }
        }
    }
}

int main () {
    srand(time(NULL));
    int array[DIM];
    int numero = 0;
    for(int i = 0; i < DIM; i++){
        numero = 1 + rand() % 232;
        if(ControllaNumero(array, numero , i ) == 0){
            array[i] = numero;
        }
        else{
            i--;
        }
    }
    Riordina(array);

    int pari[20];
    int dispari[20];
    int resto[60];
    int pos_pari = 0;
    int pos_dispari = 0;
    int pos_resto = 0;

    for(int i = 0; i < DIM; i++){
        if(array[i] % 2 == 0 && pos_pari < 20){
            pari[pos_pari] = array[i];
            pos_pari++;
        }
        if(array[100 - i -1] % 2 != 0 && pos_dispari < 20){
            dispari[pos_dispari] = array[100 - i -1];
            pos_dispari++;
        }

    }

    for(int i = 0; i < DIM ; i++){
        if(array[i] % 2 == 0){
            if(CheckArray(pari, pos_pari, array[i]) == 0){
                resto[pos_resto] = array[i];
                pos_resto++;
            }
        }
        else{
            if(CheckArray(dispari, pos_dispari, array[i]) == 0){
                resto[pos_resto] = array[i];
                pos_resto++;
            }
        }
    }

    int stamp[DIM];
    int pos = 0;
    for(int i = 0; i < pos_pari; i++){
        stamp[pos] = pari[i];
        pos++;
    }
    for(int i = 0; i < pos_dispari; i++){
        stamp[pos] = dispari[i];
        pos++;
    }
    for(int i = 0; i < pos_resto; i++){
        stamp[pos] = resto[i];
        pos++;
    }

    
    PrintArray(stamp, DIM);
    

    return 0;
}