#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,j,b,n,k = 0, k2 = 0;
	printf("size of array = ");
	scanf("%d",&n); //������ ���������� ��������� �������
	int	x[n]; //��������� ������
	printf("array:\n");
	for (i = 0; i < n; i++){ //��������� ������ ���������� ������� �� 1 �� 100
		x[i] = rand()%100+1;
		printf("%d ",x[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++){ //��� �������� ����������
		b = x[i];
		j = i - 1;
		while (b < x[j]&&j>=0){
			x[j + 1] = x[j];
			j--;
			k++; //���������� ���������++
		}
		x[j + 1] = b;
		k2++; //���������� ������������++
	}
	printf("sorted array:\n");
	for (i = 0; i < n; i++){ //����� ���������������� �������
		printf("%d ",x[i]);
	}
	printf("\n");
	printf("number of transpositions and  comparisons: %d  %d",k2, k); //����� ���������� ������������ � ���������.
	return 0;
}
