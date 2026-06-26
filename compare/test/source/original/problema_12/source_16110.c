#include<stdio.h>

int main()
{
     int n=0;
     scanf("%d",&n);
     int s[50][50]={0};
	  int hx,vx;;
     int h[50]={0};
     int v[50]={0};
int i=0,f=0;
     for(i=0;i<n*n;i++)
{
     scanf("%d %d",&hx,&vx);
    // if(h[hx-1]!=1){f=1;h[hx-1]=1;}
    // else if(v[vx-1]!=1){f=1;v[vx-1]=1;}
     if(h[hx-1]!=1 && v[vx-1]!=1){f=1;h[hx-1]=1;v[vx-1]=1;}
     if(f==1)printf("%d ",i+1);
     f=0;


}


     return 0;
}