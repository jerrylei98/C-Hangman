#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include <sys/stat.h>
#include <signal.h>

#include "hangman.h"

int handshake(int *from){
  int to;
  char buffer[1024];
  
  mkfifo("HANGMAN", 0644);
  *from = open("HANGMAN", O_RDONLY);
  printf("\nConnected.\n");
  remove("HANGMAN");

  read(*from, buffer, sizeof(buffer));
  printf("Client %s reached.\n", buffer);
  to = open(buffer, O_WRONLY);
  strncpy(buffer, "Reached", sizeof(buffer));
  write(to, buffer, sizeof(buffer));

  return to;
}

void connect(int from, int to){
  char buffer[1024];
  while(read(from, buffer, sizeof(buffer))){
    update_current_game(buffer);
    char *buff = print_game();
    write(to, buff, sizeof(buff));
  }
}

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("\nDone.\n");
    remove("HANGMAN");
    exit(0);
  }
}

int main(){
  signal(SIGINT, sighandler);

  setup_game();

  int to;
  int from;
  while(1){
    printf("Waiting...\n");
    to = handshake(&from);
    connect(to, from);
    close(to);
  }
  return 0;
}

