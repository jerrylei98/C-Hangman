#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "hangman.h"


int main(){
  setup_game();
  printf("\nWord: %s\nDefinition: %s\n", game_set.given_word, game_set.given_def);
  return 0;
}
