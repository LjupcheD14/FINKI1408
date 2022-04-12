#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct Product {
    char ime[100];
    float cena;
    float kolicina;
};
typedef struct Product Product;


int main() {


//    Product p;
//    readProduct(&p);
//    printProduct(p);

    Product p[100];
    int n, i;
    float vkupno, total = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %f %f", &p[i].ime, &p[i].cena, &p[i].kolicina);
    }
    for (i = 0; i < n; i++) {
        vkupno = (p[i].cena) * (p[i].kolicina);
        total += vkupno;
        printf("%d. %s\t%.2f x %.1f = %.2f \n", i+1, p[i].ime, p[i].cena, p[i].kolicina, vkupno);
    }
    printf("Total: %.2f", total);

    return 0;
}
