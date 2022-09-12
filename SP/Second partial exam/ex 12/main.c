#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int BrojPozitivni(int niza[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (niza[i] > 0) {
            cnt++;
        }
    }
//    return 1 + BrojPozitivni(niza + 1, n + 1);
    return cnt;
}

int main() {

    int n;
    int array[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int pozitivni = BrojPozitivni(array, n);

    printf("%d", pozitivni);

    return 0;
}
