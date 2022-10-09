#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

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
    if(grandezza > 0){
        for(int i = 0; i < grandezza; i++){
         if(array[i] == numero){
            controllo++;
            break;
            }
        }
    }
    return controllo;
}
int GeneraNumero(){
    return 1 + rand() % 233;
}

void OrdinaInverso(int array[], int lunghezza){
    for(int i = 0; i < lunghezza; i++){
        for(int j = i+1; j < lunghezza; j++){
            if(array[i] < array[j]){
                int number = array[i];
                array[i] = array[j]; 
                array[j] = number;
            }
        }
    }
}
void Riordina(int array[], int lunghezza){
    for(int i = 0; i < DIM; i++){
        for(int j = i+1; j < DIM; j++){
            if(array[i] > array[j]){
                int number = array[i];
                array[i] = array[j]; 
                array[j] = number;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int array[DIM];
    int stamp[DIM];
    int controllo =0;
    int numero =0;
    for(int i = 0; i < DIM; i++){
        numero = GeneraNumero();
        controllo = ControllaNumero(array, numero, i);
        if(controllo != 0){
            i--;
            controllo = 0;
        }else{
            array[i] = numero;
        }
    }
    Riordina(array, DIM);
    printf("\n\nArray ordinato:");
    for(int i = 0; i < DIM; i++){
        printf("\n%d", array[i]);
    }

    int primi_pari[20];
    int ultimi_disp[20];
    int resto[60];
    int pos_pari = 0;
    int pos_dispari = 0;
    int pos_resto = 0;

    for(int i =0; i < DIM; i++){
        if(array[i] %2 == 0 && pos_pari < 20){
            primi_pari[pos_pari] = array[i];
            pos_pari++;
        }
        if(array[100 - i - 1] % 2 != 0 && pos_dispari < 20){
            ultimi_disp[pos_dispari] = array[100 - i - 1];
            pos_dispari++;
        }
    }

    for(int i = 0; i < DIM; i++){
        if(array[i] % 2 == 0){
            if(CheckArray(primi_pari, pos_pari + 1, array[i]) == 0){
                resto[pos_resto] = array[i];
                pos_resto++;
            }
        }
        else{
            if(CheckArray(ultimi_disp, pos_dispari, array[i]) == 0){
                resto[pos_resto] = array[i];
                pos_resto++;
            }
        }
    }

    OrdinaInverso(resto, pos_resto +1);
    int pos_attuale =0;
    for(int i =  0; i< pos_pari; i++){
        stamp[pos_attuale] = primi_pari[i];
        pos_attuale++;
    }
    for(int i =  0; i< pos_dispari; i++){
        stamp[pos_attuale] = ultimi_disp[i];
        pos_attuale++;
    }
    for(int i =  0; i< pos_resto; i++){
        stamp[pos_attuale] = resto[i];
        pos_attuale++;
    }
    printf("\n\nArray finale:");
    for(int i = 0; i < DIM; i++){
        printf(" %d ", stamp[i]);
    }
    return 0;
}
