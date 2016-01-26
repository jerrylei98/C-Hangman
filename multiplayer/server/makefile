all: hangman.c hangman.h p1.c p2.c
#	@gcc -c hangman.c
#	@gcc -c p1.c
	gcc -o p1 hangman.c p1.c
	gcc -o p2 p2.c
	@echo p1 picks the word/gives a clue
	@echo p2 guesses until the game ends
clean:
	rm p1
	rm p2
	rm *.~
	rm *.o


