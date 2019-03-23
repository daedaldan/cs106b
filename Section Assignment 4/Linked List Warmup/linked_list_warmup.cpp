// CS106B: Programming Abstractions Assignment 4 Problem 4

#include <iostream>
#include <vector>

struct Cell {
	Cell *next;
	int value;
};

Cell * convertToList(vector<int> v) {
	Cell * head;
	head->value = v[0];

	Cell * previous = head;
	for (int i = 1; i < v.size(); i++) {
		Cell * c;
		c->value = v[i];
		previous->next = c;
		previous = c;
	}

	previous->next = NULL;

	return head;
}

void printList(Cell * list) {
	cout << list->value << endl;
	if (list->next == NULL)
		return
	else
		printList(list->next);
}

int main() {
	vector<int> testVector;
	test1.push_back(0);
	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);

	Cell * testLinkedList = convertToList(testVector);

	printList(testLinkedList);

	return 0;
}