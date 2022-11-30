#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DIM 512


void countRep(char* stringa, int *total_c){
    total_c[0]=0;
    total_c[1] = 0;
    int control = 0;
    for(int i = 0; i < strlen(stringa); i++){
        if(toupper(stringa[i]) == 'A' || toupper(stringa[i]) == 'E' || toupper(stringa[i]) == 'O' || toupper(stringa[i]) == 'I' || toupper(stringa[i]) == 'U'){
            total_c[0]++;
            control = 1;
        }
        if(control == 0 && isalpha(stringa[i])){
            total_c[1]++;
        }
        control = 0;
    }
}
int main(){
    struct sockaddr_in servizio, addr_remoto;
    int socket_fd, socket_acc , len_rem = sizeof(addr_remoto), total_v[2];
    char str[DIM], response[DIM], char_c;

    
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

        //read(socket_acc, &char_c, sizeof(char_c));
        //recv(socket_acc, str, sizeof(str), 0);
        //int total= countRep(str, char_c);

        countRep(str, total_v);
        write(socket_acc, total_v, sizeof(int)*2);

        printf("%s\n", str);

        close(socket_acc);

    }

    return 0;
}