#include <fcntl.h>

int rand_num(int DIVIDE){
  int c = open("/dev/urandom", O_RDONLY);
  unsigned int num;
  read(c,&num,4);
  close(c);
  return num % DIVIDE;
}

typedef struct game{
  int index_word;
  char *given_word;
  char *given_def;
  int current_hangman;
} hangman_t;

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


