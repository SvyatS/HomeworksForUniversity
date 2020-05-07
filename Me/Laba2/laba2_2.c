#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Sort(int n, int *ans1, int *ans2){
	int i, j, k, k1=0, k2=0, b;
	for(k=0; k<5; k++){
		int x[n];
		for(i=0; i<n; i++){
			x[i] = rand()%100;
		}
		for (i = 0; i < n; i++){
			b = x[i];
			j = i - 1;
			while (b < x[j]&&j>=0){
				x[j + 1] = x[j];
				j--;
				k1++;
			}
			x[j + 1] = b;
			k2++;
		}
	}
	k1 = k1/5;
	k2 = k2/5;
	*ans1 = k1;
	*ans2 = k2;
}

int main(int argc, char *argv[]) {
	int i;
	FILE *fp;
	fp = fopen("answer.csv", "w");
	int ans1, ans2;
	for(i=100; i<=10000; i+=100){
		Sort(i, &ans1, &ans2);
		fprintf(fp, "%d;%d\n", i, (ans2 + ans1)/2);
	}
	fclose(fp);
	printf("end");
	return 0;
}
