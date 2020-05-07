#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int factorial(int num){
	int S = 1;
	for(int i=1; i<=num; i++){
		S *= i;
	}
	return S;
}
int main(int argc, char *argv[]) {
	int n, i, one;
	printf("Enter power sets: ");
	scanf("%d", &n);
	
	printf("Enter number of units: ");
	scanf("%d", &one);
	
	int A[n];
	
	printf("Enter elements of array:\n");
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	printf("\n\n\n");
	int k = 0, num, j;
	int M[n], schet = 0;
	for(i=0; i<n; i++) M[i] = 0;
	int N = pow(2, n) - 1;
	for(i=1; i<=N; i++){
		num = i;
		while(num > 1){
			if(num%2==0){
			num /= 2;
			k++;
			}else break;
		}
		if(M[k] == 0) M[k] = 1;
		else M[k] = 0;
		for(j=0; j<n; j++) if(M[j] == 1) schet++;
		if(schet == one){
			for(j=n-1; j>=0; j--){
				if(M[j] == 1){
					printf(" %d ", A[abs(j-(n-1))]);
				}
			}
			printf("\n");
		}
		k = 0;
		schet = 0;
	}
	
	return 0;
}
