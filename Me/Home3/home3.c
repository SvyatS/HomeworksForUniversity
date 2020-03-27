#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct ways{
	char country[40];
	int time[3];
	char check[3];
	int price;
}ways;

int main(){
	FILE *fp;
	ways x;
	int select[3];
	int price;
	char check[3] = "yes";
	printf("Day Month Year:");
	scanf("%d %d %d", &select[0], &select[1], &select[2]);
	printf("Price = ");
	scanf("%d", &price);
	fp = fopen("ways.txt", "r");
	int i, flag = 0;
	char str[80];
	
	for(i=0; i<20; i++){
		fscanf(fp, "%s %d.%d.%d %s %d", &x.country, &x.time[0], &x.time[1], &x.time[2], &x.check, &x.price);
		if(x.time[0] == select[0] && x.time[1] == select[1] && x.time[2] == select[2] && x.price <= price && x.check[0] == 'y'){
			printf("%s %d.%d.%d %s %d\n", x.country, x.time[0], x.time[1], x.time[2], x.check, x.price);
			flag = 1;
		}
	}
	
	if(flag == 0){
		printf("dont have countries");
	}
	
	fclose(fp);
	return 0;
}
