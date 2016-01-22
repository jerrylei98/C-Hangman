#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "hangman.h"


int main(){
  setup_game();
  print_game();
  update_current_game("m");
  print_game();
  update_current_game("A");
  print_game();
  update_current_game("C");
  print_game();
  update_current_game("AAAAAAAAAAAAA");
  print_game();

  printf("\n\n");



  return 0;
}
