#include <stdio.h>

bool controllo(int a, int b){
    if(a <= 0 || b <= 0)
    {
        return true;
    }
    else return false;
}

int main(int argc, char *argv[]){
    int a, b;
    do
    {
    printf("Inserisci il primo numero");
    scanf("%d", &a);
    printf("Inserisci il secondo numero");
    scanf("%d", &b);
    }while(controllo(a,b));
    printf("i numeri inseriti sono: %d, %d" a,b);
    return 0;
}