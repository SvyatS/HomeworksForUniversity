#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void myShakerSort(int *arr, int size, int *num1, int *num2){
 int leftMark = 1, buff, i, k1 = 0, k2 = 0;
 int rightMark = size - 1;
 while (leftMark <= rightMark)
 {
 for (i = rightMark; i >= leftMark; i--){
 	k1++;
 	if (arr[i - 1] > arr[i]){
 		buff = arr[i];
 		arr[i] = arr[i-1];
 		arr[i-1] = buff;
 		k2++;
 	}
 }
 	leftMark++;
 for (i = leftMark; i <= rightMark; i++){
 	k1++;
 	if (arr[i - 1] > arr[i]){
 		buff = arr[i];
 		arr[i] = arr[i-1];
 		arr[i-1] = buff;
 		k2++;
 	}
 }
 rightMark--;
 }
 *num1 = k1;
 *num2 = k2;
}

int main(int argc, char *argv[]) {
	int n, i, num1, num2;
	printf("n = ");
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);
	printf("not sorted array:\n");
	for(i=0; i<n; i++){
		arr[i] = rand()%100;
		printf("%3d", arr[i]);
	}
	printf("\n\n\n");
	printf("sorted array:\n");
	myShakerSort(arr, n, &num1, &num2);
	 for(i=0; i<n; i++){
		printf("%3d", arr[i]);
	}
	printf("\ncomparisons = %d\nswaps = %d\n", num1, num2);
	return 0;
}
