#include <stdio.h>
#include <math.h>
 
int main()
{
 int x;
 int y;
 int z;
 int  rezultat1, rezultat2;
 scanf("%d %d %d", &x, &y, &z);

 
 rezultat1 = ++x - --y + z++ + (x>z);
 rezultat2 = ++x - --y + z++ + x>z;
 
 printf("%d ", rezultat1);
//  printf("%d ", x);
 printf("%d ",  rezultat2);
 
 
//  z = z-- || (x>y) && (x>z);
 
//  printf("\n %d ", x);
//  printf("%d ", y);
//  printf("%d ", z);
 
 
  	return 0;
}
