#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
main()
{
int n;
long long money=0;
int a,b;
int min=101,kg=0;
scanf("%d",&n);
while(n--)
{
scanf("%d%d",&a,&b);
if(min>b)
{
money+=min*kg;
kg=0;
min=b;
}
kg+=a;
}
money+=kg*min;
printf("%I64d",money);
}