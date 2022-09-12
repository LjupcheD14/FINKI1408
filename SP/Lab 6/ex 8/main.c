#include <stdio.h>
#include <stdlib.h>

int main()
{
 int array[100],i,n;

 scanf("%d", &n);
 for(i=0;i<n;i++){
    scanf("%d", &array[i]);
    if(array[i]%2==0){
        array[i]+=1;
    } else {
        array[i]-=1;
    }
 }

 for(i=0;i<n;i++){
    printf("%d ", array[i]);
 }


 return 0;
}
