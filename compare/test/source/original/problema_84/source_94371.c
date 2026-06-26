#include<stdio.h>
#include<math.h>
int main(){
int t,n,a[1000],i,j,p=0;
scanf("%d %d",&t,&n);
for(i=0;i<t;i++)
{
for(j=0;j<2*n;j++)
{
scanf("%d",&a[j]);
}
for(j=0;j<2*n;j=j+2)
{
if(a[j]|a[j+1])
p++;
else
continue;
}
}
printf("%d",p);
return 0;

}