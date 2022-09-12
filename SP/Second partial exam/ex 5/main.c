#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void wf() {
    FILE *f = fopen("livce.txt", "w");
    char c;
    while ((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {

    wf();
    FILE *read = fopen("livce.txt", "r");
    int money, type;
    fscanf(read, "%d", &money);
    double mult, max_mult, max = 0, sum = 1;
    char code[1024], save[1024];
    
    while (fscanf(read, "%s %d %lf", code, &type, &mult) == 3) {
        sum *= mult;
        if (sum > max) {
            max = sum;
            
        }
        if(mult > max_mult){
            max_mult = mult;
            sprintf(save, "%s %d %.2lf", code, type, max_mult);
        }
    }
        
        
    // sprintf(save, "%s %d %.2lf", code, type, max_mult);
    
    printf("%s\n%.2lf", save, money * sum);

    //printf("%s %d %.2lf\n%.2lf", code, type, max_mult, money * sum);

    return 0;
}
