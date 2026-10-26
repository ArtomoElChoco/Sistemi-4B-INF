#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

void visualizzaMenu();
int verificaPalindroma(char* str);
void concatenaStringhe(char* str1, char* str2);
void invertiStringa(char* inizio);
void generaStringaCasuale(char* str, int* dimStr, char min, char max);
void convertiInMaiuscolo(char* str, int* dimStr);

int main(void)
{
    int* scelta;
    // Ese1
    char* str;
    // Ese2
    char* str1;
    char* str2;
    // Ese7
    int* dimStr; // Dimensione della stringa casuale

    srand(time(NULL));
    scelta = (int*) malloc(sizeof(int));

    do{
        visualizzaMenu();
        printf("Scelta > ");
        scanf("%d", scelta);

        system("@cls||clear");
        fflush(stdin);
        switch(*scelta)
        {
            case 1:
            str = (char*)malloc(sizeof(char) * MAX);
            /* Data in input una stringa, verificare se è PALINDROMA */
            printf("Inserisci stringa > ");
            gets(str);
            // Rialloco per ottimizzare spazio in memoria
            str = realloc(str, sizeof(char) * (strlen(str)) + 1);
            /* printf("Stringa inserita > %s\n", str);
            printf("Dimensione > %d\n", strlen(str)); */
            if(verificaPalindroma(str) == 1)
                printf("La stringa %s e' PALINDROMA\n", str);
            else 
                printf("La stringa %s NON e' PALINDROMA\n", str);
            free(str);
            break;
            case 2: // Inverti una stringa
            str = (char*)malloc(sizeof(char) * MAX);
            /* Data in input una stringa, verificare se è PALINDROMA */
            printf("Inserisci stringa > ");
            gets(str);
            // Rialloco per ottimizzare spazio in memoria
            str = realloc(str, sizeof(char) * (strlen(str)) + 1);
            invertiStringa(str);
            printf("Contenuto della stringa inversa: %s\n", str);
            free(str);
            break;
            case 6:
            /* Date due stringhe in input, concatenarle e stampare il risultato */
            str1 = (char*) malloc(sizeof(char) * MAX);
            str2 = (char*) malloc(sizeof(char) * MAX);
            if(str1 != NULL && str2 != NULL)
            {
                printf("Stringa 1 > ");
                gets(str1);
                printf("Stringa 2 > ");
                gets(str2);

                str1 = realloc(str1, sizeof(char) * (strlen(str1) + strlen(str2)) + 1);
                str2 = realloc(str2, sizeof(char) * (strlen(str2)) + 1);
                concatenaStringhe(str1, str2);
                printf("Stringa concatenata: %s\n", str1);
            }
            free(str1);
            free(str2);
            break;
            case 7:
                dimStr = (int*) malloc(sizeof(int));
                printf("Inserisci dimensione stringa > ");
                scanf("%d", dimStr);
                str = (char*) malloc(sizeof(char) * (*dimStr) + 1);
                
                *(str + *dimStr) = '\0';
                generaStringaCasuale(str, dimStr, 'a', 'z');
                printf("Stringa casuale: %s\n", str);
                convertiInMaiuscolo(str, dimStr);
                printf("Stringa convertita: %s\n", str);

                free(dimStr);
            break;
            case 0: 
                printf("Arrivederci....\n");
            break;
            default:
                printf("Opzione non disponibile\n");
        }
        getchar();
    }while(*scelta != 0);
    free(scelta);

    return 0;
}
void visualizzaMenu(){
    printf("\nESERCITAZIONE - PUNTATORI\n");
    printf("1. Verifica se una stringa e' palindroma\n");
    printf("2. Inverti una stringa\n");
    printf("3. Conta vocali e consonanti di una stringa\n");
    printf("4. Cerca un valore in un vettore\n");
    printf("5. Calcola minimo, massimo e media di un vettore\n");
    printf("6. Concatena due stringhe\n");
    printf("7. Caricare stringa casuale (a-z) e trasformare in maiuscolo il contenuto\n");
    printf("0. Esci\n");
}

int verificaPalindroma(char* str)
{
    // 'A' 'N' 'n' 'a'
    // 'l' 'u' 'c' 'a'
    char* inizio;
    char* fine;
    inizio = str;
    fine = inizio + (strlen(str) - 1);

    while((inizio < fine) && (*inizio == *fine))
    {
        inizio++;
        fine--;
    }
    if(*inizio == *fine)
        return 1;
    return 0;
}

void concatenaStringhe(char* str1, char* str2)
{
    char *inizio = str1 + strlen(str1);

    for(; *str2 != '\0'; str2++, inizio++)
        *inizio = *str2; 

    *inizio = '\0';
}

void invertiStringa(char* inizio)
{
    char* fine = inizio + (strlen(inizio) - 1);
    char* aus = (char*) malloc(sizeof(char));

    while(inizio < fine)
    {
        *aus = *inizio;
        *inizio = *fine;
        *fine = *aus;

        inizio++;
        fine--;
    }
}

void generaStringaCasuale(char* str, int* dimStr, char min, char max)
{
    int* i; 
    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *dimStr; (*i)++)
        *(str + *i) = ((rand() % (max - min + 1)) + min);
}
void convertiInMaiuscolo(char* str, int* dimStr)
{
    int* i; 
    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *dimStr; (*i)++)
    {
        //if(*str >= 'a' && *str <= 'z')
        *(str + *i) = (*(str + *i)) - ('c' - 'C');
    }
}