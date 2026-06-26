#include<stdio.h>

int main(){
int n,a,p;
int tmp=99999,total=0;

scanf("%d",&n);

for(int i=0;i<n;i++){
scanf("%d %d",&a,&p);
if(tmp>p){
	tmp=p;
}
else if(tmp<p){
	p=tmp;
}
total+=a*p;
}
printf("%d",total);
}