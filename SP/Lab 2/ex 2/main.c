#include <stdio.h>
#include <math.h>
 
int main()
{
 int x;
 int y;
 int z;
 
 scanf("%d %d %d", &x, &y, &z);

 
 y = ++x && (z+5 || --y);
 
 printf("%d ", x);
 printf("%d ", y);
 printf("%d ", z);
 
 
 z = z-- || (x>y) && (x>z);
 
 printf("\n%d ", x);
 printf("%d ", y);
 printf("%d ", z);
 
 
 
  	return 0;
}
