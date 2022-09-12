#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[1000];
    int i,j,a,n;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &array[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(array[i]>array[j]){
                a=array[i];
                array[i]=array[j];
                array[j]=a;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ", array[i]);
    }
    return 0;
}
