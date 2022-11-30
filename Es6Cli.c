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
    int socket_fd, total_v[2];
    char str[DIM], response[DIM], char_c[2];

    printf("\nInserisci una stringa: ");
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
    write(socket_fd, &char_c[0], sizeof(char));

    read(socket_fd, total_v, sizeof(int)*2);
    printf("Vocali : %i\n", total_v[0]);
    printf("Consonanti : %i\n", total_v[1]);
    close(socket_fd);


    return 0;
}