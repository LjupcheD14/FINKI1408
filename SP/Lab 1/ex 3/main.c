#include <stdio.h>

int main ()
{
    float visina, metar, kilazha, bmi;
    scanf("%f", &kilazha);
    scanf("%f", &visina);
    metar = visina / 100;
    bmi = kilazha / (metar * metar);
    printf("%.2f", bmi);

    return 0;
}
