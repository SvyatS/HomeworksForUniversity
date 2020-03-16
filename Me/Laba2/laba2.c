#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	system("chcp 1251");
	system("COLOR 2");
	srand(time(NULL));
	int i,j,b,n,k = 0, k2 = 0;
	printf("Введите количество элементов в массиве\n");
	scanf("%d",&n);
	int	x[n];
	printf("Сформирован массив элементов:\n");
	for (i = 0; i < n; i++){
		x[i] = rand()%100+1;
		printf("%d ",x[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++){
		b = x[i];
		j = i - 1;
		while (b < x[j]&&j>=0){
			x[j + 1] = x[j];
			j--;
			k++;
		}
		x[j + 1] = b;
		k2++;
	}
	printf("Отсортированный массив:\n");
	for (i = 0; i < n; i++){
		printf("%d ",x[i]);
	}
	printf("\n");
	printf("Количество перестановок и сравнений: %d  %d",k, k2);
	return 0;
}
