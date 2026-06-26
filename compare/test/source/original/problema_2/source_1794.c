#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,day1,day2;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
       day1=0;
       day2=0;
       while(a>0&&b>0)
       {
           a--;
           b--;
           day1++;
       }
       if(a>=1)
       {
           day2=a/2;
       }
       if(b>=1)
       {
           day2=b/2;
       }
    printf("%d %d\n",day1,day2);
    }
    return 0;
}