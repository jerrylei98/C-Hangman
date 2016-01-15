all: hangman.c hangman_ASCII.h
	gcc hangman.c -o hangman
run:
	./hangman
clean:
	rm hangman
	rm *~
	rm *.o
