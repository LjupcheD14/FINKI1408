#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    
    scanf("%d %d", &a, &b);

    c = a + b;
    printf("a + b = %d \n", c);
    
    c = a - b;
    printf("a - b = %d \n", c);
    
    c = a * b;
    printf("a * b = %d \n", c);
    
    c = a / b;
    printf("a / b = %d \n", c);
    
    c = a % b;
    printf("a %% b = %d \n", c);

    

    return 0;
}
