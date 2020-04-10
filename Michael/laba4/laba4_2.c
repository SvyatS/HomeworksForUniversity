#include <stdlib.h>
#include <stdio.h>

void Sort(int n, int *ans1, int *ans2){
	int i, j, k, num1=0, num2=0, step = n, tmp;
	for(k=0; k<5; k++){
		int mass[n];
		for(i=0; i<n; i++){
			mass[i] = rand()%100;
		}
		if(n>500){
    		while(step>0){
   	 			for(i = step; i < n; i++){
            		tmp = mass[i];
            		for (j = i; j >= step; j -= step){
            			num1++;
                		if (tmp < mass[j - step]){
                			mass[j] = mass[j - step];
                    		num2++;
                		}
                		else break;
                    
            		}
            		mass[j] = tmp;
         		}
         		step = (step-1)/2;
   			}  
    	}else{
    		while(step>0){
   	 			for(i = step; i < n; i++){
            		tmp = mass[i];
            		for (j = i; j >= step; j -= step){
            			num1++;
                		if (tmp < mass[j - step]){
                			mass[j] = mass[j - step];
                    		num2++;
                		}
                		else break;   
            		}
            		mass[j] = tmp;
         		}
         		step = (step-1)/3;
   			}
    	}

	}
	num1 = num1/5;
	num2 = num2/5;
	*ans1 = num1;
	*ans2 = num2;
}
int main(int argc, char *argv[]) {
	int i, buf[3];
	FILE *fp, *fp1;
	fp = fopen("../forAllLabs/answerWithLaba3.csv", "r");
	fp1 = fopen("../forAllLabs/answerWithLaba4.csv", "w");
	int ans1, ans2;
	for(i=0; i<10000; i+=100){
		fscanf(fp, "%d;%d;%d;", &buf[0], &buf[1], &buf[2]);
		Sort(i, &ans1, &ans2);
		fprintf(fp1, "%d;%d;%d;%d;\n", buf[0], buf[1], buf[2], (ans2+ans1));
	}
	fclose(fp);
	fclose(fp1);
	printf("end");
	return 0;
}
