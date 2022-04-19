#include <stdio.h>
#include <stdlib.h>

int main()
{
    int poeni, mod, cifra = 0, ocena, posledna_cifra;
    scanf("%d", &poeni);
    posledna_cifra = poeni % 10;
    if(poeni >= 0 && poeni <= 100){
        if(poeni%10 == 0) {
            mod = 0;
        } else {
            mod = 1;
        }
        while(poeni){
            cifra = poeni % 10;
            poeni /= 10;
        }
        if(cifra >= 5){
            ocena = cifra + mod;
        } else {
            ocena = 5;
        }
    } else if(ocena == 10){
        ocena = 10;
    } else {
         printf("Nevalidna vrednost za poeni!");
         return 0;
    }

    printf("Ocenka %d",ocena);

    if(ocena > 5){
        switch(posledna_cifra) {
        case 1: case 2: case 3: printf("-"); break;
        case 9: case 8: case 0: printf("+"); break;
        }
    }


    return 0;
}
