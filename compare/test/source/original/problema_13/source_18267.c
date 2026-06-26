#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int ara[n],i;
    for(i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }

    int info=0,count=0,c=0,p=0;
    while(1)
    {
        if(c==0)
        {
            p=0;
            for(i=0; i<n; i++)
            {
                if(ara[i]<=info)
                {
                    ara[i]=2000;
                    info++;
                    p=1;
                }
            }
            if(p==1)
            {
                count++;
            }

            c=1;
        }
        else if(c==1)
        {
            p=0;
            for(i=n-1; i>=0; i--)
            {
                if(ara[i]<=info)
                {
                    ara[i]=2000;
                    info++;
                    p=1;
                }
            }
            if(p==1)
            {
                count++;
            }

            c=0;
        }

        if(info==n)
        {
            break;
        }
    }

    printf("%d",count-1);

    return 0;
}