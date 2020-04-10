#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Sort(int size, int *ans1, int *ans2){
	 int leftMark = 1, buff, i, num1 = 0, num2 = 0, k;
 	 int rightMark = size - 1;
	for(k=0; k<5; k++){
		int arr[size];
		for(i=0; i<size; i++){
			arr[i] = rand()%100;
		}
		while (leftMark <= rightMark){
 			for (i = rightMark; i >= leftMark; i--){
 				num1++;
 				if (arr[i - 1] > arr[i]){
 					buff = arr[i];
 					arr[i] = arr[i-1];
 					arr[i-1] = buff;
 					num2++;
 				}
 			}
 			leftMark++;
 			for (i = leftMark; i <= rightMark; i++){
 				num1++;
 				if (arr[i - 1] > arr[i]){
 					buff = arr[i];
 					arr[i] = arr[i-1];
 					arr[i-1] = buff;
 					num2++;
 				}
 			}
 			rightMark--;
 		}

	}
	num1 = num1/5;
	num2 = num2/5;
	*ans1 = num1;
	*ans2 = num2;
}
int main(int argc, char *argv[]) {
	int i, l = 2*(sizeof(int)+sizeof(';'));
	int buf[2];
	FILE *fp, *fp1;
	fp = fopen("../forAllLabs/answer.csv", "r");
	fp1 = fopen("../forAllLabs/answerWithLaba3.csv", "w");
	int ans1, ans2;
	for(i=0; i<10000; i+=100){
		fscanf(fp, "%d;%d;", &buf[0], &buf[1]);
	//	printf("%d    %d\n", buf[0], buf[1]);
		Sort(i, &ans1, &ans2);
		fprintf(fp1, "%d;%d;%d;\n", buf[0], buf[1], (ans2+ans1));
	}
	fclose(fp);
	fclose(fp1);
	printf("end");
	return 0;
}
