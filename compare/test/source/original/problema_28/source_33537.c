#include<stdio.h>
	int a[104],i,n,t,b,s,g;
main(){
	scanf("%d",&n);
	s=n;
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	while(!a[b]) b++;
	while(!a[s]) s--;
	for(i=b;i<=s;i++)
		if(!a[i]){
			t++;
			if(t>=2)
				a[i]=a[i-1]=99;
		}
		else t=0;
	
	for(i=b;i<=s;i++)	
		if(a[i]!=99) g++;

	printf("%d",g);
}