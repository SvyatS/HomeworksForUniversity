#include <stdio.h>
#include <stdlib.h>

int mergeSort(int *a, int l, int r)
{
  if (l == r) return; 
  int mid = (l + r) / 2; 
  int num = 0;
  num += mergeSort(a, l, mid);
  num += mergeSort(a, mid + 1, r);
  int i = l; 
  int j = mid + 1; 
  int *tmp = (int*)malloc((r-l+1) * sizeof(int)); 
  for (int step = 0; step < r - l + 1; step++) 
  {
  	num++;
    if ((j > r) || ((i <= mid) && (a[i] < a[j]))) 
    {
      tmp[step] = a[i];
      i++;
    }
    else 
    {
      tmp[step] = a[j];
      j++;
    }
  }
  for (int step = 0; step < r - l + 1; step++){
  	a[l + step] = tmp[step];
  	num++;
  }
	free(tmp);
	return num;
}
int main(){
	FILE *fp, *fp1;
	fp = fopen("answer.csv", "w");
	fp1 = fopen("../Laba4/answer.csv", "r");
	int ans;
	int buf[4];
	for(int i=100; i<=10000; i+=100){
		ans = 0;	
		for(int j=0; j<5; j++){
			int a[i];
			for(int array=0; array<i; array++) a[i] = rand()%100;
			ans += mergeSort(a, 0, i-1)/2;
		}
		fscanf(fp1, "%d;%d;%d;%d", &buf[0], &buf[1], &buf[2], &buf[3]);	
		fprintf(fp, "%d;%d;%d;%d;%d\n", buf[0], buf[1], buf[2], buf[3], ans/5);
	}
	fclose(fp);
	fclose(fp1);
	printf("end");
	return 0;
}

