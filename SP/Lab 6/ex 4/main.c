
#include<stdio.h>

int main()
{
    int i,j,n,d1=0,d2=0,a[100][100],dif1,dif2,sum1,sum2=0;
    //printf("Enter size of square matrix:");
    scanf("%d",&n);
    //printf("Enter Elements of matrix:\n");
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
        {
            scanf("%d",&a[i][j]);
            if(i==j)
                d1+=a[i][j];
            if((i+j)==(n-1))
                d2+=a[i][j];
        }
    //printf("\nFirst Diagonal Sum=%d",d1);
    //printf("\nSecond Diagonal Sum=%d",d2);

    dif1=d1-d2;
    printf("%d \n", dif1);

    for(i=0;i<n;++i){
                sum1=0;
        for(j=0; j<n; j++){
            sum1 = sum1 + a[j][0];
        }
    }

    for(i=0;i<n;++i){
                sum2=0;
        for(j=0; j<n; j++){
            sum2 = sum2 + a[j][i];
        }
    }

    //printf("%d \n", sum1);
    //printf("%d ", sum2);

    dif2 = sum1-sum2;

    printf("%d", dif2);


    return 0;
}
