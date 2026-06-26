#include <stdio.h>
#include <stdlib.h>

int main()
{
int n=0,a=0,x=0,p=0,ans=0,i=0,min=1000;

scanf("%d",&n);

for(i=1;i<=n;i++){
    scanf("%d%d",&a,&p);
   if(p<min){
    min=p;
   }
   x=a*min;
   ans+=x;
}
printf("%d",ans);


    return 0;
}