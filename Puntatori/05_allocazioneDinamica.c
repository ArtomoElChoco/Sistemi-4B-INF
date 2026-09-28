#include <stdio.h>
#include <stdlib.h>

/*
Memoria statica: Stack
Memoria dinamica: Heap

malloc(quanti byte riservare in memoria) --> malloc(sizeof(int)) == malloc(4) 
malloc ci restituisce il primo indirizzo da dove iniziano le celle caricate
int *p = malloc() --> bisogna fare il cast, perche non sempre va a un buon fine, perche l'indirizzo è di tipo void
int *p = (int*) malloc(sizeof(int))

calloc(Numero di elementi che verranno moltiplicati, sizeof(int))
calloc(5, sizeof(int)) == malloc(sizeof(int)*5)
int *p = (int*) calloc(5, sizeof(int))

Con la malloc il valore sporco che c'è dentro le celle di memoria viene mantenuto
Con la calloc il valore sporco che c'è dentro le celle di memoria viene cambiato con un valore neutro (0 in caso di int)

realloc(Indirizzo della prima cella, Nuova dimensione)
realloc(p, 5*sizeof(int))
Viene restituito un nuovo indirizzo perche le celle continue potrebbero interrompersi perche sono già occupate.

free(Primo indirizzo della cella che si vuole deallocare, cio'è viene liberata dall'utilizzo del programma permettendo
ad altri programmi di utilizzare quella area)
*/

void stampaVett(int a[], int dim, char s[]);

int main(void){
	int v[] = {1, 2, 3, 4, 5};
	int dimA = 5;
	
	printf("Array statico di %d elementi\n", dimA);
	stampaVett(v, dimA, "Allocazione Statica");
	
	// ALLOCAZIONE DINAMICA
	int numElem = 10;
	int *p;
	/* MALLOC => malloc(numByte) */
	p = (int*) malloc(sizeof(int)*numElem); // malloc(4*10 = 40)
	stampaVett(p, numElem, "MALLOC");
	
	/* CALLOC => calloc(numByte, type) */
	p = (int*) calloc(numElem, sizeof(int));
	stampaVett(p, numElem, "CALLOC");
	
	/* REALLOC => realloc(p, numElem*sizeof(int)) */
	p = realloc(p, numElem*sizeof(int));
	stampaVett(p, numElem, "REALLOC");
	
	/* FREE => free(indirizzo) */
	free(p);
	stampaVett(p, numElem, "FREE");
	
	/* 
		int dimA = 5;
	*/
	int *dim;
	dim = (int*) malloc(sizeof(int));
	*dim = 5;
	
	return 0;
}

void stampaVett(int a[], int dim, char s[]){
	int i;
	printf("\n%s\n", s);
	for(i = 0; i < dim; i++)
		printf("v[%d]: %d Indirizzo:%p\n", i, *(a+i), (a+i));
}