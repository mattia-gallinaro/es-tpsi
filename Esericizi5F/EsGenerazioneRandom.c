#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define DIM 1000000

int generaLunghezza(){
    int n = 0;
    n =  rand() % 17 + 3;
    printf("%d", n);
    return n;
}

void generaStringa(char *stringa, int grandezza){
    stringa = malloc(grandezza);
    for(int i = 0; i < grandezza; i++){
        int character = rand() % (126 -  32) + 32; 
        stringa[i] = (char)character;
        if(character == 32 || character == 34 || character == 96){
            i--;
        }
        //stringa[i] = (char)character;

    }
    
}

int controlloStringhe(char **strs, char *stringa, int index){
    for(int i = 0; i < index; i++){
        if(strcmp(stringa, strs[i]) == 0){
            return 1;
        }
    }
    return 0;
}

void scriviSuFile(){
    FILE *fp;
    if((fp = fopen("output.txt", "w+")) == NULL){
        printf("Impossibile aprire il file output");
        exit(1);
    }

    for(int i = 0;i <  DIM; i++){
        fprintf(fp, "%s\n", stringa);

    }

}
int main()
{
    char *strs1[330000];
    char *strs2[330000];
    char *strs3[340000];
    int index1, index2, index3;
    for(int i = 0; i < 1000; i++){
        int n = generaLunghezza();

        char *str = generaStringa(n);

        
        swtich(strlen(str)){
            case 3 ... 8:
                if(controlloStringhe(strs1, str, index) == 1 || index1 != 0){
                    i--;
                }
                else{
                    strs1[index1] = str;
                    index1++;
                }
                break;
            case 9 ... 14:
                if(controlloStringhe(strs2, str, index) == 1 || index2 != 0){
                    i--;
                }
                else{
                    strs1[index2] = str;
                    index2++;
                }
                break;
            case 15 ... 20:
                if(controlloStringhe(strs3, str, index) == 1 || index3 != 0){
                    i--;
                }
                else{
                    strs1[index3] = str;
                    index3++;
                }
                break; 
        }
    }
    FILE
    return 0;
}