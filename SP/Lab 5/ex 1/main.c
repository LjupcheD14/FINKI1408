#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c,d=0,n,min=0;
    scanf("%d \n", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d \n", &a, &b, &c);
        d = fabs(a-b) + fabs(b-c);
        if(min==0){
            min=d;
        } else if(d<min){
            min=d;
        }
    }
        printf("%d", min);
        return 0;
}
