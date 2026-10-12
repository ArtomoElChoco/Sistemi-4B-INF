#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void visualizzaMenu();
int verificaPalindroma(char* str);
char concatenaStringhe(char* str, char* str2);

int main(void){
	int* scelta;
	char* str;
	char* str2;
	scelta = (int*) malloc(sizeof(int));
	
	do{
		visualizzaMenu();
		printf("Scelta -> ");
		scanf("%d", scelta);
		
		system("@cls||clear");
		fflush(stdin);
		switch(*scelta){
			case 1:
				/* Data in input una stringa, verificare se è PALINDROMA */
				str = (char*) malloc(sizeof(char)*MAX);
				printf("Inserisci string -> ");
				gets(str);
				str = realloc(str, (strlen(str)) * sizeof(char) + 1);
				// printf("String inserita -> %s\n", str);
				// printf("Dimensione -> %d\n", strlen(str));
				if(verificaPalindroma(str) == 1)
					printf("La string %s e' Palindroma", str);
				else
					printf("La string %s non e' Palindroma", str);
				free(str);
				break;
			case 2:
				break;
			case 6:
				/*Date due stringhe in input, concatenarle e stampare il risultato*/
				str = (char*) malloc(sizeof(char)*MAX);
				str2 = (char*) malloc(sizeof(char)*MAX);
				if(str1 != NULL && str2 != NULL){
					printf("Stringa 1 -> ");
					gets(str);
					printf("Stringa 2 -> ");
					gets(str2);
					str1 = realloc(str1, sizeof(char) * (strlen(str) + 1));
					str2 = realloc(str2, sizeof(char) * (strlen(str) + 1));
					printf("Le stringhe %s e %s insieme sono -> %s", str1, str2, concatenaStringhe(str1, str2));
				}
				break;
			case 0:
				printf("Arrivederci...\n");
				break;
			default:
				printf("Opzione non disponibile\n");
				break;
		}
		
	}while(*scelta != 0);
	free(scelta);
	
	
	
	return 0;
}

void visualizzaMenu(){
	printf("\nESERCITAZIONE - PUNTATORI\n");
	printf("1. Verifica se una string e' palindroma\n");
	printf("2. Inverti una stringa\n");
	printf("3. Conta vocali e consonanti di una stringa\n");
	printf("4. Cerca un valore in un vettore\n");
	printf("5. Calcola minimo, massimo e media di un vettore\n");
	printf("6. Concatena due stringhe\n");
	printf("0. Esci\n");
}

char concatenaStringhe(char* str, char* str2){
	str = realloc(str, sizeof(char) * (strlen(str) + strlen(str2) + 1));
	char* inizio = str + strlen(str1);
	*inizio = *str2;
}

int verificaPalindroma(char* str){
	char* inizio;
	char* fine;
	inizio = str;
	fine = inizio + (strlen(str) - 1);
	while(fine > inizio && *inizio.tolower == *fine.tolower){
		inizio++;
		fine--;
	}
	return *fine == *inizio ? 1 : 0;
}