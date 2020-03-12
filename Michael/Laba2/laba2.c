#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
	system("chcp 1251");
	srand(time(NULL));
	int i, j, n ,temp ,k = 0;
	printf("Введите количество элементов в массиве\n");
	scanf("%d",&n);
	int x[n];
	printf("Сформирован массив элементов:\n");
	for (i = 0; i < n; i++){
		x[i] = rand()%100;
		printf("%3d",x[i]);
	}
	printf("\n");
	for (i = 0; i < n-1; i++){
		for(j=i+1; j<n; j++){
			if(x[i]>x[j]){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
				k++;
			}
		}
	}
	printf("Отсортированный массив:\n");
	for (i = 0; i < n; i++){
		printf("%d ",x[i]);
	}
	printf("\n");
	printf("Количество перестановок и сравнений: %d",k);
	return 0;
}
