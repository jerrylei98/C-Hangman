all: hangman.c hangman.h game.c
	gcc -c hangman.c
	gcc -c game.c
	gcc -o hangman hangman.o game.o
	@echo \Errors in BUGS. $ make run to run
	@echo Game will randomly select a word from 4 history definitions
	@echo Guess as single player
run:
	./hangman
clean:
	rm *.o
	rm hangman
	rm *~
