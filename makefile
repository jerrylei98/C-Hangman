all: 

hangman: hangman.c hangman.h test.c
	gcc -c hangman.c
	gcc -c test.c
	gcc -o app hangman.o test.o
run:
	./hangman
clean:
	rm *.o
	rm *~

