#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//void clearString(char *str) {
//    if (str[strlen(str) - 1] == '\n') {
//        str[strlen(str) - 1] = '\0';
//    }
//}




int main() {
//    FILE *f = fopen("test.txt", "r");
//    fclose(f);

    int n;
    scanf("%d", &n);
    int A[n * 2][n * 2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            if (j > n - 1) {
                scanf("%d", &A[i + n][j - n]);
            } else {
                scanf("%d", &A[i][j]);
            }
        }
    }

    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}

