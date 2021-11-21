/// \author Mattia Gallinaro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdbool.h>


/*bool ControlloInserimento(char valore[20])
{
    bool controllo = false;
    int num = 0;
    if((num = atoi(valore)) == NULL)
    {
        controllo = true;
    }
    return controllo;
}*/
int main()
{
    int numero,pid;
    char valore[20];
    printf("Inserisci il numero da sommare");
    scanf("%d",&numero);
    pid = fork();
    if(pid == 0)
    {
        printf("il risultato della somma per il figlio e' %d\n", (numero+15));
        exit(1);
    }
    else
    {
        wait(&pid);
        printf("il risultato della somma per il padre e' %d\n", (numero+10));
        exit(2);
    }
    return 0;
}