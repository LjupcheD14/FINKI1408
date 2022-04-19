#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int dolzina(int broj){
    int dl = 0;
    while(broj)
    {
        dl++;
        broj/=10;
    }
    return dl;
}

int main()
{

    int broj, dolzina_broj, obraten_broj = 0, privremen_broj;
    scanf("%d", &broj);
    privremen_broj = broj;
    dolzina_broj = dolzina(broj);


    obraten_broj=0;
    while(broj!=0){
    obraten_broj=obraten_broj*10+broj%10;
    broj=broj/10;
    }

    if(dolzina_broj == 5){

    if(privremen_broj != obraten_broj){
        printf("Ne e palindrom");
    } else if(privremen_broj == obraten_broj) {
        printf("Palindrom");
    }

    } else {
        printf("Nevaliden vlez");
    }

    return 0;
}
