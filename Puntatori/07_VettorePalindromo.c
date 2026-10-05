#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void CaricaVet(int *v, int *dim);
void StampaVet(int *v, int *dim);
void ControllaPalindromo(int *v, int *dim);

// Dato un vettore di interi grande n
// a. Caricare il vettore con valori casuali
// b. Dire se è palindromo
int main(void){
	int *pV;
	int *dim;
	srand(time(NULL));
	dim = (int*) malloc(sizeof(int));
	printf("Inserisci lunghezza: ");
	scanf("%d", dim);
	pV = (int*) malloc(sizeof(int) * (*dim));
	
	CaricaVet(pV, dim);
	StampaVet(pV, dim);
	ControllaPalindromo(pV, dim);
	
	return 0;
}

void CaricaVet(int *v, int *dim){
	int *i = (int*) malloc(sizeof(int));
	for(*i = 0; *i < *dim; (*i)++){
		// *v = (rand() % 10) + 1;
		*v = 0;
		v++;
	}
}

void StampaVet(int *v, int *dim){
	int *i = malloc(sizeof(int));
	for(*i = 0; *i < *dim; (*i)++){
		printf("v[%d]: %d\n", *i, *(v+*i));
	}
}

void ControllaPalindromo(int *v, int *dim){
	int *i = (int*) malloc(sizeof(int));
	*i = *dim;
	int *bob = (int*) malloc(sizeof(int));
}