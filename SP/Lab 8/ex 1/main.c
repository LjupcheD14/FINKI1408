#include <stdio.h>
#include <stdlib.h>

int checker(int n){
    if(n==0){
        return 1;
    }
    if(n>10){
        if((n/10)%10 <= n%10){
            return 0;
        }
    }
    checker(n/10);
}

int main()
{

    int m,n;
    scanf("%d", &m);
    while(m){
        scanf("%d", &n);
        printf("%d\n", checker(n));
        m--;
    }

    return 0;
}
