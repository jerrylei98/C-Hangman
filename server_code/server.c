#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//needed for server/clients (new header files)
#include <sys/types.h> 
#include <sys/socket.h>  
#include <netinet/in.h>

#include "hangman.h"

int main(){
  int socket_id, socket_client;
  //ip address, type of port, port, protocol


  //create socket (just sets up operating system to know that there is a socket)
  socket_id = socket(AF_INET, SOCK_STREAM,0); 
  //AF_INET is a constant to what IP type used (this is for IPv4) 
  //SOCK_STREAM = TCP //SOCK_DGRAM = UDP 
  //0 is suggested

  //bind to port/address
  struct sockaddr_in listener;
  listener.sin_family = AF_INET; //socket type IPv4
  listener.sin_port = htons(5000); // port #
  listener.sin_addr.s_addr = INADDR_ANY; //bind to any incoming address

  // once all setup ^^
  bind(socket_id, (struct sockaddr *)&listener, sizeof(listener));
  

  //just opens socket 
  listen(socket_id, 1);
  printf("<server listening>\n");
  
  socket_client = accept(socket_id, NULL, NULL);
  printf("<server> connected: %d\n", socket_client);
  
  setup_game();
  char buffer[256];
  while(game_set.current_hangman < 7){
    char *temp = print_game();
    write(socket_client, temp, strlen(temp));
    read(socket_id, buffer, sizeof(buffer));
  }
  close(socket_client);
  close(socket_id);
    
}  

