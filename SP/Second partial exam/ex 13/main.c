#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main() {

//    FILE *f = fopen("test.txt", "r");
//    fclose(f);


    int i, j, m, n, sum = 0, x, matrix[100][100], Arr[m];
    scanf("%d \n", &x);
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];
        }
        Arr[i] = sum>x?1:(sum<x?-1:0);
//        printf("%d \n", sum);
//        printf("X: %d \n", x);


    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", Arr[i]);
        }
        printf("\n");
    }


    return 0;
}
