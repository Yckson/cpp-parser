#include<stdio.h>

int main()
{
    int fl , fla,w1,w2,ctr1,ctr2,sum1=0,sum2=0;
    scanf("%d %d",&fl,&fla);
    sum1=fl*fla;
    for(ctr1=0;ctr1<fl;ctr1++)
    {
        for(ctr2=0;ctr2<fla;ctr2++)
        {
            scanf("%d %d",&w1,&w2);
         //   printf("%d %d",w1,w2);
          if(w1==0&&w2==0)
        {
            sum2++;
        }
        }

    }

    printf("%d",sum1-sum2);
}