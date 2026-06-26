#include<stdio.h>
int main()
{
int n,i,j=-1,s=0,y=0;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
if(a[i]==0&&j==-1)
{
j=i+1;
a[i]=-1;
s++;
}
}
while(s<n)
{
for(i=j;i<n;i++)
{
if(a[i]!=-1&&s>=a[i])
{
a[i]=-1;
s++;
if(s==n)
break;
}
}
if(s==n)
break;
y++;
for(i=n-1;i>=0;i--)
{
if(a[i]!=-1&&s>=a[i])
{
a[i]=-1;
s++;
if(s==n)
break;
}
}
if(s==n)
break;
y++;
j=0;
}
printf("%d",y);
}