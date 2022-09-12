#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main() {

    int i, j, n, m, flag = 0, cnt = 0;
    int matrix[100][100];
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < m; j++) {
            flag++;
            if (matrix[i][j] == 0) {
                flag = 0;
            }
            if(flag==3){
                cnt++;
                break;
            }
        }
    }

    for (j = 0; j < m; j++) {
        flag = 0;
        for (i = 0; i < n; i++) {
            flag++;
            if (matrix[i][j] == 0) {
                flag = 0;
            }
            if(flag==3){
                cnt++;
                break;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}
