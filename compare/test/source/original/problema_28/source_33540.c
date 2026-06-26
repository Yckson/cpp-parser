#include<stdio.h>
int main()
{
    int n,a[100],c=0,j,i,k=0,t;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0; j<n; j++)
    {
        if(a[j]==0)
            continue;
        else
        {
            k=j;
            break;
        }
    }
    for(t=k; t<n; t++)
    {
        if(a[t]==0&&a[t+1]==0)
            continue;
        if(a[t-1]==0&&a[t]==0)
            continue;
        if(a[t]==1)
            c++;
        if(t==n-1){
            if(a[t]==0)
                break;
        }
        if(a[t]==0)
            c++;
    }
    printf("%d",c);
    return 0;
}