#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int maxdigit(int broj, int maxbroj) {
    if (broj != 0) {
        if (broj % 10 > maxbroj) {
            maxbroj = broj % 10;
            broj = broj / 10;
            return maxdigit(broj, maxbroj);
        } else {
            broj = broj / 10;
            return maxdigit(broj, maxbroj);
        }
    }
    return maxbroj;
}


int main() {

    int n;
    while (scanf("%d", &n) == 1) {
        int result = maxdigit(n, '\0');
        printf("%d \n", result);
    }


    return 0;
}


