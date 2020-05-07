#include <stdio.h>
#include <stdlib.h>

#define  root i+sh
#define  left 2*i+1+sh
#define right 2*i+2+sh

void swap (int *a, int *b) { int t = *a; *a = *b; *b = t; }

void Sort(int n, int *ans1, int *ans2){
	int i, j, num1 = 0, num2 = 0, sh = 0, b = 0;
	int a[n];
	for(j=0; j<5; j++){
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	sh = 0, b = 0;
  	while (1){
		b = 0;
		for (i = 0; i < n; ++i){
			if (right < n){
				num1++;
        		if (a[root] > a[left] || a[root] > a[right]){
	        		if (a[left] < a[right]){
	          			swap (&a[root], &a[left]);
	          			num2++;
	        			b = 1;
	        		}
	        		else if (a[right] < a[left]){
	          			swap (&a[root], &a[right]);
	          			num2++;
	          			b = 1;
	        		}
	      		}
      		}
      		else if (left < n){
      			num1++;
        		if (a[root] > a[left]){
	        		swap (&a[root], &a[left]);
	        		num2++;
	        		b = 1;
	      		}
      		}
    	}
    	if (!b) sh++;
    	if (sh + 2 == n) break;   	
	}
	}
	*ans1 = num1/5;
    *ans2 = num2/5;
}

int main(int argc, char *argv[]) {
	int i;
	FILE *fp, *fp1;
	fp = fopen("answer.csv", "w");
	fp1 = fopen("../Laba2/answer.csv", "r");
	int ans1, ans2;
	int buf[2];
	for(i=100; i<=10000; i+=100){
		fscanf(fp1, "%d;%d", &buf[0], &buf[1]);
		Sort(i, &ans1, &ans2);
		fprintf(fp, "%d;%d;%d\n", buf[0], buf[1], (ans2 + ans1)/2);
	}
	fclose(fp);
	printf("end");
	return 0;
}
