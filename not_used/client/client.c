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
  char buffer[1024];
  int i;

  socket_id=socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in sock;
  sock.sin_family = AF_INET;
  sock.sin_port = htons(5000);
  
  inet_aton("104.131.83.105", &(sock.sin_addr));
  bind(socket_id, (struct sockaddr *)&sock, sizeof(sock));

  i = connect(socket_id, (struct sockaddr *) &sock, sizeof(sock));
  printf("<client> connect returned %d\n", i);

  while(1){
    int LINE_CAP = 1024;
    char line[LINE_CAP];
    printf("\nEnter guess (single char or full word): ");
    fgets(line, LINE_CAP, stdin);
    if(line[strlen(line - 1)]=='\n')
      line[strlen(line - 1)] = '\0';
    char *receive_line = line;
    send(socket_id, receive_line, sizeof(receive_line), 0);
    read(socket_id, buffer, sizeof(buffer));
    printf("<client> received: \n%s \n", buffer);
  }
  close(socket_id);
    
  return 0;
}
