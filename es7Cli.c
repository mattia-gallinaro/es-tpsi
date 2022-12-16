#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define DIM 512

int main(){
    struct sockaddr_in servizio;
    int socket_fd;
    char str[DIM], resp[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port= htons(50000);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    connect(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("\nInserisci una stringa:");
    scanf("%[^\n]", str);

    write(socket_fd, str, sizeof(str));

    read(socket_fd, resp, sizeof(resp));

    printf("\nEcco la tua stringa riordinata: %s", resp);

    close(socket_fd);

}

