/*

		Programma : Calcolo e verifica delle congetture di
			        Beal, Cramer e Collatz.
		Autore : Elia Renzoni.
		Contatti : Per migliorare il programma o per maggiori informazioni
			       sul progetto potete contattarmi qui : 
				   elia.renzoni03@gmail.com

		Data : 26/12/2022.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_ARR_BEAL 3		    
#define MAX_ARR_CRAMER 2	  
#define BEAL_SCELTA 0	            
#define COLLATZ_SCELTA 1	    
#define CRAMER_SCELTA 2	            
#define ESCI_SOFTWARE 3		    


int          acquisisci_scelta(void);
void         acquisisci_beal(void);
void         acquisisci_collatz(void);
void         acquisisci_cramer(void);
void         calcola_beal(const int valore_base[],                     
			  const int valore_esponenti[]);
void 	     fattore_primo(int verifica_fattore[]);
void 	     calcola_collatz(int);
void 	     calcola_cramer(const int valore_numeri[]);

int main(void) 
{
	
	int confronto_scelta;              

	confronto_scelta = acquisisci_scelta();

	if      (confronto_scelta == BEAL_SCELTA)
		acquisisci_beal();
	else if (confronto_scelta == COLLATZ_SCELTA)
		acquisisci_collatz();
	else if (confronto_scelta == CRAMER_SCELTA)
		acquisisci_cramer();
	else 
		return (0);

	return (0);
}

/* definizione della funzione per comunicare all'utente le scelte da effettuare 
   e validazione dei dati inseriti dall'utente */
int acquisisci_scelta(void) 
{
	int numero_scelta;		
	int acquisizione_errata,	
	    esito_lettura;		
	do 
	{
		printf("   SELEZIONA L'OPERAZIONE :  \n");
		printf("*****************************\n");
		printf("* 0 - Congettura di Beal    *\n");
		printf("* 1 - Congettura di Collatz * \n");
		printf("* 2 - Congettura di Cramer  *\n");
		printf("*****************************\n");
		printf(" 3 - Per uscire dal software \n");
		printf("*****************************\n");
		esito_lettura = scanf("%d",
		                      &numero_scelta);
		acquisizione_errata = esito_lettura != 1 || 
				      numero_scelta < BEAL_SCELTA || 
				      numero_scelta > ESCI_SOFTWARE;
		if (acquisizione_errata)
			printf("Errore, il valore non e' accettabile ! \n");
		while (getchar() != '\n');
	}
	while (acquisizione_errata);

	return (numero_scelta);
}

/* definizione della funzione per l'acquisizione e la validazione 
   dei dati relativi alla congettura di Beal*/
void acquisisci_beal(void) 
{
	int  valore_base[MAX_ARR_BEAL],			
	     valore_esponenti[MAX_ARR_BEAL];	        
	char caratteri_base[] = {'a','b','c'},	        
	     caratteri_esponenti[] = {'x','y','z'};	
	int  esito_lettura,				
	     acquisizione_errata,			
	     i;						

	/* acquisire e validare i dati relativi alla congettura di Beal */
	for (i = 0; i < 3; i++) 
	{
		/* acquisizione e validazioni delle basi */	
		do 
		{
			printf("Inserisci il valore della base %c >= 1 : \n",
			       caratteri_base[i]);
			esito_lettura = scanf("%d",
			      		      &valore_base[i]);
			acquisizione_errata = esito_lettura != 1 || valore_base[i] < 1;
			if (acquisizione_errata) 
				printf("Errore, valore inserito non e' valido ! \n");
			while (getchar() != '\n');
		} 
		while (acquisizione_errata);
		/* acquisizione e validazione degli esponenti */
		do 
		{
			printf("Inserisci il valore dell'esponente %c >= 3, della base %c : \n",
			        caratteri_esponenti[i],
				caratteri_base[i]);
			esito_lettura = scanf("%d",
			                      &valore_esponenti[i]);
			acquisizione_errata = esito_lettura != 1 || valore_esponenti[i] < 3;
			if (acquisizione_errata)
				printf("Errore, valore inserito non e' valido ! \n");
			while (getchar() != '\n');
		} 
		while (acquisizione_errata);
	}

	/* trasferire i valori degli esponenti e delle basi(validati) all seguente
	   funzione affinche' verifichi o meno la congettura */
	calcola_beal(valore_base,
		     valore_esponenti);
}

/* definizione della funzione l'acquisizione e la validazione 
 * dei dati relativi alla congettura di Collatz*/
void acquisisci_collatz(void) 
{

	int numero;

	int esito_lettura,
	    acquisizione_errata;

	do 
	{
		printf("Inserisci un numero > 0 : \n");
		esito_lettura = scanf("%d",
				      &numero);

		acquisizione_errata = esito_lettura != 1 || numero <= 0;
		if (acquisizione_errata)
			printf("Errore, il valore inserito non e' valido ! \n");
		while (getchar() != '\n');
	} 
	while (acquisizione_errata);

	/* invocazione della funzione per il calcolo della congettura*/
	calcola_collatz(numero);
}

/* Definizione della funzione per l'acqusizione e la validazione
*  dei dati relativi alla congettura di Cramer*/
void acquisisci_cramer(void) 
{

    int valore_numeri[MAX_ARR_CRAMER];
	char numeri_ord[2][15] = {"primo numero","secondo numero"};
	int i,
	    esito_lettura;
	int contatore,
	    divisore;
	int valori_min_diversi,
	         valori_uguali,
		   div_diverso,
		 n_consecutivi;

	/* acquisisce i valori e controlla se rispettano i vincoli di progetto*/
	for (i = 0; i < 2; i++) 
	{
		do 
		{
			printf("Inserisci il valore del %s  (Numero primo e >= 11) : \n",
			       numeri_ord[i]);
			esito_lettura = scanf("%d",
					      &valore_numeri[i]);

			valori_min_diversi = esito_lettura != 1 || valore_numeri[i] < 11;
			valori_uguali = valore_numeri[i] == valore_numeri[i - 1];
			n_consecutivi = valore_numeri[i] < valore_numeri[i - 1];

			if (valori_min_diversi) 
				printf("Errore, valore non valido ! \n");
			else 
			{
				for (contatore = 2,
			     	 divisore = 0;
			    	(contatore < valore_numeri[i]);
			     	 contatore++) 
				{
					if (valore_numeri[i] % contatore == 0)
						divisore++;
				}
				div_diverso = divisore != 0;
				if (div_diverso) 
				{
					printf("Errore, il numero non e' primo ! \n");
				}
				else 
				{
					if (i == 1) 
					{ 
						if (valori_uguali) 
						{ 
							printf("Errore, i numeri sono uguali \n");
						}
						else 
						{
							if (n_consecutivi) 
							{
								printf("Errore, numeri non consecutivi \n");
							}
						}
					}			
				}		
			}
			while (getchar() != '\n');
		}
		while (div_diverso || valori_min_diversi || valori_uguali || n_consecutivi);
	}
	/* invocazione della funzione per il calcolo della congettura di Cramer */
	calcola_cramer(valore_numeri);
}

/* Calcolo della congettura di Beal */
void calcola_beal(const int valore_base[],
		  const int valore_esponenti[]) 
{


	int contatore;
	int risultati[MAX_ARR_BEAL];
	int somma_risultati = 0;
	int verifica_fattore[MAX_ARR_BEAL];

	for (contatore = 0;
	     contatore < 3;
	     contatore++) 
	{
		risultati[contatore] = pow(valore_base[contatore],
					   valore_esponenti[contatore]);
		verifica_fattore[contatore] = valore_base[contatore];

		if (contatore < 2)
		{
			somma_risultati += risultati[contatore];
		}
		else if (contatore == 2) 
		{
			if (somma_risultati < risultati[contatore])
			{
				printf("LA CONGETTURA NON E' VERIFICATA ! \n");
			}
			else if (somma_risultati > risultati[contatore]) 
			{
				printf("LA CONGETTURA NON E' VERIFICATA ! \n");
			}
			else
			{	
				printf("LA CONGETTURA E' VERIFICATA ! \n");
			}
			fattore_primo(verifica_fattore);
		}
	}
	/* Ritorno alla funzione main */
	main();
}

/* Calcolo della congettura di Collatz tramite ricorsione */
void calcola_collatz(int num) 
{
	int num_pari;
	num_pari = num % 2;

	if (num == 1) 
	{
		printf("%d \n",
		       num);
		printf("LA CONGETTURA E' VERIFICATA ! \n");
		main();
	}
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
/* Calcolo della congettura di Cramer*/
void calcola_cramer(const int valore_numeri[]) 
{
	int num_p,
	        i;
	int differenza,
	       val_ass,
	      log_natu,
	      quadr_ln;

	for (i = 0;
	     i < 2;
	     i++) 

		if (i == 1) 
		{
			differenza = valore_numeri[i] - valore_numeri[i - 1];
			num_p = valore_numeri[i - 1];
		}

	printf("Differenza = %d \n",
	       differenza);

	val_ass = abs(differenza);

	printf("Valore assoluto della differenza : %d \n",
	       val_ass);
	log_natu = log(num_p);

	quadr_ln = pow(log_natu, 2);

	printf("Quadrato del ln del numero piu' piccolo : %d \n",
	       quadr_ln);

	if (val_ass < quadr_ln) 
	{
		printf("LA CONGETTURA E' VERIFICATA ! \n");
	}
	else
	{	
		printf("LA CONGETTURA NON E' VERIFICATA ! \n");
	}

	main();	
}

/* Verifica se le basi a, b e c hanno dei fattori primi in comune */
void fattore_primo(int verifica_fattore[])
{

	int contatore,
	    divisore;

	for (contatore = 0;
	     contatore < 3;
	     contatore++)
	{
		divisore = 2;

		while (divisore <= verifica_fattore[contatore] &&
		       divisore <= verifica_fattore[contatore + 1] &&
		       divisore <= verifica_fattore[contatore + 2])
		{

			while (verifica_fattore[contatore] % divisore == 0 &&
			       verifica_fattore[contatore + 1] % divisore == 0 &&
			       verifica_fattore[contatore + 2] % divisore == 0)
			{
				verifica_fattore[contatore] /= divisore;
				verifica_fattore[contatore + 1] /= divisore;
				verifica_fattore[contatore + 2] /= divisore;

				printf("Fattore primo in comune : %d \n",
				       divisore);
			}
			divisore++;
		}
		divisore = 2;
	}

}
