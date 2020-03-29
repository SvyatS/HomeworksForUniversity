#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct train{
	char place[40];
	int number;
	int time[2];
	int price;
}train;

int main(int argc, char *argv[]) {
	train A;
	FILE *fp;
	char place[40];
	printf("place: ");
	scanf("%s", &place);
	fp = fopen("ways.txt", "r");
	int lines = 0, i;
	while(!feof(fp)) {
    	fscanf(fp, "%*[^\n]%*c");
        lines++;
	}
	fclose(fp);
	fp = fopen("ways.txt", "r");
	for(i=0; i<lines; i++){
		fscanf(fp, "%s %d %d.%d %d", &A.place, &A.number, &A.time[0], &A.time[1], &A.price);
		if(strcmp(A.place, place) == 0){
			printf("%s %d %d.%d %d\n", A.place, A.number, A.time[0], A.time[1], A.price);
		}
	}
	return 0;
}
