#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DIM 512

char* checkWord(char stringa[]){
    for(int i = 0; i < strlen(stringa); i++){
        if(stringa[i] != stringa[strlen(stringa) -i -1]){
            return "Non va bene";
        }
    }
    return "Va bene";
}

int main(){
    struct sockaddr_in servizio, addr_remoto;
    int socket_fd, socket_acc , len_rem = sizeof(addr_remoto);
    char str[DIM], response[DIM];

    
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(50000);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    listen(socket_fd, 10);

    while(1)
    {
        fflush(stdout);

        socket_acc = accept(socket_fd, (struct sockaddr*)&addr_remoto, &len_rem);

        read(socket_acc, str, sizeof(str));

        //recv(socket_acc, str, sizeof(str), 0);
        
        write(socket_acc, checkWord(str), DIM);

        printf("%s\n", str);

        close(socket_acc);

    }

    return 0;
}