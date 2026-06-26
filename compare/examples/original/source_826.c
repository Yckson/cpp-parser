#include<stdio.h>
int main()
{
    int r,b,s=0,d=0;
    scanf("%d %d",&r,&b);
    if(r<b)
    {
     d=r;
     s=b-r;
    }
    else
    {
        d=b;
        s=r-b;
    }
    s=s/2;
    printf("%d %d",d,s);
}