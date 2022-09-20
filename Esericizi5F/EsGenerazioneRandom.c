#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define tot 99000
#define dim 33000


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

void scriviSuFile(char **strs1, char **strs2, char **strs3){
    FILE *fp;
    if ((fp = fopen("output.txt", "w+")) == NULL)
    {
        printf("Impossibile aprire il file output");
        exit(1);
    }

    for(int i = 0;i <  dim; i++){
        fprintf(fp, "%s\n", strs1[i]);
    }
    
    for(int i = 0;i <  dim; i++){
        fprintf(fp, "%s\n", strs2[i]);
    }
    
    for(int i = 0;i <  dim; i++){
        fprintf(fp, "%s\n", strs3[i]);
    }
    
    fclose(fp);
}
int main()
{
    char *strs1[dim];
    char *strs2[dim];
    char *strs3[dim];
    int index1, index2, index3 = {0};
    for(int i = 0; i < tot; i++){
        int n = generaLunghezza();

        char *str = generaStringa(n);

        
        switch(strlen(str)){
            case 3 ... 8:
                if(controlloStringhe(strs1, str, index1) == 1 && index1 != dim && index1 != 0){
                    i--;
                }
                else{
                    strs1[index1] = str;
                    index1++;
                }
                break;
            case 9 ... 14:
                if(controlloStringhe(strs2, str, index2) == 1 && index2 != dim && index2 != 0 ){
                    i--;
                }
                else{
                    strs2[index2] = str;
                    index2++;
                }
                break;
            case 15 ... 20:
                if(controlloStringhe(strs3, str, index3) == 1 && index3 != dim && index3 != 0){
                    i--;
                }
                else{
                    strs3[index3] = str;
                    index3++;
                }
                break; 
        }
    }
    scriviSuFile(strs1, strs2, strs3);
    return 0;
}