#include <iostream>
#include <cstdlib>

using namespace std; 
  
int getNextGap(int gap) 
{ 
    gap = (gap*8)/11; 
  
    if (gap < 1) 
        return 1; 
    return gap; 
} 

void Sort(int n, int *ans1, int *ans2){
	int i, j, num1 = 0, num2 = 0;
	int a[n];
	for(j=0; j<5; j++){
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	int gap = n; 
    bool swapped = true; 
  
    while (gap != 1 || swapped == true) 
    { 
        gap = getNextGap(gap); 
        swapped = false; 
        for (int i=0; i<n-gap; i++) 
        { 
            if (a[i] > a[i+gap]) 
            { 
                swap(a[i], a[i+gap]); 
                num2++;
                swapped = true; 
            }
			num1++; 
        } 
    } 
	}
	*ans1 = num1/5;
    *ans2 = num2/5;
}


int main(int argc, char *argv[]) {
	int i;
	FILE *fp, *fp1;
	fp = fopen("answer.csv", "w");
	fp1 = fopen("../Laba3/answer.csv", "r");
	int ans1, ans2;
	int buf[3];
	for(i=100; i<=10000; i+=100){
		fscanf(fp1, "%d;%d;%d", &buf[0], &buf[1], &buf[2]);
		Sort(i, &ans1, &ans2);
		fprintf(fp, "%d;%d;%d;%d\n", buf[0], buf[1], buf[2], (ans2 + ans1)/2);
	}
	fclose(fp);
	fclose(fp1);
	printf("end");
	return 0;
}
