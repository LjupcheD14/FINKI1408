#include<stdio.h>
// #include<conio.h>
#include<math.h>

int main() {
    
   int sekunda;
   int sekunda1;
   int minuta;
   int cas;
   
//   clrscr();
   scanf("%d", &sekunda);
   
   cas = sekunda/3600;
   minuta = (sekunda-cas*3600)/60;
   sekunda1 = sekunda-cas*3600-minuta*60;
   
   printf("%d sekundi se %d casovi, %d minuti i %d sekundi", sekunda, cas, minuta, sekunda1);
    
    return 0;
}
