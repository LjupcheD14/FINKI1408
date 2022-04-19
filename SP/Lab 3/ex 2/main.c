#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    float a, b, c, resenie_1, resenie_2;
    scanf("%f %f %f", &a, &b, &c);
    resenie_1 = (pow((int)b,2)-(4*a*c));

    if(resenie_1 != 0){
        if(resenie_1 > 0){
            printf("Reshenija na ravenkata se: %.02f i %.02f\n",
                   (-b - sqrt(resenie_1)) / (2* a), (-b + sqrt(resenie_1)) / (2* a));
        }
        else {
            printf("Ravenkata nema realni reshenija");
        }
    } else{
         printf("Dvojno reshenie na ravenkata e: %.02f", -b / 2*a);
    }

    return 0;
}
