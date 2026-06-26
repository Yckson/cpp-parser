#include<stdio.h>
int main()
{
    int a,b,d,x,y;
    int c=0;
    scanf("%d %d",&a,&b);
    while(a!=0 && b!=0)
    {
        a=a-1;
        b=b-1;
        c=c+1;
        x=a;
        y=b;
    }
    printf("%d",c);
    printf(" ");
    if(x==0)
    {
        d=y/2;
        printf("%d",d);
    }
    else if(y==0)
    {
        d=x/2;
        printf("%d",d);
    }
    else
    {
        printf("0");
    }
    return 0;
}