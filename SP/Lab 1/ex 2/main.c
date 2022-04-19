#include <stdio.h>
int main ()
{
    int broj;
    scanf("%d",&broj);
    int e,d,p,de,pd,s,ps,i,pi;
    pi=broj/5000;
    i=(broj%5000)/1000;
    ps=(broj%5000)%1000/500;
    s=(broj%5000)%1000%500/100;
    pd=(broj%5000)%1000%500%100/50;
    de=(broj%5000)%1000%500%100%50/10;
    p=(broj%5000)%1000%500%100%50%10/5;
    d=(broj%5000)%1000%500%100%50%10%5/2;
    e=(broj%5000)%1000%500%100%50%10%5%2;
    printf("%d*5000\n",pi);
    printf("%d*1000\n",i);
    printf("%d*500\n",ps);
    printf("%d*100\n",s);
    printf("%d*50\n",pd);
    printf("%d*10\n",de);
    printf("%d*5\n",p);
    printf("%d*2\n",d);
    printf("%d*1\n",e);



    return 0;
}
