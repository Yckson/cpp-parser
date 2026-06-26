#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
    int a[100010],n,i,j,d,D;
    bool b[100010];
    while(~scanf("%d",&n))
    {
        d=0;
        D=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(b,0,sizeof(b));
        i=1;
        while(1)
        {
            for(;i<=n;i++)
            {
                if(a[i]<=d&&b[i]==0)
                {
                    b[i]=1;
                    d++;
                    j=i;
                }
            }
            if(d==n)
                break;
            else
            {
                D++;
                i=j;
                for(;i>0;i--)
                {
                    if(a[i]<=d&&b[i]==0)
                    {
                        b[i]=1;
                        d++;
                        j=i;
                    }
                }
            }
            if(d==n)
                break;
            else
            {
                D++;
                i=j;
            }
        }
        printf("%d\n",D);

    }
    return 0;
}