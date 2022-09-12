#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile() {
  FILE *f = fopen("text.txt", "w");
  char c;
  while((c = getchar()) != '#') {
    fputc(c, f);
  }
  fclose(f);
}

int main() {
    
  writeToFile();
    FILE *f = fopen("text.txt", "r");
    char c, prev = ' ';
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int i = 0, cnt = 0;

    //FILE *f = fopen("C:\\Users\\ljupc\\CLionProjects\\untitled\\cmake-build-debug\\test.txt", "r");

    while (!feof(f)) {
        c = tolower(fgetc(f));
        int flag1 = 0, flag2 = 0;

        for (int k = 0; k < sizeof(vowels) / sizeof(char); k++) {
            if (c == vowels[k]) {
                flag1 = 1;
            }
            if (prev == vowels[k]) {
                flag2 = 1;
            }
        }
        if(flag1 && flag2 == 1){
            printf("%c%c \n", prev, c);
            cnt++;
        }
        prev = c;
    }

    printf("%d", cnt);

    fclose(f);
    


  return 0;
}
