#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void createList(Node **START) {
	*START = NULL;
	printf("List created successfully\n");
	return;
}

void insert(Node **START, int data) {
	Node *new_node = (Node *)malloc(sizeof(Node));	// Ignore CPPLintBear
	new_node->data = data;
	if (*START == NULL) {
		new_node->next = NULL;
		*START = new_node;
	} else {
		new_node->next = *START;
		*START = new_node;
	}
}

void printList(Node **START) {
	Node *temp = *START;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	Node* START;
	createList(&START);
	insert(&START, 12);
	insert(&START, 10);
	insert(&START, 9);
	insert(&START, 56);
	insert(&START, 17);
	printList(&START);
}
