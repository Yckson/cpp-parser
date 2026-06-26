#include <stdio.h>

int main()
{
    int n, i, count=0, var=0;
    scanf("%d",&n);
    int a[100];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    i=0;
    while(i<n)
    {
        if(a[i]==1) count++, var++;
        else if(a[i]==0 && a[i+1]!=0 && var!=0 && i+1<n && a[i-1]!=0 && i-1>=0) count++;
        i++;
    }
    printf("%d\n",count);
    return 0;
}