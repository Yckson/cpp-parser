#include <stdio.h>

int main(void) {
   int n,i,j,mindx;
   scanf("%d",&n);
   int quant[n],cost[n];
   for(i=0;i<n;i++)
   {
    scanf("%d%d",&quant[i],&cost[i]);   
   }
   mindx=0;
   long int sum=quant[0]*cost[0];
   for(i=1;i<n;i++)
   {
        if(cost[i]<cost[i-1]&&cost[i]<cost[mindx])
        {
            sum+=(cost[i]*quant[i]);
            mindx=i;
        }   
        else
        {   
            sum+=(cost[mindx]*quant[i]);    
        
        }
   }
printf("%ld\n",sum);
return 0;
}