#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define lli long long int
#define MAX INT_MAX
#define PI acos(-1)
#define FOR(ii,aa,bb) for(ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(ii=aa;ii>bb;ii--)
#define buyuk(a,b) (a<b)? b:a
#define min(a,b) (a<b)? a:b
#define ort(a,b) (a+b)/2
#define carp(a,b) (a)*(b)
/*
   void sort(int bas,int ort,int son){
   int yer=bas,x=bas,y=ort+1,t,i;
   while(x <= ort && y <= son){
   if(a[x] < a[y]) temp[yer++]=a[x++];
   else temp[yer++]=a[y++];}
   while(x <= ort) temp[yer++]=a[x++];
   while(y <= son) temp[yer++]=a[y++];
   for(i=bas;i<=son;i++) a[i]=temp[i];}   
   void merge(int bas,int son){
   if(son <= bas)return;
   int ort=(bas+son)/2;
   merge(bas,ort);
   merge(ort+1,son);
   sort(bas,ort,son);}
   */
int main () {
	int bas,son,i,j,t=0,m=0,arr[105],x;
	scanf("%d",&x);
	for(i=0;i<x;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<x;i++){
		if(arr[i]==1)
			break;
		if(arr[i]==0)
			arr[i]=3;
	}
	bas=i;
	for(i=x;i>=0;i--){
		if(arr[i]==1)
			break;
	if(arr[i]==0)
		arr[i]=3;
	}
	son=x-(i+1);
	if(bas==x){
		printf("0");
		return 0;
	}
	t=t-(bas+son);
	for(i=bas;i<x-son;i++){
 		if((arr[i]==0 &&( arr[i+1]!=0 && arr[i-1]!=0 ))|| arr[i]==1)
 		m++;
	}

	printf("%d",m);

}