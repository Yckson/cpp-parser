#include <stdio.h>

int main()
{
    int ara[101]={0};
    int n,i,count1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&ara[i]);
    i=0;
    if(ara[i]==1)
        count1++;
    for(i=1;i<n-1;i++)
    {
        if(ara[i]==1)
            count1++;
        else if(ara[i]==0)
        {
            if(ara[i-1]==1 && ara[i+1]==1)
                count1++;
        }
        else continue;
    }
    if(ara[i]==1)
        count1++;
    printf("%d\n",count1);
    return 0;
}