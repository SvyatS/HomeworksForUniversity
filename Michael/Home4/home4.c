#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, size, i, one;
	printf("Enter power sets: ");
	scanf("%d", &n);
	
	printf("Enter number of units: ");
	scanf("%d", &one);
	
	printf("Enter size of array: ");
	scanf("%d", &size);
	int A[size];
	
	printf("Enter elements of array:\n");
	for(i=0; i<size; i++){
		scanf("%d", &A[i]);
	}
	printf("\n\n\n");
	int k = 0, num, j, boolM;
	int M[n], schet = 0;
	for(i=0; i<n; i++) M[i] = 0;
	int N = pow(2, n) - 1;
	for(i=1; i<N; i++){
		num = i;
		while(num > 1){
			if(num%2==0){
			num /= 2;
			k++;
			}else break;
		}
		if(M[k] == 0) M[k] = 1;
		else M[k] = 0;
		for(j=0; j<n; j++){
			if(M[j] == 1) schet++;
		}
		for(j=0; j<size; j++){
			if(i == A[j] && schet == one){
				printf("%d   ", A[j]);
				for(boolM = n-1; boolM >= 0; boolM--) printf("%d", M[boolM]);
				printf("\n");
			}
		}
		schet = 0;
		k = 0;
	}
	
	return 0;
}
