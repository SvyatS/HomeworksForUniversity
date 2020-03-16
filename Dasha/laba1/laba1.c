#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *input, *output;
	int i, j, m, n, k, flag = 0;
	float num;
	fpos_t *position;
	printf("m, n = ");
	scanf("%d %d", &m, &n);	//вводим количество строк и стобцов n<m
	int delete[n-m]; //матрица в которой будут храниться индексы удаляемых столбцов
	input = fopen("answer.bin", "wb");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){ //записываем матрицу в файл (элементы генерируются рандомно от 0 до 9)
			num = rand()%10;
			fwrite(&num, sizeof(float), 1, input);
		}
	}
	fclose(input);
	output = fopen("answer.bin", "rb");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){ //выводим матрицу с файла
			fread(&num, sizeof(float), 1, output);
			printf("%10f", num);
		}
		printf("\n");
	}
	fclose(output);
	printf("\n\n\n");
	output = fopen("answer.bin", "rb");
	input = fopen("answer2.bin", "wb");
	for(i=0; i<n-m; i++){ //записывае индексы столбцов которые хотим удалить
		printf("delete: ");
		scanf("%d", &delete[i]);
	}
	printf("\n\n\n");
	for(i=0; i<m; i++){
		position = sizeof(float)*i*n; //вычисляем позицию первого элемента строки
	 	fsetpos(output, &position); //устанавливаем ее 
		for(j=0; j<n; j++){
			for(k=0; k<n-m; k++){
				if(delete[k] == j){ //если столбец == индексу из массива то переходим в позицию следующего элемента строки
					flag = 1;
					position = sizeof(float)*(i*n+j+1);
	 				fsetpos(output, &position);
				}
			}
			if(flag == 0){ //если столбец != индексу из массива то считываем его в файл
				fread(&num, sizeof(float), 1, output);
				fwrite(&num, sizeof(float), 1, input);	
			}	
			flag = 0;			
		}
	}
	fclose(input);
	fclose(output);
	printf("\n\n\n");
	output = fopen("answer2.bin", "rb");
	for(i=0; i<m; i++){ //выводим файл с конечным результатом
		for(j=0; j<m; j++){
			fread(&num, sizeof(float), 1, output);
			printf("%10f", num);
		}
		printf("\n");
	}
	fclose(output);
	return 0;
}
