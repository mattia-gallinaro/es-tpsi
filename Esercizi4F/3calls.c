#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
//1  stout and write
//0 stdin and read
int main(int argc, char *argv[]) {
  if(argc != 2){
    printf("Il numero degli argomenti e' errato");
    exit(1);
  }
  int p1p2[2], p2p3[2], p3p0[2], pid1,pid2, pid3, total;
  char str[1000];
  do{
    printf("\nInserisci la stringa da cercare all'interno del file %s ", argv[1]);
    scanf("%s", str);
    if(pipe(p1p2) != 0){
      printf("Errore nella generazione della pipe tra p1 e p2");
      exit(1);
    }
    else{
      pid1 = fork();//creo il primo figlio
      if(pid1 == 0){
        close(1);
        dup(p1p2[1]);
        close(p1p2[0]);
        close(p1p2[1]);

        execl("/bin/cat", "cat", argv[1], NULL);
        exit(1);
      }
      else
      {
        if(pipe(p2p3) != 0){
        printf("Errore nella generazione della pipe tra p2 e p3");
        exit(1);
      }
        pid2 = fork();//crea il secondo figlio
        if(pid2 == 0){
          close(0);
          dup(p1p2[0]);
          close(p1p2[0]);
          close(p1p2[1]);
          
          close(1);
          dup(p2p3[1]);
          close(p2p3[0]);
          close(p2p3[1]);

          execl("/bin/grep", "grep", "-o", str, NULL);
          exit(1);//in caso di errore della chiamata di sistema execl
        }
        else{
          //wait(&pid2);
          close(p1p2[0]);//chiudo definitivamente la pipe tra p1 e p2
          close(p1p2[1]);
          if(pipe(p3p0) != 0){
            printf("Errore nella generazione della pipe tra p3 e il padre");
            exit(1);
          }
          pid3 =fork();
          if(pid3 == 0){//terzo figlio 
            close(0);
            dup(p2p3[0]);
            close(p2p3[0]);
            close(p2p3[1]);

            close(1);
            dup(p3p0[1]);
            close(p3p0[0]);
            close(p3p0[1]);

            execl("/bin/wc", "wc ","-l", NULL);
            exit(1);
          }
          else{
            close(p2p3[0]);
            close(p2p3[1]);
            char sr[100];
            read(p3p0[0], sr, sizeof(sr));
            printf("\nLa parola %s e' stata trovata %d volte",str, atoi(sr));
            total += atoi(sr);
            close(p3p0[0]);
            close(p3p0[1]);
          }
          //else{
            //printf("Errore nella generazione del terzo //figlio");
            //exit(1);
          //}
        }
      }
    }
  }while(strcmp(str, "fine") != 0);
  printf("\nIl numero di parole totali trovate sono %d", total);
  return 0;
}
