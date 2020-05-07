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

int main() {
	int i, buf;
	FILE *fp;
	Node *head = NULL;
	Node *head2 = NULL;
	Node *end = NULL;
	fp = fopen("numbers.txt", "r");
	while(!feof(fp)){
		fscanf(fp, "%5d", &buf);
		head = AddToEnd(head, buf);
	}
	fclose(fp);
	printf("List from file:\n");
	print(head);
	printf("Sorted list (All elements =< 0):\n");
	int k = 0;
	while(head){
		if(head->data < 0)
			head2 = AddToEnd(head2, head->data);
		head = head->next;
	//	printf("%d\n", head->data);
	}
	print(head2);
	return 0;
}
