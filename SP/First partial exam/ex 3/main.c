#include <stdio.h>
#include <stdlib.h>

int main()
{

    int number, max=0, lr_number=0;

    scanf("%d", &number);

    for(int i=number-1; i>0; i--){
        int sum=0;
        for(int j=i; j>0; j--){
            if(i%j==0){
                sum+=j;
            }
        }
        if(sum>max){
            max=sum;
            lr_number=i;
        }
    }

    printf("%d", lr_number);


    return 0;
}
