#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data);
Node* getLast(Node *head);
void pushBack(Node *head, int value);
Node* getNth(Node* head, int n);
int pop(Node **head);
int deleteNth(Node **head, int n);
int deleteMax(Node *head);
int deleteSelect(Node *head, int n);
int searchNum(Node *head, int n);
int ChangeNth(Node **head, int n, int data);
void printLinkedList(const Node *head);
