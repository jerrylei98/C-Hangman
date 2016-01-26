#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h> 
#include <sys/socket.h>  
#include <netinet/in.h>

#include "hangman.h"

int main(){
  setup_game();

  int socket_id, socket_client;

  socket_id = socket(AF_INET, SOCK_STREAM,0); 
  struct sockaddr_in listener;
  listener.sin_family = AF_INET; 
  listener.sin_port = htons(5000); 
  listener.sin_addr.s_addr = INADDR_ANY; 

  bind(socket_id, (struct sockaddr *)&listener, sizeof(listener));
  
  listen(socket_id, 1);
  printf("<server listening>\n");

  while(1){
    if(game_set.current_hangman < 7){
      socket_client = accept(socket_id, NULL, NULL);
      printf("<server> connected: %d\n", socket_client);
  
      write(socket_client, print_game(), sizeof(print_game()));
    }
    else if(game_set.current_hangman > 6){

      close(socket_client);
      close(socket_id);
    }
  }
  return 0;
}
