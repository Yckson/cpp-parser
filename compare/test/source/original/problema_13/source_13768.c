#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define PI 3.141592653589793
#define max(a,b) (a < b) ? (b) : (a)
#define min(a,b) (a > b) ? (b) : (a)
#define FOR(i,a,b) for(i = a ; i <= b ; i++)
#define ROF(i,a,b) for(i = a ; i >= b ; i--)
#define RAD(x) ((x)*PI)/180
#define y1 y_1
#define ll long long
#define endl printf("\n")
#define MAX 1005

int n, i, s, ans, a[MAX];

int main () {
	scanf("%d",&n);
	FOR(i, 1, n)
		scanf("%d",&a[i]);
	while(1){
		FOR(i, 1, n)
			if(a[i] <= s){a[i] = n + 1; s++;}
		ans++;
		if(s == n)
			break;
		ROF(i, n, 1)
			if(a[i] <= s){a[i] = n + 1 ; s++;}
		ans++;
		if(s == n)
			break;
	}
	printf("%d\n",ans - 1);
	return 0;
}