#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

//needed for server/clients (new header files)                                                                                                           
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//needed for clients
#include <arpa/inet.h>

int main(int argc, char **argv){
  int socket_id;
  char buffer[256];
  int i;

  //create socket
  socket_id=socket(AF_INET, SOCK_STREAM, 0);
  
  //bind to port/address
  struct sockaddr_in sock;
  sock.sin_family = AF_INET;
  sock.sin_port = htons(5000);
  
  inet_aton("104.131.83.105", &(sock.sin_addr));
  bind(socket_id, (struct sockaddr *)&sock, sizeof(sock));

  //attempt a connection
  i = connect(socket_id, (struct sockaddr *) &sock, sizeof(sock));
  printf("<client> connect returned %d\n", i);
  /*  if(i == -1){
    printf("<client> error: %d %s\n", errno, strenno(errno));
    exit(0);
  } Who needs errors?
  */
  read(socket_id, buffer, sizeof(buffer));
  printf("<client> received: [%s] \n", buffer);
  close(socket_id);
    
  return 0;
}
