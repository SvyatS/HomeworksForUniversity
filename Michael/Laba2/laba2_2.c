#include <stdlib.h>
#include <stdio.h>

void Sort(int n, int *ans1, int *ans2){
	int i, j, k, s1=0, s2=0, temp;
	for(k=0; k<5; k++){
		int x[n];
		for(i=0; i<n; i++){
			x[i] = rand()%100;
		}
		for(i = 0; i < n-1; i++){
			for(j=i+1; j<n; j++){
				if(x[i]>x[j]){
					temp = x[i];
					x[i] = x[j];
					x[j] = temp;
					s1++;
				}
				s2++;
			}	
		}
	}
	s1 = s1/5;
	s2 = s2/5;
	*ans1 = s1;
	*ans2 = s2;
}
int main(int argc, char *argv[]) {
	int i;
	FILE *fp;
	fp = fopen("answer.csv", "w");
	int ans1, ans2;
	for(i=0; i<10000; i+=100){
		Sort(i, &ans1, &ans2);
		fprintf(fp, "%d;%d\n", ans2, ans1);
	}
	fclose(fp);
	printf("end");
	return 0;
}
