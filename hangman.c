#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

#include "hangman.h" //header file containing the words and the hangman ascii values from 0-6. words[0-20], definitions[0-20], hangman_numbers[0-6], max_words for cap and rand_num


char *hangman_numbers[7] = {
"\
\n +---+\
\n |   |\
\n     |\
\n     |\
\n     |\
\n     |\
\n========\n", 

"\
\n +---+\
\n |   |\
\n O   |\
\n     |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n |   |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|   |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|\\  |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|\\  |\
\n |   |\
\n/    |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|\\  |\
\n |   |\
\n/ \\  |\
\n========\n"

};

int max_words = 4;

char *words[4] = {"Majority Rule", "Checks and Balances", "Unitary System", "Federalism"};


char *definitions[4] = {"A fundamental democratic principle requiring that the majority's view be respected. Nonetheless", "System in which each branch of government can limit the power of the other two branches. For example", "System of government in which all power is invested in a central government.", "A system of government in which power is divided by a written constitution between a central government and regional governments. As a result"};


void setup_game(){
  game_set.current_hangman = 0;

  game_set.index_word = rand_num(max_words);
  game_set.given_word = words[game_set.index_word];
  game_set.given_def = definitions[game_set.index_word];
  game_set.length_word = strlen(game_set.given_word);

  int check_win[game_set.length_word];
  game_set.current_game = check_win;

  int c1 = 0;
  while (c1 < strlen(game_set.given_word)){
    if(game_set.given_word[c1] == ' ')
      game_set.current_game[c1] = 2;
    else
      game_set.current_game[c1] = 0;
    //  printf("%d ", game_set.current_game[c1]);
    c1++;
  }
}

int rand_num(int DIVIDE){
  int c = open("/dev/urandom", O_RDONLY);
  unsigned int num;
  read(c, &num, 4);
  close(c);
  return num % DIVIDE;
}

char *word(){
  int i = 0;
  char *

int win_lose(int current_game[]){ //checks if current_game has any fails, returns 0 if game is not won, returns 1 if game is won (everything in current_game is 1
  int c1 = sizeof(current_game)/sizeof(int); //elements in current_game
  while(c1 > 0){
    if(current_game[c1] == 0)
      return 0;
    c1--;
  }
  return 1;
}
  



int main(){
  //  setup_game();
  //printf("\nWord: %s\nDefinition: %s\n", game_set.given_word, game_set.given_def);
  char *funtimes = "funTiMES";
  printf("\nLower: %s", funtimes);
  str_upper(funtimes);
  printf("\nUpper: %s\n", funtimes);

  return 0;
}


