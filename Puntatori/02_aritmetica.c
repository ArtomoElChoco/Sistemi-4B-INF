#include <stdio.h>

int main(void){
    
    int v[] = {33, 44, 55};
    int i;

    for(i = 0; i < 4; i++){
        printf("v[%d]: %d\n", i, v[i]);
    }

    return 0;
}