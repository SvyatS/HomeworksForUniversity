#include <stdio.h>
#include <stdlib.h>
#define Error 0x7FFF


typedef struct Node {
    int data;
    struct Node *next;
} Node;

void *Add(Node *Top, int data) {
    Node *newel = (Node*) malloc(sizeof(Node));
    newel->data = data;
    newel->next = Top;
    return newel;
}

int Delete(Node **Top){
	int d;
	if((*Top) != NULL){
		d = (*Top)->data;
		Node *temp = *Top;
		*Top = (*Top)->next;
		free(temp);	
	}else{
		printf("Error delete!");
		d = Error;
	}
	return d;
}

Node *AddToEnd(Node *Top, int data){
	Node *newel = (Node*) malloc(sizeof(Node));
	newel->data = data;
    newel->next = NULL;
    if(Top == NULL) return newel;
    Node *temp = Top;
    while(temp->next) temp = temp->next;
    temp->next = newel;
    return Top;
}

void print(Node *Top) {
    while(Top){
        printf("%5d", Top->data);
        Top = Top->next;
    }
    printf("\n\n");
}

int Check(Node *Top, int num){
	while(Top){
        if(Top->data == num){
        	return NULL;
        }
        Top = Top->next;
    }
    return 1;
}
int main() {
	int i, buf;
	Node *L = NULL;
	Node *L1 = NULL;
	Node *L2 = NULL;
	for(i=0; i<10; i++){
		buf = rand()%50;
		L1 = AddToEnd(L1, buf);
		buf = rand()%50;
		L2 = AddToEnd(L2, buf);
	}
	printf("L1: ");
	print(L1);
	printf("L2: ");
	print(L2);
	while(L1){
		if(Check(L2, L1->data) && Check(L1->next, L1->data))	L = AddToEnd(L, L1->data);
		L1 = L1->next;
	}
//	while(L){
//		printf("%5d", L->data);
//		if(Check(L->next, L->data))	Delete(&L);
//		else L = L->next;
//	}
	printf("L: ");
	print(L);
	return 0;
}
