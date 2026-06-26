#include <stdio.h>

int main()

{
	int n, aulas, i, ii;
	aulas = 0;
	scanf("%d", &n);
	int vetor[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}


	for (i = 0; i < n; i++) {
		if (vetor[i] == 1) {
			aulas = aulas + 1;
		}
		if (vetor[i] == 0 && i != 0 && vetor[i - 1] == 1) {
			if (vetor[i + 1] == 1) {
				aulas = aulas + 1;
			}

		}
		}

	printf("%d", aulas);


	return 0;
}