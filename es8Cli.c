#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>

#define DIM 512

int main(){
    struct sockaddr_in servizio;
    int socket_fd;
    char str1[DIM], str2[DIM], common[DIM];

    servizio.sin_family= AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(50000);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    connect(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("\nInserisci una stringa:");
    scanf("%s", str1);

    printf("\nInserisci una stringa:");
    scanf("%s", str2);

    write(socket_fd, str1, sizeof(str1));

    write(socket_fd, str2, sizeof(str2));

    read(socket_fd, common, sizeof(common));

    close(socket_fd);

    printf("Caratteri comuni: %s", common);
    return 0;
    
}