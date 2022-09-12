#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void writeToFile() {
    FILE *f = fopen("C:\\Users\\ljupc\\CLionProjects\\untitled\\cmake-build-debug\\test.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    writeToFile();

    // vasiot kod ovde
    char character;
    FILE *read = fopen("C:\\Users\\ljupc\\CLionProjects\\untitled\\cmake-build-debug\\test.txt", "r");
    int cnt_upper=0, cnt_lower=0, cnt_total=0;

    while(!feof(read)) {
        character = fgetc(read);

        if (isalpha(character)) {
            cnt_total++;
            isupper(character) ? cnt_upper++ : cnt_lower++;
        }
    }
    printf("%.4lf\n%.4lf", cnt_upper/(float)cnt_total, cnt_lower/(float)cnt_total);

    fclose(read);
    return 0;
}
