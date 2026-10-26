#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visualizzaMenu(char* scelta);
void caricaMultipli(int* vetInt, int* lunghezza, int* mult);
int contaVocali(char* frase);
void gnomeSort(char* v, int* n);

int main(void){
	srand(time(NULL));
	int* lunghezza;
	char* input = (char*)malloc(sizeof(char));
	do{
		// system("@cls||clear");
		fflush(stdin);
		visualizzaMenu(input);
		switch(*input){
			case 'a':
				lunghezza = (int*)malloc(sizeof(int));
				do{
					printf("\nInserisci lunghezza del vettore: ");
					scanf("%d", lunghezza);
				}while(*lunghezza < 1);
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
				getchar();
				break;
			case 'b':
				lunghezza = (int*)malloc(sizeof(int));
				do{
					printf("\nInserisci lunghezza del vettore: ");
					scanf("%d", lunghezza);
				}while(*lunghezza < 1);
				char* stringa = (char*)malloc(sizeof(char) * (*lunghezza));
				i = (int*)calloc(1, sizeof(int));
				for(; *i < *lunghezza; (*i)++){
					*(stringa + (*i)) = (rand() % ('z' - 'a' + 1)) + 'a';
					printf("%c", *(stringa + (*i)));
				}
				gnomeSort(stringa, lunghezza);
				printf("\n\n");
				for(*i = 0; *i < *lunghezza; (*i)++){
					printf("%c", *(stringa + (*i)));
				}
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
				frase = (char*)realloc(frase, sizeof(char) * (*newElem + 1));
				*(frase + (*newElem)) = '\0';
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
		if(*start % 2 == 0 && (*(frase + (*i)) == 'a' || *(frase + (*i)) == 'e' || *(frase + (*i)) == 'i' ||
		*(frase + (*i)) == 'o' || *(frase + (*i)) == 'u')){
			(*cont)++;
		}
		(*i)++;
	}
	printf("\nIl totale delle vocali presenti nella sotto stringa è: %d", *cont);
}

void caricaMultipli(int* vetInt, int* lunghezza, int* mult){
	int* vetSec = (int*)calloc(*lunghezza, sizeof(int));
	int* newElem = (int*)calloc(1, sizeof(int));
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
	free(vetSec);
	free(newElem);
}

void visualizzaMenu(char* scelta){
	printf("a. Svolgi esercizio 1\n");
	printf("b. Svolgi esercizio 2\n");
	printf("c. Svolgi esercizio 3\n");
	printf("\nq. Termina\n");
	scanf("%c", scelta);
}

void gnomeSort(char* v, int* n)
{
	int* index = (int*)calloc(1, sizeof(int));
	char* tmp = (char*)malloc(sizeof(char));
	while (*index < *n) {
		if (*index == 0) {
			(*index)++;
		}
		if (*(v + (*index)) >= *(v + (*index - 1))) {
			(*index)++;
		} else {
			*tmp = *(v + (*index));
			*(v + (*index)) = *(v + (*index - 1));
			*(v + (*index - 1)) = *tmp;
			(*index)-- ;
		}
	}
}