#include<stdio.h>
int main()
{
 int num;
 scanf("%d",&num);
 int square=num*num;
 int arr[num],b[num],i=0;
 for(i=0;i<num;++i)
 {  arr[i]=i+1;
    b[i]=i+1;}
 int hor[square],ver[square];
 for (i=0;i<square;++i)
 {         scanf("%d%d",&hor[i],&ver[i]);}
 int count=0,c[square],x,y;
 for (i=0;i<square;++i)
 { x=hor[i];
   y=ver[i]; 
   if (arr[x-1]!=0 && b[y-1]!=0)
          { arr[x-1]=0;
            b[y-1]=0;
            c[count]=i+1;
            count+=1;}}
 for (i=0;i<count;++i)
   printf("%d ",c[i]);
return 0;}