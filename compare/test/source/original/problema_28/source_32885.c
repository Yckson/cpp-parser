#include <stdio.h>


int main(){
	int n, i, a[105];
	scanf("%d", &n);

	int which[n];

	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	//populates 'which' vector
	int j = 0;
	int populou = 0;
	for(i=0; i<n; i++){
		if(a[i] == 1){
			which[j++] = i;
			populou = 1;
		}
	}

	//sets initial stayFor value to the subtraction of first and last pairs
	int stayFor = 0;
	if(populou) stayFor = which[j-1] - which[0] + 1;
	
	//checks 2-by-2 for zeros between them
	for(i=0; i<j-1; i++){
		if(which[i+1] - which[i] > 2){
			stayFor -= (which[i+1] - which[i] - 1);
		}
	}


	printf("%d\n", stayFor);

	return 0;
}