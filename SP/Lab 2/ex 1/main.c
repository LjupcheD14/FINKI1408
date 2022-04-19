#include <stdio.h>

int main() {
    // Write C code here
    int pari,cena,ddv,proizvod,ostanati_pari;
    scanf("%d ", &pari);
    scanf("%d ", &cena);
    ddv = cena * 0.18;
    proizvod = cena + ddv;
    ostanati_pari = pari - proizvod;
    if(ostanati_pari > 0)
    {
        printf("1");
    } else {
        printf("0");
    }

    
    return 0;
}
