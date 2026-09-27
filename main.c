#include <stdio.h>

int main(){
    //Cercare l'elemento di un array e stampare la posizione
    int n;
    printf("Inserisci lunghezza array: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        printf("Inserisci numero: ");
        scanf("%d", &array[i]);
    }
    int x;
    printf("inserisci numero da cercare: ");
    scanf("%d", &x);
    int i = 0;
    while(i < n && array[i] != x){
        i++;
    }
    if(i == n){
        printf("Valore non trovato");
    }
    else{
        printf("Valore %d trovato in posizione %d", x, i);
    }
    return 0;
}