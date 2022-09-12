#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int sum_pos(int *array, int n, int index) {
    if(index >= n){
        return 0;
    }
    return *(array + index) + sum_pos(array, n, index + 1);
}

int main() {

    int n, index;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &*(array + i));
    }
    scanf("%d", &index);

    printf("%d", sum_pos(array, n, index));

    return 0;
}
