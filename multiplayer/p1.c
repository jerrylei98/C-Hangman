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
  strncpy(buffer, "Ready.", sizeof(buffer));
  write(to, buffer, sizeof(buffer));

  return to;
}

void connect(int from, int to){
  char buffer[1024];
  while(read(from, buffer, sizeof(buffer))){
    printf("%s", buffer);
    update_current_game(buffer);
    strcpy(buffer, print_game());
    write(to, buffer, sizeof(buffer));
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
    printf("%s", print_game());
    to = handshake(&from);
    connect(from, to);
    close(to);
  }
  return 0;
}

