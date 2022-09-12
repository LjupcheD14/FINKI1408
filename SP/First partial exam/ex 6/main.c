#include <stdio.h>
#include <stdlib.h>

int sum=0;
double counter=0, counter_2=0;


int main()
{
    int compare,a,b;
    double procent=0.00;
    scanf("%d", &compare);
    scanf("%d", &a);scanf("%d", &b);

    while((a+b) != 0){
        sum += a+b;
        if(compare==sum){
            counter++;
        }
        counter_2++;
        sum=0;
        scanf("%d", &a); scanf("%d", &b);

    }

    procent = counter/counter_2;
    printf("Vnesovte %d parovi od broevi chij zbir e %d \n", (int)counter, compare);
    printf("Procentot na parovi so zbir %d e %.02lf%% \n", compare, procent * 100);

    return 0;
}
