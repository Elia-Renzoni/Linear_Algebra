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
The conjecture is true if the sequence end with $1$
* Cramer > 
```C
/* definizione della funzione per la verifica della congettura 
 * di Cramer */
void calcola_cramer(const int valore_numeri[])  /* input : valore dei numeri */
{
    /* dichiarazione delle variabili locali alla funzione */
    double num_p;            /* lavoro : numero piu' piccolo */
    int    i,                /* lavoro : variabile di controllo */
	   differenza,       /* lavoro : differenza tra i due numeri */
	   val_ass;          /* lavoro : valore assoluto della differenza */
    double log_natu,         /* lavoro : logaritmo naturale del num. piu' piccolo */
	   quadr_ln;         /* lavoro : quadrato del logaritmo naturale */

    /* calcola la differenza tra i numeri e assegna il numero 
     * piu' piccolo alla variabile num_p */
    for (i = 0;
        (i < MAX_ARR_CRAMER);
	 i++)
    
	if (i == 1)
	{
	    differenza = valore_numeri[i] - valore_numeri[i - 1];
	    num_p = valore_numeri[i - 1];
	}

    /* calcola e comunica all'utente i risultati delle due 
     * operazioni */
    val_ass = abs(differenza);
    printf("Valore assoluto della differenza : %d \n",
           val_ass);
    log_natu = log(num_p);
    quadr_ln = pow(log_natu, 2.0);
    printf("Quadrato del ln del numero piu' piccolo : %f \n",
           quadr_ln);
    
}
```
The conjecture is ture if ![](https://wikimedia.org/api/rest_v1/media/math/render/svg/4f6d7a86e7873aaa14b2f9cd4f5b61d19e0ce787)

