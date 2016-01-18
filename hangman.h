#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>

void str_upper(char *str);
int win_lose(int current_game[]);
int rand_num(int divide);
void setup_game();

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
