#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};


struct Node* first = NULL;


void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int contains(int value) {
	struct Node * ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

int sum() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int evenSum() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			s += ptr->data;
		}
		ptr = ptr->next;
	}
	return s;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 == 1) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
	}
}

void elementIx100(int i) {
	struct Node * ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data = ptr->data * 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void leftElementIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index < i) {
			ptr->data = ptr->data * 10;
		}
		ptr = ptr->next;
		index++;
	}
}

void main() {
	first = NULL;
	printList(); // printList cheeeeck

	addToHead(10); // add cheeeeck
	printList();

	deleteFromHead(); // delete cheeeeck
	printList();

	addToHead(30); 
	printf("%d\n", contains(30)); // contains cheeeeck

	addToHead(30);  // clearlist cheeeeck
	addToHead(40);
	addToHead(50);
	printList();
	clearList();
	printList();

	addToHead(30); // sum cheeeeck
	addToHead(40);
	addToHead(50);
	printf("sum = %d\n", sum());

	clearList();   // evensum cheeeeck
	addToHead(30); 
	addToHead(127);
	addToHead(50);
	printf("sum of even = %d\n", evenSum());

	clearList();   // oddsX10 cheeeeck
	addToHead(30);
	addToHead(17);
	addToHead(5);
	oddsX10();
	printList();

	clearList();   // elementIx100 cheeeeck
	addToHead(30);
	addToHead(17);
	addToHead(5);
	elementIx100(2);
	printList();

	clearList();   // leftElemntIx10 cheeeeck
	addToHead(3);
	addToHead(2);
	addToHead(7);
	addToHead(5);
	leftElementIx10(2);
	printList();
}