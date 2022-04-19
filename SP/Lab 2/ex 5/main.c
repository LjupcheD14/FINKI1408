#include <stdio.h>

int main() {
    // Write C code here
    

    
    int indeks,dve_cifri;
    int ocenka_1,ocenka_2,ocenka_3,ocenka_4,ocenka_5,ocenka_6;
    double prosek=0;
    int zbir=0;
    scanf("%d", &indeks);
    scanf("%d", &ocenka_1);
    scanf("%d", &ocenka_2);
    scanf("%d", &ocenka_3);
    scanf("%d", &ocenka_4);
    scanf("%d", &ocenka_5);
    scanf("%d", &ocenka_6);
    
    
    zbir = (ocenka_1+ocenka_2+ocenka_3+ocenka_4+ocenka_5+ocenka_6);
    prosek = zbir/6.00;
    dve_cifri = indeks/10000;

    
    printf("Prosek: %0.3f \n", prosek);
    printf("Student: %d \n", indeks);
    
    if(dve_cifri == 17){
        printf("3 godina \n");
    } else if(dve_cifri == 16){
        printf("4 godina \n");
    } else if(dve_cifri == 15) {
        printf("5 godina \n");
    } 
    else if(dve_cifri == 14) {
        printf("6 godina \n");
    }
    else if(dve_cifri == 13) {
        printf("7 godina \n");
    }
    else if(dve_cifri == 18) {
        printf("2 godina \n");
    }
    else if(dve_cifri == 19) {
        printf("1 godina \n");
    }
    else {
        printf("Vnesi drug indeks \n");
    }
    
    if(prosek >= 9.5){
        printf("Nagraden: 1 \n");
    } else {
        printf("Nagraden: 0 \n");
    }
  
    
    
    
    return 0;
}
