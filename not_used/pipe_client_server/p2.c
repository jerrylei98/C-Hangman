#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

int client_handshake(int *from_server){ 
  int to_server;
  char buffer[100];
  sprintf(buffer, "%d", getpid()); // Prints the string version of
  // The int returned by getpid() to the buffer
  // Note that this becomes the name of the private pipe 
  // in the next line.
  mkfifo(buffer, 0644);
  to_server = open("HANGMAN", O_WRONLY);
  write(to_server, buffer, sizeof(buffer)); //passing the PID
  // into to_server to set up the connection
  *from_server=open(buffer, O_RDONLY); // Server has connected 
  // to pipe!!!
  remove(buffer); // Bye-bye named pipe!
  read(*from_server, buffer, sizeof(buffer)); // two ends of
  // pipe now have the sam info so they can talk
  printf("<client> connection established: [%s]\n", buffer);
  return to_server;
}
int main(){
  int to_server;
  int from_server;
  char buffer[100];
  to_server = client_handshake(&from_server);
  while(1){ // Forever loop so that we can keep using the pipe
    // until we quit
    printf("<client> enter stuff\n");
    fgets(buffer, sizeof(buffer), stdin);
    write(to_server, buffer, sizeof(buffer));
    read(from_server, buffer, sizeof(buffer));
    printf("<client> received: [%s]\n", buffer);
  }
  close(to_server);
  close(from_server);
  return 0;
}
