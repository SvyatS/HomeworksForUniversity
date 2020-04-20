#include <stdio.h>
#include <stdlib.h>
#define N 4
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int score = 0, num = 0, i, j;
	int table[N][N] = {{0, 3, 1, 3}, {0, 0, 1, 3}, {0, 0, 0, 1}, {3, 3, 3, 0}};
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%3d", table[i][j]);
		}
		printf("\n");
	}
	
	
	//Алгоритм
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(table[i][j] == 3){
				score++;
			}else if(table[i][j] == 0){
				score--;
			}
		}
		if(score > 0) num++;
		score = 0;
	}
	printf("answer = %d\n", num);
	return 0;
}
