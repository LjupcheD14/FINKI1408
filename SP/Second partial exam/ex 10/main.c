#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


void wf() {
    FILE *f = fopen("test.txt", "w");
    char c;
    while ((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {


    int z1 = 1, z2 = 0;
    wf();
    FILE *read = fopen("test.txt", "r");
//    FILE *f = fopen("test.txt", "r");

    scanf("%*c");
    char string[1024];
    scanf("%[^\n]", string);
    char comp1 = *(string + 0), comp2 = *(string + 1);

    while (!feof(read)) {
        char character = fgetc(read);
        if (character == comp2) {
            z2 = 1;
        }
        if(z1 == 0 && z2 == 0){
            printf("%c", character);
        }
        if(character == comp1){
            z1=0;
        }
        if(character == '\n'){
            z1 = 1;
            z2 = 0;
            printf("\n");
        }
    }

//    fclose(f);

    return 0;
}
