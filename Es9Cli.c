#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<ctype.h>
#include<arpa/inet.h>

#define DIM 512

int main(){
    struct sockaddr_in servizio;
    int socket_fd, result, total[2];
    char str1[DIM], str2[DIM], common[DIM], str_ord[DIM], resp[DIM], c[2];

    servizio.sin_family= AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(50000);

    socket_fd = socket(AF_INET, SOCK_STREAM,0);

    bind(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    connect(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("\nInserisci la prima stringa:");
    scanf("%s", str1);

    printf("\nInserisci la seconda stringa, per il controllo dei caratteri comuni :");
    scanf("%s", str2);

    printf("\nInserisci il carattere da cercare:");
    scanf("%s", c);

    write(socket_fd, str1, sizeof(str1));

    write(socket_fd, str2, sizeof(str2));

    //write(socket_fd, common, sizeof(common));

    write(socket_fd, &c[0], sizeof(c[0]));

    read(socket_fd, &result, sizeof(result));
    if(result == 1){
        printf("\n Parola 1 non palindroma");
    }
    else{
        printf("\n Parola 1 palindroma");
    }

    read(socket_fd, &result, sizeof(result));

    read(socket_fd, total,  sizeof(total));

    read(socket_fd, str_ord, sizeof(str_ord));

    read(socket_fd, common, sizeof(common));
    printf("\nRipetizioni di %c : %d", c[0], result);

    printf("\nvocali : %d", total[0]);

    printf("\nconsonanti : %d", total[1]);

    printf("\nStringa ordinata : %s", str_ord);

    printf("Lettere in comune : %s",  common);
    close(socket_fd);

}