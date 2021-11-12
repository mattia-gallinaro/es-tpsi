#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void CambiaCaratteri(char * stringa[], char delete, char replace)
{//cambio il primo parametro con char * stringa[] o char ** stringa
    for(int i = 0; i < MAX;i++)
    {
        for(int j = 0; j < strlen(stringa[i]); j++)
        {
           if(stringa[i][j] == delete)
           {
                stringa[i][j] = replace;
           }
        }
    }
}
void scriviOutput(char * argv[], char * stringa[])
{
   FILE* stream;
   if((stream = fopen(argv[2], "w+")) == NULL)
   {
      printf("Impossibile aprire il file di scrittura\n");
      exit(5);
   }
   for(int i = 0 ; i < MAX ; i++)
   {
      fprintf(stream, "%s", stringa[i]);
   }
   fclose(stream);
}
int main(int argc,char * argv[])
{
    FILE* stream;
    char *stringa[100]; 
    int numParole = 0;
    
    if(argc != 6)
    {
        printf("Il numero di argomenti e' errato\n");
        exit(1);
    }
    if(strcmp(argv[3], "-s") != 0)
    {
        printf("Come metodo devi inserire -s\n");
        exit(2);
    }
    if(strlen(argv[4]) != 1 || strlen(argv[5]) != 1)
    {
        printf("Devi inserire un carattere\n");
        exit(3);
    }
    if((stream  = fopen(argv[1], "r")) == NULL)
    {
        printf("Impossibile aprire il file di lettura\n");
        exit(4);
    }
    while(!feof(stream))
    {
        fscanf(stream, "%s\t", stringa[numParole]);
        numParole++;
    }
    fclose(stream);
    CambiaCaratteri(stringa, argv[4][0], argv[5][0]);
    scriviOutput(argv, stringa);

    return 0;
}
