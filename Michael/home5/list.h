#pragma once
#ifndef LIST_H_
#define LIST_H_

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

#endif /* LIST_H_ */
