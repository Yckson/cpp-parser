#include<stdio.h>
main()
{
    int n,i;
    scanf("%d",&n);
    int a[n],p[n];
    int k=0;
    int m=0;
    for(i=0;i<n;i++)
    scanf("%d%d",&a[i],&p[i]);
    m=p[0];
    for(i=0;i<n;i++)
    {
    if(m>p[i])
    m=p[i];
    k=k+(a[i]*m);
    }
    printf("%d",k);
}