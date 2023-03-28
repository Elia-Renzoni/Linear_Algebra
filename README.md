# Linear Algebra Project 
> University of Urbino, Procedural Programming Teaching Project - Bachelor's Degree in Applied Computer Science

The project is about solving the conjectures of Beal, Cramer and Collatz. 


* Beal
```C
void calcola_beal(const int valore_basi[],          /* input : valore delle basi */
		  const int valore_esponenti[])     /* input : valore degli esponenti */
{
    /* dichiarazione delle variabili locali alla funzione */
    int contatore;                        /* lavoro : variabile di controllo */
    int risultati[MAX_ARR_BEAL];          /* lavoro : valore delle potenze */
    int somma_risultati = 0;              /* lavoro : somma delle potenze */
    int basi_congettura[MAX_ARR_BEAL];    /* lavoro : valori delle basi della congettura */

    /* elevamento a potenza, somma tra le potenze e verifica
     * se la congettura e' verificata o meno */
    for (contatore = 0;
        (contatore < MAX_ARR_BEAL);
	 contatore++)
    {
	risultati[contatore] = pow(valore_basi[contatore],
			           valore_esponenti[contatore]);
	basi_congettura[contatore] = valore_basi[contatore];

	if (contatore < 2)
	{
	    somma_risultati += risultati[contatore];
	}
	else if (contatore == 2)
	{
	    if (somma_risultati < risultati[contatore] || 
		somma_risultati > risultati[contatore])
	    {
	         printf("LA CONGETTURA NON E' VERIFICATA ! \n");
	    }
		    
	    /* trasferire il valore delle basi a,b e c alla seguente funzione
	     * per verificare se hanno fattori primi in comune */
	    fattore_primo(basi_congettura);
	}
    }
}
```
The conjecture is true if $A^x$ + $B^y$ = $C^z$ when $x, y, z > 2$ are $Z^+$ then $A, B, C$  have a prime factor in common.

* Collatz > 
```C
/* definizione della funzione per la verifica della congettura 
 * di Collatz */
void calcola_collatz(int num)     /* input : valore del numero */
{
    /* dichiarazione della variabile locale alla funzione */
    int num_pari;            /* lavoro : esito della verifica del numero */

    /* numero pari o dispari */
    num_pari = num % 2;
    /* caso base */
    if (num == 1)
    {
	printf("%d \n",
	       num);
    }
    /* caso generale */
    else if (num > 1 && num_pari == 0)
    {
	printf("%d \n",
	       num);
	calcola_collatz(num / 2);
    }
    else
    {
	printf("%d \n",
	       num);
        calcola_collatz(num * 3 + 1);
    }
}
```
* Cramer > 

