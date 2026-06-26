#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

int main()
{
    int n,a[10010],cnt,num,biaos,i;
    bool via[10010];
    while(~scanf("%d",&n))
    {
        num=cnt=0;
        biaos=1;
        memset(via,0,sizeof(via));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(cnt>=a[i]&&via[i]==0)
            {
                cnt++;
                via[i]=1;
            }
        }
        while(1)
        {
            if(cnt==n)
                break;
            else
            {
                num++;
                biaos=-biaos;
            }
            if(biaos==1)
            {
                for(i=1; i<=n; i++)
                {
                    if(cnt>=a[i]&&via[i]==0)
                    {
                        cnt++;
                        via[i]=1;
                        if(cnt==n)
                            break;
                    }
                }
            }
            if(biaos==-1)
            {
                for(i=n; i>=1; i--)
                {
                    if(cnt>=a[i]&&via[i]==0)
                    {
                        cnt++;
                        via[i]=1;
                        if(cnt==n)
                            break;
                    }
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}