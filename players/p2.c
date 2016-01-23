#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include <sys/stat.h>
#include <signal.h>


int handshake(int *from){
  int to;
  char buffer[1024];

  mkfifo(buffer, 0644);
  to = open("HANGMAN", O_WRONLY);
  write(to, buffer, sizeof(buffer));

  *from = open(buffer, O_RDONLY);
  remove(buffer);

  read(*from, buffer, sizeof(buffer));

  printf("%s", buffer);

  return to;
}


int main(){

  int to;
  int from;
  char buffer[1024];

  to = handshake(&from);

  while(1){
    fgets(buffer, sizeof(buffer), stdin);
    //    strtok(buffer, "\n");

    write(to, buffer, sizeof(buffer));
    read(from, buffer, sizeof(buffer));

    printf("%s", buffer);
  }

  close(to);
  close(from);
  return 0;
}

