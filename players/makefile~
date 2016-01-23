all:

server: hangman.c hangman.h server.c
	gcc -c hangman.c
	gcc -c server.c
	gcc -o server hangman.o server.o
run:
	./server
