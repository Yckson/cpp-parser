#include<stdio.h>
int main()
{
    int n,m,i=0,count=0,x,a;
    int ara[400];
    scanf("%d %d",&n,&m);
    while(i<2*n*m)
    {
        scanf("%d",&x);
        if(i%2==0&&x==1)
            count++;
        if(i%2==1&&a==0&&x==1)
            count++;
        a=x;
        i++;
    }
    printf("%d\n",count);
    return 0;
}