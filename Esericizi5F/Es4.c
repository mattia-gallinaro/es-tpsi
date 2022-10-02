#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ControllaLettere(char stringa[])
{
    int risultato = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (isalpha(stringa[i]) == 0)
        {
            risultato++;
            break;
        }
    }
    return risultato;
}

int ContaLettere(char stringa[], int caso)
{
    int n_vocali = 0;
    int n_consonanti = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        char c = toupper(stringa[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' && caso == 0)
        {
            n_vocali++;
        }
        else if (isalpha(c) != 0 && caso == 1)
        {
            n_consonanti++;
        }
    }
    if (caso == 0)
    {
        return n_vocali;
    }
    else
    {
        return n_consonanti;
    }
}

int ContaRipetizioni(char stringa[], char c)
{
    int conteggio = 0;
    if (strchr(stringa, c) == NULL)
    {
        return conteggio;
    }
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == c)
        {
            conteggio++;
        }
    }
    return conteggio;
}

int CercaDoppie(char stringa[]){
    int risultato = 0;
    for(int i = 0 ; i< strlen(stringa); i++){
        for(int j = i+1; j < strlen(stringa); j++){
            if(stringa[i] == stringa[j]){
                risultato++;
                break;
            }
        }
        if(risultato == 1){
            break;
        }
    }
    return risultato;
}

void StringaPariDispari(char stringa[]){
    char str1[strlen(stringa)];
    char str2[strlen(stringa)];
    str1[0] = '\0';
    str2[0] = '\0';
    int posizioneP =0 , posizioneD = 0;
    for(int i = 0; i< strlen(stringa); i++){
        if((i % 2) == 0)
        {
            if(isalpha(stringa[i]) !=0){
                strncat(str1, &stringa[i], 1);
            }
            
        }
        else{
            if(isalpha(stringa[i]) !=0){
                strncat(str2, &stringa[i], 1);
            }
        }
    }
    printf("\nLa stringa con lettere in posizione pari e': %s", str1);
    printf("\nLa stringa con lettere in posizione dispari e': %s", str2);
}

void ControlloGrandezza(char str1[], char str2[]){
    if(strlen(str1) > strlen(str2)){
        printf("\nLa stringa piu' corta e' : %s\ne la piu' lunga e': %s", str2, str1);
    }else if(strlen(str1) < strlen(str2)){
        printf("\nLa stringa piu' corta e' : %s\ne la piu' lunga e': %s", str1, str2);
    }else{
        printf("\nHanno la stessa grandezza");
    }
}

void LettereDoppie(char str1[], char str2[]){
    int posizione = 0;
    char risposta[strlen(str1) + strlen(str2)];
    int controllo = 0;
    for(int i = 0; i < strlen(str1); i++){
        for(int j = 0; j < strlen(str2); j++){
            if(str1[i] == str2[j]){
                controllo = 1;
                break;
            }
        }
        if(controllo == 1){
            if(isalpha(str1[i]) != 0 && strchr(risposta, str1[i]) == 0){
                risposta[posizione] = str1[i];
                posizione++;
            }
            controllo = 0;
        }
    }
    printf("\nI caratteri doppi sono: %s", risposta);
}
void ControlloMaggiorLettere(char stringa[],char seconda[], int caso, char risposta[]){
    int n_lettere_1 = ContaLettere(stringa, caso);
    int n_lettere_2 = ContaLettere(seconda, caso);
    if(n_lettere_1 > n_lettere_2){
        printf("\nLa prima stringa ha piu' %s della seconda", risposta);
    }else if(n_lettere_1 < n_lettere_2){
        printf("\nLa seconda stringa ha piu' %s della prima", risposta);
    }else{
        printf("\nHanno la stessa quantita' di %s", risposta);
    }
}
int main()
{
    char stringa[100];
    int scelta = 0;
    printf("\nInserisci una stringa a piacere:");
    scanf("%[^\n]", stringa);

    while (1)
    {
        printf("\nPremi 1 per verificare se la stringa contiene solo lettere\nPremi 2 per vedere il numero di vocali contenute nella stringa\nPremi 3 per vedere il numero di consonanti della stringa\nPremi 4 per vedere quante volte un carattere compare nella stringa\nPremi 5 per creare 2 ulteriori stringhe\nPremi 6 per verificare se la stringa contiene doppie\nPremi 7 per terminare la selezione\nSelezione: ");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            if (ControllaLettere(stringa) == 1)
            {
                printf("\nLa stringa non contiene solamente lettere");
            }
            else
            {
                printf("\nLa stringa contiene solo lettere");
            }
            break;
        case 2:
            printf("\nLa stringa contiene %d vocali", ContaLettere(stringa, 0));
            break;
        case 3:
            printf("\nLa stringa contiene %d consonanti", ContaLettere(stringa, 1));
            break;
        case 4:
            char c[8];
            printf("\nInserisci un carattere: ");
            scanf("%s", c);
            int conteggio = ContaRipetizioni(stringa, c[0]);
            if(conteggio== 0){
                printf("\nIl carattere non esiste nella stringa");
            }else{
                printf("\nIl carattere si trova %d volte nella stringa", conteggio);
            }
            break;
        case 5:
            StringaPariDispari(stringa);
            break;
        case 6:
            if(CercaDoppie(stringa) == 1){
                printf("\n La stringa contiene doppie");
            }
            else{
                printf("\n La stringa non contiene doppie");
            }
            break;
        }
        if(scelta >=7)
            break;
    }
    char seconda[100];
    printf("\nInserisci la seconda stringa: ");
    scanf("%s", seconda);
    ControlloGrandezza(stringa, seconda);
    LettereDoppie(stringa, seconda);
    ControlloMaggiorLettere(stringa, seconda , 0, "vocali");
    ControlloMaggiorLettere(stringa, seconda , 1, "consonanti");
    return 0;
}