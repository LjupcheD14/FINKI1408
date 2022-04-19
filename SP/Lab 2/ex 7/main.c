#include <stdio.h>
int main () {
    int iznos, broevi;
    int iznos_1 = 0;
    scanf("%d", &iznos);
    
    for (int i = 0; i < 5; i ++)
    {
        scanf("%d", &broevi);
        iznos_1 = iznos_1 + broevi; 
    }
    if ((iznos + iznos_1) > 0)
    {
        printf("1");
    } 
    if ((iznos + iznos_1) <= 0)
    {
        printf("0");
    }
    return 0;
}
