#include<stdio.h>
int main()
{
    int a,t,s,d,f,c,q;
    while(scanf("%d%d",&t,&s)==2)
    {
        f=0;
        for(c=0;c<t;c++)
        {
            for(q=0;q<s;q++)
            {
                scanf("%d%d",&a,&d);
                if(a||d)
                f++;
            }
        }

     printf("%d\n",f);

    }

    return 0;
}