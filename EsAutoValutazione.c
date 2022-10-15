#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef struct{
    int numero;
    int ripetizioni;
}numero;

void PopolaArray(int array[],int grandezza){
    int numero = 0;
    for(int i =0; i < grandezza; i++){
        numero = rand() % 100;
        array[i] = numero;
    }

}

int ControllaNumeri(numero numeri[], int pos_now, int num){
    int controllo = 0;
    for(int i = 0; i < pos_now; i++){
        if(numeri[i].numero == num){
            controllo++;
            break;
        }
    }
    return controllo;
}

void Riordina(int array[], int grandezza){
    for(int i = 0; i < grandezza; i++){
        for(int j = i+1; j< grandezza; j++){
            if(array[i] > array[j]){
                int c = array[i];
                array[i] =array[j];
                array[j] = c;
            }
        }
    }
}
void ContaRipetizioni(int array[], int grandezza){
    numero numeri[100]; 
    int pos_at = 0;
    int counter = 0;
    for(int i = 0; i < grandezza; i++){
        if(ControllaNumeri(numeri, pos_at, array[i]) == 0){
            for(int j = 0; j < grandezza; j++){
                if(array[i] == array[j]){
                    counter++;
                }

            }
            numeri[pos_at].numero =  array[i];
            numeri[pos_at].ripetizioni =  counter;
            pos_at++;
        }
        counter = 0;
    }
    for(int i =0; i < pos_at; i++){
        printf("\nNumero %d con ripetizioni %d\n", numeri[i].numero, numeri[i].ripetizioni);
    }
}

void EliminaRipetizioni(int array[], int *grandezza){
    int counter = 0;
    for(int i = 0 ; i < (*grandezza) - counter; i++){
        for(int j= i+1; j < (*grandezza) - counter; j++){
            if(array[j] == array[i]){
                for(int k = j;k < (*grandezza) - counter -1; k++){
                    array[k] = array[k+1];
                }
                counter++;
                i--;
            }
        }
    }
    (*grandezza) -= counter;
    for(int i =0; i < *grandezza; i++){
        printf("\nNumero %d\n",array[i]);
    }
}

void OrdinaSeparato(int array[], int grandezza){
    for(int i = 0;i < grandezza; i++){
        for(int j = i+1;j < grandezza; j++){
            if(array[i] % 2 ==0 && array[j] % 2 == 0 && array[i] < array[j]){
                int c = array[i];
                array[i] =array[j];
                array[j] = c;
            }
            else if(array[i] % 2 != 0 && array[j] % 2 != 0 && array[i] > array[j]){
                int c = array[i];
                array[i] =array[j];
                array[j] = c;
            }
        }
    }
    for(int i =0; i < grandezza; i++){
        printf("\nNumero %d\n",array[i]);
    }
}
int main(){
    int grandezza = 100;
    int array[grandezza];
    PopolaArray(array, grandezza);
    Riordina(array, grandezza);
    ContaRipetizioni(array, grandezza);
    EliminaRipetizioni(array, &grandezza);
    OrdinaSeparato(array,grandezza);
}