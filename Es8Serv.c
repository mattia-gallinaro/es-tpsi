#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define DIM 512

void checkCommon(char str1[], char str2[], char common[]){
    int counter =0;
    for(int i =0; i< strlen(str1); i++)
    {
        if(strchr(str2, str1[i]) != 0 && strchr(common, str1[i]) == 0){
            common[counter] = str1[i];
            counter++;
        }
    }
}


int main(){
    struct sockaddr_in servizio, remoto;
    int socket_fd, socket_acc, len_rem =sizeof(remoto);
    char str1[DIM], str2[DIM], common[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(50000);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_fd, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("\nSocket pronta");

    listen(socket_fd, 2);

    for (;;)
    {
        socket_acc = accept(socket_fd, (struct sockaddr*)&remoto, &len_rem);

        printf("\nNuovo utente connesso\n");

        read(socket_acc, str1, sizeof(str1));
        read(socket_acc, str2, sizeof(str2));

        checkCommon(str1, str2, common);

        write(socket_acc, common, sizeof(common));

        memset(str1, 0 ,sizeof(str1));
        memset(str2, 0 , sizeof(str2));
        memset(common, 0, sizeof(common));
        close(socket_acc);


    }
    


}