#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n1,n2,i=1;
    scanf("%d %d", &n1, &n2);
    if(n1<=0 || n2<=0){
        printf("Invalid input");
        return 0;
    }
    int temp;
    if(n2>n1){
        temp=n1;
        n1=n2;
        n2=temp;
    }
    while(n2){
        if(i%2==0){
            if(n1%10 != n2%10){
                printf("NE");
                return 0;
            }
            n2/=10;
        }
        n1/=10;
        i++;
    }
    printf("PAREN");

    return 0;
}
