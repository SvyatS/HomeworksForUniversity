#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ShellSort(int n, int mass[], int *k1, int *k2)
{
    int i, j, step = n;
    int num1 = 0, num2 = 2;
    int tmp;
    if(n>500){
    	while(step>0){
   	 		for(i = step; i < n; i++){
            	tmp = mass[i];
            	for (j = i; j >= step; j -= step){
                	if (tmp < mass[j - step]){
                		mass[j] = mass[j - step];
                    	num2++;
                	}
                	else break;
                    
            	}
            	num1++;
            	mass[j] = tmp;
         	}
         	step = (step-1)/2;
   		}  
    }else{
    	while(step>0){
   	 		for(i = step; i < n; i++){
            	tmp = mass[i];
            	for (j = i; j >= step; j -= step){
                	if (tmp < mass[j - step]){
                		mass[j] = mass[j - step];
                    	num2++;
                	}
                	else break;   
            	}
            	num1++;
            	mass[j] = tmp;
         	}
         	step = (step-1)/3;
   		}
    }
   *k1 = num2;
   *k2 = num1;
}

int main(int argc, char *argv[]) {
	int n;
	printf("Enter n = ");
	scanf("%d", &n);
	int x[n], i, k1=0, k2=0;
	for(i=0; i<n; i++){
		x[i] = rand()%100;
	}
	ShellSort(n, x, &k1, &k2);
	printf("%d  %d", k1, k2);
	
	return 0;
}
