#include <stdio.h>
#include <stdlib.h>

int main()
{
    int den,mesec,godina;
    scanf("%d %d %d", &den, &mesec, &godina);

    if(mesec >= 1 && mesec <= 12){

    if((den >= 1 && den <= 31) && (mesec == 1 || mesec == 3 || mesec == 5 || mesec == 7 || mesec == 8 || mesec == 10 || mesec == 12)){
        printf("DA\n");
    }
        else if ((den>=1 && den<=30) && (mesec==4 || mesec==6 || mesec==9 || mesec==11)){
      printf("DA\n");
    }
    else if((den>=1 && den<=28) && (mesec==2)){
      printf("DA\n");
    }
    else if((mesec == 2) && (den == 29) && (godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0))) {
        printf("DA\n");
    } else {
        printf("NE\n");
    }

    } else {
        printf("NE\n");
    }

    return 0;
}
