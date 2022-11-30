#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define DIM 512



int main(){
    struct sockaddr_in servizio;
    int socket_fd;
    char str[DIM], response[DIM];
    printf("Inserisci una stringa");
    scanf("%s", str);
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(50000);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(connect(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio)) != 0){
        printf("Non trovo il server");
    }

    printf("%s\n", str);
    write(socket_fd, str, sizeof(str));
    read(socket_fd, response, sizeof(response));
    printf("%s", response);
    close(socket_fd);


    return 0;
}