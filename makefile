all: 

hangman: hangman.c hangman.h test.c
	gcc -o test.c hangman
run:
	./hangman
clean:
	rm *~
	rm *.o
