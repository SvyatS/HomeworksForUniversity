#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	system("chcp 1251");
	system("COLOR 2");
	srand(time(NULL));
	int i,j,b,n,k = 0;
	printf("������� ���������� ��������� � �������\n");
	scanf("%d",&n);
	int	x[n];
	printf("����������� ������ ���������:\n");
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
			k+=3;
		}
		x[j + 1] = b;
		k++;
	}
	printf("��������������� ������:\n");
	for (i = 0; i < n; i++){
		printf("%d ",x[i]);
	}
	printf("\n");
	printf("���������� ������������ � ���������: %d",k);
	return 0;
}
