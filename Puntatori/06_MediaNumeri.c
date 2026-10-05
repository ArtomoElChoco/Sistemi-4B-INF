#include <stdio.h>
#include <stdlib.h>

//Dati 3 numeri in input. Stampare in output la media

int main(void){
	int* n1 = (int*) malloc(sizeof(int));
	int* n2 = (int*) malloc(sizeof(int));
	int* n3 = (int*) malloc(sizeof(int));
	printf("\nInserisci numero: ");
	scanf("%d", n1);
	printf("\nInserisci numero: ");
	scanf("%d", n2);
	printf("\nInserisci numero: ");
	scanf("%d", n3);
	float* media = (float*) malloc(sizeof(float));
	*media = (*n1+*n2+*n3)/3;
	printf("\n\nMedia dei valori: %.2f", *media);
	
	
	return 0;
}