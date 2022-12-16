#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<ctype.h>
#include<unistd.h>

#define DIM 512

int palindroma(char str[]){
    for(int i = 0 ; i < strlen(str) / 2; i++){
        if(str[i] != str[strlen(str) -i -1]){
            return 1;
        }
    }
    return 0;
}

int countCharRep(char str[], char c){
    int counter = 0;
    for(int i = 0 ; i < strlen(str); i++){
        if(str[i] == c){
            counter++;
        }
    }
    return counter;
}

void countVC(char str[],int total[]){
    int control =0;
    total[0] = 0;
    total[1] = 0;
    for(int i = 0; i < strlen(str); i++){
        if(toupper(str[i]) == 'A' || toupper(str[i]) == 'E' || toupper(str[i]) == 'O' || toupper(str[i]) == 'I' || toupper(str[i]) == 'U'){
            total[0]++;
            control = 1;
        }
        if(control == 0 && isalpha(str[i])){
            total[1]++;
        }
        control = 0;
    }
}

void reOrder(char str[], char ret[]){
    int counter = 0;
    for(int i =0; i< strlen(str); i++){
        if(isalpha(str[i]) > 0){
            ret[counter] = str[i];
            counter++;
        }
    }

    for(int i =0;  i < strlen(ret); i++){
        for(int j = i +1; j< strlen(ret); j++){
            if(ret[j] < ret[i]){
                int swap = ret[j];
                ret[j] = ret[i];
                ret[i] = swap;
            }
        }
    }
}

void letCommon(char str1[], char str2[], char common[]){
    int counter=0;
    for(int i =0; i < strlen(str1) ; i++){
        if(strchr(str2, str1[i]) != 0 && strchr(common, str1[i])== 0){
            common[counter] = str1[i];
            counter++;
        }
    }
}
int main(){
    struct sockaddr_in servizio, remoto;
    int socket_fd , socket_acc, len_rem = sizeof(remoto), total[2];
    char str1[DIM], str2[DIM], common[DIM], c, ret[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(50000);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("\n Socket pronta");

    listen(socket_fd, 2);

    while(1){

        socket_acc = accept(socket_fd, (struct sockaddr*)&remoto, &len_rem);
        printf("\n Connessione effettuata");
        read(socket_acc, str1, sizeof(str1));

        read(socket_acc, str2, sizeof(str2));

        //read(socket_acc, common, sizeof(common));

        read(socket_acc, &c, sizeof(c));

        int result = palindroma(str1);

        write(socket_acc, &result, sizeof(int));

        result = countCharRep(str1, c);

        write(socket_acc, &result, sizeof(int));

        countVC(str1, total);

        write(socket_acc, total, sizeof(total));

        reOrder(str1, ret);
        
        write(socket_acc, ret, sizeof(ret));

        letCommon(str1, str2, common);

        write(socket_acc, common, sizeof(common));
        close(socket_acc);

        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        memset(common, 0, sizeof(common));
        memset(ret, 0, sizeof(ret));
    }
}