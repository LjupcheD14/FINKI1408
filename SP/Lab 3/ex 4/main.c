#include <stdio.h>
#include <stdlib.h>

int main()
{

    long int mbroj;
    int den=1,mesec=1,godina=1;
    scanf("%ld",&mbroj);
    den = mbroj / 100000;
    mesec = (mbroj / 1000) % 100;
    godina = mbroj % 1000;
    int godina_1 = godina + 1000;

    int rezultat = den * 100 + mesec * 1000 + godina_1;

    //printf("%d\n", den);
    //printf("%d\n", mesec);
    //printf("%d\n", godina_1);


    //printf("%d\n", rezultat);

    if(rezultat > 10000){
        printf("%d", rezultat);
    }
      else if(rezultat < 10000 && godina_1 < 1960){
        printf("7%d", rezultat);
    } else if(rezultat < 10000 && godina_1 >= 1961 && godina_1 <= 1980){
        printf("8%d", rezultat);
    } else if(rezultat < 10000 && godina_1 >= 1981 && godina_1 <= 1999){
        printf("9%d", rezultat);
    } else {
        printf("%d", rezultat);
    }







    //den = mbroj/100;
    //godina = mbroj%1000;


    return 0;
}
