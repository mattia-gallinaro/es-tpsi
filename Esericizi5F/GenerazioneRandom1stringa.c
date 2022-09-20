#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

//#define tot 99000
#define dim 1000000


int generaLunghezza()
{
    int n = 0;
    n =  (rand() % (20- 3)) + 3;
    return n;
}

char* generaStringa(int grandezza){
    char *stringa = malloc(grandezza + 1);
    for(int i = 0; i < grandezza; i++){
        int character = (rand() % (126 -  32)) + 32; 
        stringa[i] = (char)character;
        if (character == 32 || character == 34 || character == 96)
        {
            i--;
        }

    }
    return stringa;
    
}

int controlloStringhe(char **strs, char *stringa, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (strcmp(stringa, strs[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void scriviSuFile(char **strs){
    FILE *fp;
    if ((fp = fopen("output.txt", "w+")) == NULL)
    {
        printf("Impossibile aprire il file output");
        exit(1);
    }

    for(int i = 0;i <  dim; i++){
        fprintf(fp, "%s\n", strs[i]);
    }
    
    
    fclose(fp);
}
int main()
{
    char *strs[dim];
    for(int i = 0; i < dim; i++){
        int n = generaLunghezza();

        char *str = generaStringa(n);
        if(controlloStringhe(strs, str, i) == 1){
            i--;
        }
        else{
            strs[i] = str;
        }
        
        
    }
    scriviSuFile(strs);
    return 0;
}