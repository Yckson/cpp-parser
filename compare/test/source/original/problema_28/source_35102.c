#include<stdio.h>
int main()
{
    int n,i,j,a,b,arr[101],cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    i=1;
    while(arr[i]==0)
    {
        i++;
    }
    a=i;
    i=n;
    while(arr[i]==0)
    {
        i--;
    }
    b=i;
    j=a;
    while(j<=b)
    {
        if(arr[j]==1 || (arr[j]==0 && arr[j-1]==1 && arr[j+1]==1))
        {
            cnt++;
        }
        j++;

    }
    printf("%d",cnt);
    return 0;
}