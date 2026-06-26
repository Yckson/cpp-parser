#include<stdio.h>
main()
{
    int i,j,k,l,a,b;
    scanf("%d%d",&a,&b);
    if(a>=b)
        printf("%d",b);
    else
        printf("%d",a);
    if(a>=b)
    {
        i=a-b;
        j=i%2;
        k=i-j;
        l=k/2;
        printf(" %d",l);
    }
    else
    {
        i=b-a;
        j=i%2;
        k=i-j;
        l=k/2;
        printf(" %d",l);
    }
}