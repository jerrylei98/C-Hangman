all: hangman.c hangman.h word_giver.c
	gcc -c hangman.c
	gcc -c word_giver.c
	gcc -o word_giver hangman.o word_giver.o
	gcc -o word_guesser word_guesser.c

run:
	./server
