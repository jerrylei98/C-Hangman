#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "hangman.h" //header file containing the words and the hangman ascii values from 0-6. words[0-20], definitions[0-20], hangman_numbers[0-6], max_words for cap and rand_num
 
int win_lose(int current_game[]){ //checks if current_game has any fails, returns 0 if game is not won, returns 1 if game is won (everything in current_game is 1
  int c1 = sizeof(current_game)/sizeof(int); //elements in current_game
  while(c1 > 0){
    if(current_game[c1] == 0)
      return 0;
    c1++;
  }
  return 1;
}
  

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
      game_set.current_game[c1] = 1;
    else
      game_set.current_game[c1] = 0;
    printf("%d ", game_set.current_game[c1]);
    c1++;
  }
}


int main(){
  setup_game();
  printf("\nWord: %s\nDefinition: %s\n", game_set.given_word, game_set.given_def);
  return 0;
}

