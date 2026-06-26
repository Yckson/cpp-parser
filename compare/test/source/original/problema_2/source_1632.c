#include<stdio.h>
main()
{
    int a,b,m,n;
    scanf("%d %d",&a,&b);
    m=(a>b)?b:a;
    n=(a>b)?((a-b)/2):((b-a)/2);
    if(a==b){
        m=a;
        n=0;
    }
    printf("%d %d",m,n);
}