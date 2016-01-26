#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "hangman.h"

int server_handshake(int *from_client){
  int to_client;
  char buffer[100];
  
  mkfifo("HANGMAN", 0644);
  *from_client = open("mario", O_RDONLY);
  
  read(*from_client, buffer, sizeof(buffer));
  printf("<server>connection received[%s]", buffer);
  remove("HANGMAN");
  
  to_client = open(buffer, O_WRONLY);
  write(to_client, buffer, sizeof(buffer));
  
  return to_client;
}

int main(){
  int to_client;
  int from_client;
  char buffer[100];

  while(1){
    printf("<server> waiting for connection\n");
    to_client = server_handshake(&from_client);
    
    while(read(from_client, buffer, sizeof(buffer))){
      printf("<server> received [%s]\n", buffer);
      //      process(buffer);
      write(to_client, buffer, sizeof(buffer));
      strncpy(buffer,"", sizeof(buffer));
      close(to_client);
    }
  }
  return 0;
}
