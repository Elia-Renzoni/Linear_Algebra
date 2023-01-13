/************************************************/
/*  Programma per la verifica delle congetture  */
/************************************************/

/*****************************/
/* inclusione delle librerie */
/*****************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*****************************************/
/* definizione delle costanti simboliche */
/*****************************************/

#define MAX_ARR_BEAL 3               /* numero delle basi, per congettura di Beal */
#define MAX_ARR_CRAMER 2             /* numero dei valori, per congettura di Cramer */
#define BEAL_SCELTA 0	             /* scelta congettura di Beal */
#define COLLATZ_SCELTA 1	     /* scelta congettura di Collatz */
#define CRAMER_SCELTA 2		     /* scelta congettura di Cramer */

/********************************/
/* dichiarazioni delle funzioni */
/********************************/

int  acquisisci_scelta(void);
void acquisisci_beal(void);
void acquisisci_collatz(void);
void acquisisci_cramer(void);
int  verifica_primi(int valori_numeri);
void calcola_beal(const int valore_basi[],
		  const int valore_esponenti[]);
void calcola_collatz(int);
void calcola_cramer(const int valore_numeri[]);
void fattore_primo(int basi_congettura[]);

/******************************/
/* definizioni delle funzioni */
/******************************/

/* definizione della funzione main */
int main(void)
{
    /* dichiarazione della variabile locale alla funzione */
    int confronto_scelta;                /* lavoro : scelta dell'utente */                                     

    /* memorizza la scelta dell'utente */
    confronto_scelta = acquisisci_scelta();

    /* seleziona la congettura in base alla scelta */
    switch (confronto_scelta)
    {
	case BEAL_SCELTA:
	     acquisisci_beal();
	     break;

        case COLLATZ_SCELTA:
	     acquisisci_collatz();
	     break;

	case CRAMER_SCELTA:
	     acquisisci_cramer();
	     break;
    }

    return (0);
}

/* definizone della funzione per comunicare all'utente le scelte da effettuare
 * e validazione dei dati inseriti dall'utente */
int acquisisci_scelta(void)
{
    /* dichiarazione delle variabili locali alla funzione */
    int numero_scelta;               /* input : numero scelta */
    int acquisizione_errata,         /* lavoro : esito complessivo dell'acquisizione */
        esito_lettura;               /* lavoro : esito della scanf */
    
    /* acquisire la scelta dell'utente e validare i dati */
    do
    {
        printf("  SELEZIONA L'OPERAZIONE :  \n");
	printf("****************************\n");
	printf("* 0 - Congettura di Beal    *\n");
	printf("* 1 - Congettura di Collatz *\n");
	printf("* 2 - Congettura di Cramer  *\n");
	printf("*****************************\n");

	esito_lettura = scanf("%d",
			      &numero_scelta);
	acquisizione_errata = esito_lettura != 1 ||
		              numero_scelta < BEAL_SCELTA ||
			      numero_scelta > CRAMER_SCELTA;
	if (acquisizione_errata)
	    printf("Errore, il valore non e' accettabile ! \n");
	while (getchar() != '\n');
    }
    while (acquisizione_errata);

    return (numero_scelta);  
}

/* definizione della funzione per l'acquisizione e la validazione dei dati
 * relativi alla congettura di Beal */
void acquisisci_beal(void)
{
    /* dichiarazione delle variabili locali alla funzione */
    int  valore_base[MAX_ARR_BEAL],		 /* input : valore delle basi */
         valore_esponenti[MAX_ARR_BEAL];         /* input : valore degli esponenti */
    char caratteri_base[] = {'a',                /* output : caratteri id. delle basi*/
                             'b',
                             'c',},
	 caratteri_esponenti[] = {'x',           /* output : caratteri id. degli espo. */
	                          'y',
	                          'z'};
    int esito_lettura,                           /* lavoro : esito della scanf */
	acquisizione_errata,                     /* lavoro : esito complessivo dell'acq. */
	i;                                       /* lavoro : variabile di controllo */

    /* acquisire e validare i dati relativi alla congettura di Beal */
    for (i = 0;
        (i < MAX_ARR_BEAL);
	 i++)
    {
	do
	{
            printf("Inserisci il valore della base %c (>= 1) e dell'esponente %c (>= 3) : \n",
		   caratteri_base[i],
		   caratteri_esponenti[i]);

	    esito_lettura = scanf("%d%d",
			          &valore_base[i],
				  &valore_esponenti[i]);

	    acquisizione_errata = esito_lettura != 2 || 
		                  valore_base[i] < 1 ||
				  valore_esponenti[i] < 3;

	    if (acquisizione_errata)
	        printf("Errore, valori non validi ! \n");
	    while (getchar() != '\n');
	 }
	 while (acquisizione_errata);
    }

    /* trasferire i valori delle basi e degli esponenti alla seguente funzione
     * affinche' verifichi la congettura */
    calcola_beal(valore_base,
		 valore_esponenti);

}

/* definizione della funzione per l'acquisizione e la validazione
 * dei dati relativi alla congettura di Collatz */
void acquisisci_collatz(void)
{
    /* dichiarazione delle variabili locali alla funzione */
    int numero;                        /* input : valore del numero */
    int esito_lettura,                 /* lavoro : esito della scanf */
	acquisizione_errata;           /* lavoro : esito complessivo dell'acq. */

    /* acquisizione e validazione del numero */
    do
    {
	printf("Inserisci un numero > 0 : \n");
	esito_lettura = scanf("%d",
			      &numero);
	acquisizione_errata = esito_lettura != 1 ||
			      numero <= 0;
	if (acquisizione_errata)
	    printf("Errore, il valore inserito non e' valido ! \n");
	while (getchar() != '\n');
    }
    while (acquisizione_errata);

    /* trasferire il valore del numero acquisito alla seguente funzione 
     * affinche' verifichi la congettura */
    calcola_collatz(numero);
}

/* definizione della funzione per l'acquisizione e la validazione 
 * dei dati relativi alla congettura di Cramer */
void acquisisci_cramer(void)
{
    /* dichiarazione delle variabili locali alla funzione */
    char numeri_ordine[2][15] = {"Primo Numero",       /* output : stringa id. numero */
                                 "Secondo Numero"};
    int  valori_numeri[MAX_ARR_CRAMER];      /* input : valore dei numeri */
    int  indice,                             /* lavoro : variabile di controllo del ciclo */
         acquisizione_errata,                /* lavoro : ver. il numero dei valori acq.*/
	 esito_lettura,                      /* lavoro : esito della scanf */
         valori_uguali,                      /* lavoro : ver. numeri uguali */
	 valori_consecutivi,                 /* lavoro : ver. numeri consecutivi o no */
	 valore_minore,                      /* lavoro : ver. se il primo numero e' < del sec. */
	 numeri_primi,                       /* lavoro : ver. numeri primi */
	 valori_piccoli,                     /* lavoro : ver. numeri troppo piccoli */
         numero_compreso,                    /* lavoro : numero compreso tra i due numeri primi */
	 verifica_numero_compreso,           /* lavoro : ver. se il numero compreso e' primo o meno */
	 numero_minore,                      /* lavoro : contiene il numero piu' piccolo fra i due */
         numero_maggiore;                    /* lavoro : contiene il numero piu' grande fra i due */

    for (indice = 0;
        (indice < MAX_ARR_CRAMER);
	 indice++)
    {
	/* acquisizione e validazione dei numeri */
	do
	{
	    printf("Inserisci il valore del %s (Numero primo e >= 11) : \n",
		   numeri_ordine[indice]);
	    esito_lettura = scanf("%d",
				  &valori_numeri[indice]);

	    acquisizione_errata = esito_lettura != 1;
	    valori_uguali = valori_numeri[indice] == valori_numeri[indice - 1];
	    valori_piccoli = valori_numeri[indice] < 11;
	    valore_minore = valori_numeri[indice] < valori_numeri[indice - 1];

	    /* invocazione della funzione per verificare se i numeri sono primi */
	    numeri_primi = verifica_primi(valori_numeri[indice]);

	    if (valori_piccoli || acquisizione_errata)
	    {
		printf("Errore, numero non valido ! \n");
	    }

	    /* se i numeri inseriti non sono primi */
	    if (numeri_primi)
	    {
		printf("Errore, il numero non e' primo ! \n");
	    }
	    /* se i numeri sono primi */
	    else 
	    {
		if (indice == 1)
		{
		    /* se i numeri primi sono uguali */
		    if (valori_uguali)
		    {
			printf("Errore, i numeri sono uguali ! \n");
		    }
			
		    else
                    {
		        /* se il secondo valore e' minore del primo */
		        if (valore_minore)
			{
			    printf("Errore, il secondo numero deve essere maggiore del primo \n");
			}
			/* se il secondo valore e' maggiore del primo */
			else 
			{
		            /* memorizza in due variabili diverse il 
			     * numero maggiore e il minore */
			    numero_minore = valori_numeri[indice - 1];
			    numero_maggiore = valori_numeri[indice];

			    /* verifica se i numeri primi inseriti sono consecutivi*/
			    for (numero_compreso = numero_minore + 1,   
			         valori_consecutivi = 0;
		                (numero_compreso < numero_maggiore);
			         numero_compreso++)
			    {
			        /* invocazione della funzione per verificare se i numeri compresi
			         * tra i due primi sono anch'essi primi */
			        verifica_numero_compreso = verifica_primi(numero_compreso);

			       /* se i numeri compresi tra i due numeri primi inseriti 
			       * sono anch'essi primi*/
			       if (verifica_numero_compreso == 0)
				      valori_consecutivi = 1;
			    }
				
		            /* messaggio all'utente */
	    		    if (valori_consecutivi)
			        printf("Errore, i numeri non sono consecutivi ! \n");
			}
				
	            }
	         }
	     }
	     while (getchar() != '\n');		
	}
	while (acquisizione_errata ||
	       valori_uguali  ||
	       valori_piccoli ||
	       numeri_primi   ||
	       valori_consecutivi ||
	       valore_minore);	    
    }

    /* trasferire il valore dei numeri alla seguente funzione
     * affinche' verifichi la congettura */
    calcola_cramer(valori_numeri);
}

/* definizione della funzione per verificare se i numeri sono
 * primi o meno */
int verifica_primi(int valori)
{
   /* dichiarazione delle varaibili locali alla funzione */
   int valori_primi;        /* output : ver. se il numero e' primo o meno*/
   int conteggio = 0;       /* lavoro : numero di divisori */
   int divisore;            /* lavoro : id. numeri primi */

   /* controlla se i numeri sono primi o meno */  
   for (divisore = 2;
       (divisore < valori);
        divisore++)
   {
	if (valori % divisore == 0)
	     conteggio++;
   }

   valori_primi = conteggio != 0;
   
   return (valori_primi);
}

/* definizione della funzione per la verifica della congettura
 * di Beal */
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

/* definizione della funzione per calcolare e comunicare 
 * all'utente se le basi a,b e c hanno un fattore primo
 * in comune e stamparlo */
void fattore_primo(int basi_congettura[])     /* input : valore delle basi */
{
    /* dichiarazione delle variabili locali alla funzione */
    int contatore,            /* lavoro : variabile di controllo */
	divisore;             /* lavoro : identifica i numeri primi divisori */
    int numero_primo;         /* lavoro : ver. se i divisori sono primi o meno*/

    /* controlla se vi sono fattori primi in comune */
    for (contatore = 0;
        (contatore < MAX_ARR_BEAL);
	 contatore++)
    {
	divisore = 2;
	while (divisore <= basi_congettura[contatore] &&
	       divisore <= basi_congettura[contatore + 1] &&
	       divisore <= basi_congettura[contatore + 2])
	{
		/* invocazione della funzione per verificare se la 
		 * variabile divisore contiene numeri primi o meno*/
	        numero_primo = verifica_primi(divisore);
		
		/* se divisore e' un numero primo */
		if (numero_primo == 0)
		{
		  /* fino a quando i valori delle basi sono divisibili 
		   * per il divisore, divide il loro valore per il divisore
		   * e stampa il valore della variabile divisore */
		  while (basi_congettura[contatore] % divisore == 0 &&
		         basi_congettura[contatore + 1] % divisore == 0 &&
		         basi_congettura[contatore + 2] % divisore == 0)
		  {
			  basi_congettura[contatore] /= divisore;
			  basi_congettura[contatore + 1] /= divisore;
			  basi_congettura[contatore + 2] /= divisore;

			  printf("Fattore primo in comune : %d \n",
			         divisore);
		  }

		}

		divisore++;
	}
    }
}










