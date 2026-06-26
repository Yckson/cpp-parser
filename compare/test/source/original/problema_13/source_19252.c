#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int a[1111];
bool b[1111];

int main()
{
    int i,js,j,k,n,m,ans,num;
    while(~scanf("%d",&n))
    {
        memset(b,0,sizeof(b));
        num=0;
        js=0;
        ans=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(j=0;; j++)
        {
            for(i=0; i<n; i++)
            {
                if(a[i]<=js&&b[i]==0)
                {
                    b[i]=1;
                    num++;
                    js++;
                }
            }
            if(num>=n)
            {
                break;
            }
            ans++;
            for(i=n-1; i>=0; i--)
            {
                if(a[i]<=js&&b[i]==0)
                {
                    b[i]=1;
                    num++;
                    js++;
                }
            }
            if(num>=n)
            {
                break;
            }
            ans++;
        }
        printf("%d\n",ans);
    }
    return  0;
}