#include <stdio.h>
#include <stdlib.h>
#include "mylibraly.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	Node *head = NULL;
	push(&head, 123);
	for(int i = 0; i<10; i++) pushBack(head, i);
	printLinkedList(head);
	return 0;
}
