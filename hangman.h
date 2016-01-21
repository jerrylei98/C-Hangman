#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>

char *str_upper(char *str); //changes the string to uppercaes
char *show_current_game(); //returns a string that uses the true/false or space array to return underscore or the character that is guessed
int win_lose(int current_game[]); //checks if there is anything in the array that has 0, meaning that there are still characters that are not guessed
int rand_num(int divide); //random number to grab random word(server sided)

void setup_game();
void print_game(); //prints the hangman things that are needed (hangman ascii, word with holes, definition + more)



typedef struct game{
  int index_word;
  char *given_word;
  char *given_def;
  int length_word;
  int current_hangman;
  int *current_game;
} hangman_t;

hangman_t game_set;

#endif
