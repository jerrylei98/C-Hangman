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
\n\t +---+\
\n\t |   |\
\n\t     |\
\n\t     |\
\n\t     |\
\n\t     |\
\n\t========\n", 

"\
\n\t +---+\
\n\t |   |\
\n\t O   |\
\n\t     |\
\n\t     |\
\n\t     |\
\n\t========\n",

"\
\n\t +---+\
\n\t |   |\
\n\t O   |\
\n\t |   |\
\n\t     |\
\n\t     |\
\n\t========\n",

"\
\n\t +---+\
\n\t |   |\
\n\t O   |\
\n\t/|   |\
\n\t     |\
\n\t     |\
\n\t========\n",

"\
\n\t +---+\
\n\t |   |\
\n\t O   |\
\n\t/|\\  |\
\n\t     |\
\n\t     |\
\n\t========\n",

"\
\n\t +---+\
\n\t |   |\
\n\t O   |\
\n\t/|\\  |\
\n\t |   |\
\n\t/    |\
\n\t========\n",

"\
\n\t +---+\
\n\t |   |\
\n\t O   |\
\n\t/|\\  |\
\n\t |   |\
\n\t/ \\  |\
\n\t========\n"

};

int max_words = 1;

char *words[1] = {"Majority Rule"};//, "Checks and Balances", "Unitary System", "Federalism"};


char *definitions[1] = {"A fundamental democratic principle requiring that the majority's view be respected. Nonetheless"};//, "System in which each branch of government can limit the power of the other two branches. For example", "System of government in which all power is invested in a central government.", "A system of government in which power is divided by a written constitution between a central government and regional governments. As a result"};


void setup_game(void){
  game_set.current_hangman = 0;

  game_set.index_word = rand_num(max_words);
  game_set.given_word = str_upper(words[game_set.index_word]);
  game_set.given_def = definitions[game_set.index_word];
  game_set.length_word = strlen(game_set.given_word);

  //int current_game_t[game_set.length_word];
  int c1 = 0;
  while(c1 < game_set.length_word){
    if(game_set.given_word[c1] == ' ')
      game_set.current_game[c1] = 2;
    if(game_set.given_word[c1] != ' ')
      game_set.current_game[c1] = 0;
    c1++;
  }
  c1 = 0;
  while(c1 < 26){
    game_set.char_guess[c1] = 0;
    c1++;
  }
}

void print_game(void){
  printf("\n%s\n", hangman_numbers[game_set.current_hangman]);
  /*printf("\n\t%s\n", game_set.given_word); 
  int c1 = 0;
  while(c1 < game_set.length_word){
    printf(" %d", *(game_set.current_game +c1));
    c1++;
  }
  Used only to check characters -- TESTING PURPOSES ONLY*/ 
  show_current_game();
  show_char_guessed();
  printf("\n%s\n", game_set.given_def);
}


int rand_num(int DIVIDE){
  int c = open("/dev/urandom", O_RDONLY);
  unsigned int num;
  read(c, &num, 4);
  close(c);
  return num % DIVIDE;
}

char *str_upper(char *str){
  char *str2 = malloc(strlen(str)+1);
  int c1 = 0;
  while(c1 < strlen(str)){
    str2[c1] = toupper(str[c1]);
    c1++;
  }
  str2[c1] = '\0';
  return str2;
}
  

void show_current_game(void){
  int c1 = 0;
  printf("\t");
  while(c1 < game_set.length_word){
    if(game_set.current_game[c1] == 0)//game_set.current_game[c1] == 0)
      printf(" _");
    if(game_set.current_game[c1] == 1)
      printf(" %C", game_set.given_word[c1]);
    if(game_set.current_game[c1] == 2)
      printf("\n\t");
    c1++;
  }
  printf("\n");
}

void show_char_guessed(void){
  int c1 = 0;
  printf("\tCharacters Guessed:");
  while(c1 < 26){
    if(game_set.char_guess[c1] == 1){
      char char_show = c1 + 65;
      printf(" %c", char_show);
    }
    c1++;
  }
}

int win_lose(void){ //checks if current_game has any fails, returns 0 if game is not won, returns 1 if game is won (everything in current_game is 1
  if(game_set.current_hangman == 7)
    return 2;
  int c1 = 0; 
  while(c1 < game_set.length_word){
    if(game_set.current_game[c1] == 0)
      return 0;
    c1--;
  }
  return 1;
}
  
void update_current_game(char *str){ //changes the game_set.current_game by checking if str has is only 1 char, or matches the game_set.given_word. If it is longer than 1, does not check and does not add to game_set.current_hangman. 
  if(strlen(str) == strlen(game_set.given_word)){ //game finished
    if(strcmp(str_upper(str), game_set.given_word) == 0){
      int c1 = 0;
      while(c1 < game_set.length_word){
	game_set.current_game[c1] = 1;
	c1++;
      }
    }
    else
      game_set.current_hangman++;
    return;
  }
  if(strlen(str) == 1){ //guess 1 character
    char j = toupper(str[0]);
    if(j == ' ') //space is not a letter that can be guessed
      return;
    if(game_set.char_guess[j-65] == 1) //character has been guessed before
      return;
    if(game_set.char_guess[j-65] == 0){
      game_set.char_guess[j-65] = 1;
      int c1 = 0;
      int yes_no = 0;
      while(c1 < game_set.length_word){
	if(game_set.given_word[c1] == j){
	  game_set.current_game[c1] = 1;
	  yes_no++;
	}
	c1++;
      }
      if(yes_no > 0)
	return;
      if(yes_no == 0){
	game_set.current_hangman++;      
	return;
      }
    }
  }
}
      


/*
int main(){
  setup_game();
  print_game();
  /*  char *funtimes = "funTiMES";
  printf("\nLower: %s", funtimes);
  funtimes = str_upper(funtimes);
  printf("\nUpper: %s\n", funtimes);
  update_current_game("m");
  print_game();
  update_current_game("R");
  print_game();
  update_current_game("A");
  print_game();
  update_current_game("MaJorIty RuLe");
  print_game();


  printf("\n\n");
  return 0;
}*/


