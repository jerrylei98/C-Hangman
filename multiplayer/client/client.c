#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>

int main(int argc, char **argv){
  int socket_id;
  char buffer[256];
  int i;

  socket_id=socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in sock;
  sock.sin_family = AF_INET;
  sock.sin_port = htons(5000);
  
  inet_aton("104.131.83.105", &(sock.sin_addr));
  bind(socket_id, (struct sockaddr *)&sock, sizeof(sock));

  i = connect(socket_id, (struct sockaddr *) &sock, sizeof(sock));
  printf("<client> connect returned %d\n", i);

  read(socket_id, buffer, sizeof(buffer));
  printf("<client> received: [%s] \n", buffer);
  close(socket_id);
    
  return 0;
}
