#include <stdio.h>

int main(void){
    int i;          // 0x005
    char c = 'c';   // 0x00A

    int* pi;
    
    i = 10;
    printf("La variabile i occupa %d byte\n", sizeof(i));
    printf("Il tipo char occupa %d byte\n", sizeof(char));
    printf("Il puntatore pi occupa %d byte\n", sizeof(pi));

    printf("L'indirizzo di i e' %p e contiene %d\n", &i, i);
    printf("L'indirizzo di c e' %p e contiene %c\n", &c, c);
    printf("L'indirizzo di pi e' %p e contiene %p\n", &pi, pi);
    return 0;
}