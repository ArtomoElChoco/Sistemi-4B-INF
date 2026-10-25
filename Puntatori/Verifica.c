#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visualizzaMenu(char* scelta);
void caricaMultipli(int* vetInt, int* lunghezza, int* mult);
int contaVocali(char* frase);

int main(void){
	srand(time(NULL));
	int* lunghezza;
	char* input = (char*)malloc(sizeof(char));
	do{
		// system("@cls||clear");
		visualizzaMenu(input);
		switch(*input){
			case 'a':
				lunghezza = (int*)malloc(sizeof(int));
				printf("\nInserisci lunghezza del vettore: ");
				scanf("%d", lunghezza);
				int* vetInt = (int*)calloc(*lunghezza, sizeof(int));
				int* i = (int*)malloc(sizeof(int));
				for(*i = 0; *i < *lunghezza; (*i)++){
					*(vetInt + (*i)) = (rand() % 201) - 100;
					printf("%d\n", *(vetInt + (*i)));
				}
				free(i);
				int* mult = (int*)malloc(sizeof(int));
				printf("\nInserisci un multiplo: ");
				scanf("%d", mult);
				caricaMultipli(vetInt, lunghezza, mult);
				break;
			case 'b':
				printf("Addio");
				break;
			case 'c':
				lunghezza = (int*)malloc(sizeof(int));
				printf("\nInserisci lunghezza string: ");
				scanf("%d", lunghezza);
				char* frase = (char*)calloc(*lunghezza, sizeof(char));
				int* newElem = (int*)malloc(sizeof(int));
				*newElem = 0;
				printf("\nInserisci frase: ");
				scanf("%s", frase);
				while(*(frase + (*newElem)) != '\0'){
					(*newElem)++;
				}
				frase = (char*)realloc(frase, sizeof(char) * (*newElem));
				contaVocali(frase);
				break;
			case 'q':
				break;
			default:
				printf("Hai sbagliato\n");
				break;
		}
	}while(*input != 'q');
	
	return 0;
}

int contaVocali(char* frase){
	printf("\n%s\n", frase);
	int* cont = (int*)malloc(sizeof(int));
	*cont = 0;
	int* i = (int*)malloc(sizeof(int));
	*i = 0;
	int* start = (int*)malloc(sizeof(int));
	*start = 1;
	while(*(frase + (*i)) != '\0'){
		if(*(frase + (*i)) == '*'){
			(*start)++;
		}
		if(*start % 2 == 0){
			(*cont)++;
		}
	}
	printf("\nIl totale delle vocali presenti nella sotto stringa è: %d", *cont);
}

void caricaMultipli(int* vetInt, int* lunghezza, int* mult){
	int* vetSec = (int*)calloc(*lunghezza, sizeof(int));
	int* newElem = (int*)malloc(sizeof(int));
	*newElem = 0;
	int* i = (int*)malloc(sizeof(int));
	for(*i = 0; *i < *lunghezza; (*i)++){
		if(*(vetInt + (*i)) % (*(mult)) == 0){
			*(vetSec + (*newElem)) = *(vetInt + (*i));
			printf("%d\n", *(vetSec + (*newElem)));
			(*newElem)++;
		}
	}
	vetSec = (int*)realloc(vetSec, *newElem * sizeof(int));
	free(lunghezza);
	free(i);
	free(mult);
	free(vetInt);
	free(newElem);
}

void visualizzaMenu(char* scelta){
	printf("a. Svolgi esercizio 1\n");
	printf("b. Svolgi esercizio 2\n");
	printf("c. Svolgi esercizio 3\n");
	printf("\nq. Termina\n");
	scanf("%c", scelta);
}