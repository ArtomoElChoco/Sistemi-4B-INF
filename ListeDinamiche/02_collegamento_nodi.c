#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct dipendente{
	char matricola[5];
	char cognome[MAX];
	int eta;
	struct dipendente *next; //Puntatore al nodo successivo
}Dipendenti;

Dipendenti* creaDipendente(char cogn[], int eta);

int main(void){
	Dipendenti *n1, *n2, *n3;
	srand(time(NULL));
	
	//Creazione dei nodi (ANCORA "SCOLLEGATI" TRA LORO)
	n1 = creaDipendente("Rossi", 35);
	n2 = creaDipendente("Bianchi", 42);
	n3 = creaDipendente("Verdi", 28);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	
	return 0;
}


Dipendenti* creaDipendente(char cogn[], int eta){
	Dipendenti* nodo;
	char matr[5];
	int i;
	
	for(i = 0; i < 2; i++){
		matr[i] = 'A' + (rand() % ('Z' - 'A' + 1));
	}
	for(i = 2; i < 4; i++){
		matr[i] = '0' + rand() % 10;
	}
	matr[4] = '\0';
	
	nodo = (Dipendenti*)malloc(sizeof(Dipendenti));
	strcpy(nodo->matricola, matr);
	strcpy(nodo->cognome, cogn);
	nodo->eta = eta;
	nodo->next = NULL;
	
	return nodo;
}