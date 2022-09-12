#include <stdio.h>
#include <stdlib.h>

void elka(int n){
    int space=n/2;
    int star=1;

    for(int i=0; i<=n/2; i++){
        int tmp_space=space;
        while(tmp_space){
            printf(" ");
            tmp_space--;
        }

        int tmp_star=star;
        while(tmp_star){
            printf("*");
            tmp_star--;
        }
        printf("\n");
        space--;
        star+=2;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    elka(n);

    return 0;
}
