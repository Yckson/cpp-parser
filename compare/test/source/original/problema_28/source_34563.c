#include<stdio.h>
main()
{
    int n,i,res=0;
    scanf("%d",&n);
    int s[n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    int flag=0;
    for(i=1;i<=n;i++)
    {
        if(s[i]==1 && flag==0)
        {
            flag=1;
            res++;
        }
        else if(flag==1 && i!=n)
        {
            if(s[i]==1)
                res++;
            else if(s[i+1]==1)
            {
                if(s[i-1]==1)
                    res++;
            }
        }
        else if(flag==1 && i==n)
        {
            if(s[i]==1)
                res++;
        }
    }
    printf("%d",res);

}