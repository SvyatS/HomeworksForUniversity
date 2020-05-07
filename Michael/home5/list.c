#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

Node* getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void pushBack(Node *head, int value) {
	Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}


Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}


int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

int deleteNth(Node **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;
 
        prev->next = elm->next;
        free(elm);
        return val;
    }
}

int deleteMax(Node *head){
	int max = -9999999;
	Node *gg = head;
	int num = 0, maxnum = 0;
	while(gg){
		if(gg->value > max){
			max = gg->value;
			maxnum = num;
			printf("max %d\n", maxnum);
		}
		num++;
		gg = gg->next;
	}
	deleteNth(&head, maxnum);
}

int deleteSelect(Node *head, int n){
	Node *gg = head;
	int num = 0, maxnum = 0;
	while(gg){
		if(gg->value == n){
			maxnum = num;
			break;
		}
		num++;
		gg = gg->next;
	}
	deleteNth(&head, maxnum);
}

int searchNum(Node *head, int n){
	Node *gg = head;
	int num = 0, maxnum;
	while(gg){
		if(gg->value == n){
			maxnum = num;
			break;
		}
		num++;
		gg = gg->next;
	}
	if(maxnum == NULL){
		printf("\nERROR: dont searched\n", n);
	}
	return maxnum;
}

int ChangeNth(Node **head, int n, int data) {
    Node *prev = getNth(*head, n-1);
    prev->value = data;
}

void printLinkedList(const Node *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

