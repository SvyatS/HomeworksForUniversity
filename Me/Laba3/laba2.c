#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,j,b,n,k = 0, k2 = 0;
	printf("size of array = ");
	scanf("%d",&n); //вводим количесвто элементов массива
	int	x[n]; //объявляем массив
	printf("array:\n");
	for (i = 0; i < n; i++){ //заполняем массив случайными числами от 1 до 100
		x[i] = rand()%100+1;
		printf("%d ",x[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++){ //сам алгоритм сортировки
		b = x[i];
		j = i - 1;
		while (b < x[j]&&j>=0){
			x[j + 1] = x[j];
			j--;
			k++; //количество сравнений++
		}
		x[j + 1] = b;
		k2++; //количество перестановок++
	}
	printf("sorted array:\n");
	for (i = 0; i < n; i++){ //вывод отсортированного массива
		printf("%d ",x[i]);
	}
	printf("\n");
	printf("number of transpositions and  comparisons: %d  %d",k2, k); //вывод количества перестановок и сравнений.
	return 0;
}
