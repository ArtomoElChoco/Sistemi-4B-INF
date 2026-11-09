#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

Studente* creaNodo();

typedef struct studente{
	int matr;
	char cognome[MAX];
	float inf, sis, tpsit;
} Studente;


void StampaNodo(Studente* nodo);

int main(void){
	
	Studente* nodo = NULL;
	
	nodo = creaNodo();
	StampaNodo(nodo);
	free(nodo);
	
	
	return 0;
}

Studente* creaNodo(){
	Studente* pStu;
	int matr;
	float info, sistem, tech;
	char cogn[MAX];
	printf("Inserisci la matricola");
	scanf("%d", &matr);
	fflush(stdin);
	printf("Inserisci cognome");
	gets(cogn);
	printf("Inserisci Informatica");
	scanf("%f", &info);
	printf("Inserisci Sistemi");
	scanf("%f", &sistem);
	printf("Inserisci la TPSIT");
	scanf("%f", &tech);
	
	pStu = (Studente*)malloc(sizeof(Studente));
	pStu->matr = 100;
	pStu->inf = 7.6;
	pStu->sis = 6.5;
	strcpy(pStu->cognome, "Rossi");
	return pStu;
}

void StampaNodo(Studente* nodo){
	printf("\nSTAMPA STUDENTE\n");
	printf("%d\t$
}