#include<stdio.h>

int main()
{
    long long n,a,p,i,cost,min_p;
    
    cost=0;
    min_p=1000;

    scanf("%lld",&n);

    while(n--)
    {
        scanf("%lld %lld",&a,&p);

        min_p=(min_p>p)?p:min_p;

        cost+=a*min_p;
    }

    printf("%lld",cost);
    return 0;
}