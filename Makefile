calcolo_congetture: calcolo_congetture.c Makefile
	gcc -ansi -Wall -g calcolo_congetture.c -o calcolo_congetture -lm
pulisci:
	rm -f calcolo_congetture.o
pulisci_tutto:
	rm -f calcolo_congetture calcolo_congetture.o
