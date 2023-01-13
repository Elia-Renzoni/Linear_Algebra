calcolo_congetture: congetture_beal_cramer_collatz.c Makefile
	gcc -ansi -Wall -O congetture_beal_cramer_collatz.c -o congetture_beal_cramer_collatz -lm
pulisci:
	rm -f congetture_beal_cramer_collatz.o
pulisci_tutto:
	rm -f congetture_beal_cramer_collatz congetture_beal_cramer_collatz.o
