#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if(argc != 2){
    printf("Argomenti errati\n");
    exit(1);
  }
  int piped[2], fd,tot =0, status;
  char ris[10];
  char str[100];
  if(pipe(piped) != 0){
    printf("errore durante la generazione della pipe\n");
    exit(1);
  }
  do{
    printf("\nInserisci una stringa: ");
    scanf("%s", str);
    fd= fork();
    if(fd == 0){
      close(0);
      dup(piped[0]);
      close(piped[0]);
      close(1);
      dup(piped[1]);
      close(piped[1]);

      execl("/bin/grep", "grep ","-c", str, argv[1], (char *)0);
      exit(0);
    }
      read(piped[0], ris, sizeof(ris));
      printf("\nLa stringa %s e' stata letta : %d  volte\n", str, atoi(ris));
      tot += atoi(ris);
 }while(strcmp(str, "fine") != 0);
  printf("\nIl numero di stringhe totali trovate sono: %d\n", tot);
  return 0;
}
