#include<stdio.h>
int main()
{
int n,i,p,s=0,m=-1;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
if(a[i]==1&&m==-1)
{
m=i;
s++;
}
}
for(i=m+1;i<n;i++)
{
if(a[i]==1)
s++;
else
{
p=i;
while(i<n&&a[i]==0)
i++;
if(i<n&&a[i]==1)
{
if((i-p)==1)
s=s+2;
else if((i-p)>1)
s++;
}
}
}
printf("%d",s);
}