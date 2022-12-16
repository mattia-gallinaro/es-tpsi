#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 50000
#define DIM 512

void ordina(char str[], char new_str[]){
    int counter = 0;
    for(int i =0; i< strlen(str); i++){
        if(isalpha(str[i]) > 0){
            new_str[counter] = str[i];
            counter++;
        }
    }

    for(int i =0;  i < strlen(new_str); i++){
        for(int j = i +1; j< strlen(new_str); j++){
            if(new_str[j] < new_str[i]){
                int swap = new_str[j];
                new_str[j] = new_str[i];
                new_str[i] = swap;
            }
        }
    }
}

int main(){
    struct sockaddr_in servizio, addr_remoto;
    int socket_fd, socket_acc , len_rem = sizeof(addr_remoto);
    char str[DIM], new_str[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(PORT);

    socket_fd = socket(AF_INET, SOCK_STREAM , 0);

    bind(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("\nSocket pronta");

    listen(socket_fd, 2);

    while(1){
        socket_acc = accept(socket_fd, (struct sockaddr*)&addr_remoto, &len_rem);

        printf("\nNuovo utente connesso\n");

        read(socket_acc, str, sizeof(str));

        ordina(str, new_str);
        write(socket_acc , new_str, sizeof(str));
        close(socket_acc);
        fflush(stdout);

        memset(str, 0, sizeof(str));
        memset(new_str, 0 , sizeof(new_str));
        fflush(stdout);
    }

    return 0;

} 