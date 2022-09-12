#include <stdio.h>
#include <ctype.h>
void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
   
    wtf(); 
    FILE *read = fopen("input.txt", "r");
    
    int counter = 0, Array[1024];
    while (!feof(read)) {
        char ct = fgetc(read);
        if (isdigit(ct)) {
            Array[counter] = ct - '0';
            counter++;
        }
        if (ct == '\n') {
            printf("%d:", counter);
            int temp;
            for (int i = 0; i < counter; i++) {
                for (int j = i + 1; j < counter; j++) {
                    if(Array[i] > Array[j]){
                        temp = Array[i];
                        Array[i] = Array[j];
                        Array[j] = temp;
                    }
                }
            }
            for(int i=0; i<counter; i++){
                printf("%d", Array[i]);
            }
            counter = 0;
            printf("\n");
        }
    }
    return 0;
}
