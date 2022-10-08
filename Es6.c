#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define DIM 100

int ContaPari(int array[]){
    int counter = 0;
    for(int i = 0;i < DIM; i++){
        if(array[i]%2 == 0){
            counter++;
        }
    }
    return counter;
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
void OrdinaCresc(int array[], int start, int end){
    for(int i = start; i < end; i++){
        for(int j = i+1; j < end; j++){
            if(array[i] > array[j]){
                int number = array[i];
                array[i] = array[j]; 
                array[j] = number;
            }
        }
    }
}
void OrdinaInverso(int array[], int start, int end){
    for(int i = start; i < end; i++){
        for(int j = i+1; j < end; j++){
            if(array[i] < array[j]){
                int number = array[i];
                array[i] = array[j]; 
                array[j] = number;
            }
        }
    }
}
// 0 sta per il caso pari e 1 per il caso dispari
// 1 array, da 20 numeri pari se non si hanno 20 pari allora si fa fino a quanti ne esistono 
// se ce ne sono di piu , prendo solo i primi 20 numeri pari e i restanti li metto in fondo
int main(){
    srand(time(NULL));
    int array[DIM];
    int numero = 0, controllo = 0;
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
    for(int i = 0; i < DIM; i++){
        printf("\n%d", array[i]);
    }
    Riordina(array, DIM);
    printf("\n\n");
    for(int i = 0; i < DIM; i++){
        printf("\n%d", array[i]);
    }

    int stamp[DIM];
    int pos_pari = 0, pos_disp =0;
    int controlloPari = 0;
    int controlloDispari = 0;
    int pari[ContaPari(array)];
    int dispari[100 - ContaPari(array)];

    for(int i = 0; i < 100; i++){
        if(array[i] % 2 == 0){
            pari[pos_pari] = array[i];
            pos_pari++;
        }else{
            dispari[pos_disp] = array[i];
            pos_disp++;
        }
    }
    if((sizeof(pari)/ sizeof(int)) >= 20){
        for(int i = 0; i < 20; i++){
            stamp[i]= pari[controlloPari];
            controlloPari++;
        }
    }else{
        for(int i = 0; i < pos_pari; i++){
            stamp[i]= pari[controlloPari];
            controlloPari++;
        }
    }
    OrdinaCresc(stamp, 0, controlloPari);

    if((sizeof(dispari)/ sizeof(int)) > 20){
        for(int i = controlloPari; i < controlloPari + 20; i++){
            stamp[i]= dispari[controlloDispari];
            controlloDispari++;
        }
        OrdinaInverso(stamp, controlloPari, controlloPari + 20);
    }else{
        for(int i = controlloPari; i < controlloPari + pos_disp + 1; i++){
            stamp[i]= dispari[controlloDispari];
            controlloDispari++;
        }
        OrdinaInverso(stamp, controlloPari, controlloPari + pos_disp + 1);
    }
    
    int start = controlloDispari + controlloPari;

    for(int i = controlloDispari + controlloPari; i < DIM; i++){
        if(controlloPari < pos_pari){
            stamp[i] = pari[controlloPari];
            controlloPari++;
        }
        else{
            stamp[i] = dispari[controlloDispari];
            controlloDispari++;
        }
    }
    OrdinaInverso(stamp, start, DIM);
    printf("\n\n");
    for(int i = 0; i < DIM; i++){
        printf("\n %d", stamp[i]);
    }
    return 0;
}