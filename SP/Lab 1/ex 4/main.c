#include <stdio.h>

int main()
{
    int suma,oceni;
    suma = 0;
    float prosek;
    prosek = 0;

    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &oceni);
        suma = suma + oceni;
        prosek = suma / 5.00;

    }
    printf("%.2f", prosek);

    return 0;
}
