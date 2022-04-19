#include <stdio.h>
#include <math.h>
 
int main()
{
    
    int br_km;
    int C,K,P;
    int V,B,M,D;
    int company_1, company_2;
    
    scanf("%d\n", &br_km);
    scanf("%d %d %d\n", &C, &K, &P);
    scanf("%d %d %d %d\n", &V, &B, &M, &D);
    
    company_1 = C + (br_km - K) * P;
    company_2 = B + (br_km / V) * M + br_km * D;
    
    printf("%d %d \n", company_1, company_2);

    
    if(company_1 <= company_2) {
        printf("1");
    } else {
        printf("0");
    }
 
 
  	return 0;
}
