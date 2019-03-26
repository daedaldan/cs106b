// CS106B: Programming Abstractions Assignment 4 Problem 4

#include <iostream>
#include <vector>

using namespace std;

struct Cell {
	Cell *next;
	int value;
};

void printList(Cell * list) {
	cout << list->value << endl;
	if (list->next == NULL)
		return;
	else
		printList(list->next);
}

int sumList(Cell * list) {
	if (list->next == NULL)
		return list->value;
	else 
		return list->value + sumList(list->next);
}

Cell * convertToList(vector<int> & v) {
	Cell * head = new Cell;
	head->value = v[0];
	Cell * previous = head;
	for (int i = 1; i < v.size(); i++) {
		Cell * c = new Cell;
		c->value = v[i];
		previous->next = c;
		previous = c;
	}

	previous->next = NULL;

	return head;
}



int main() {
	vector<int> test1;
	test1.push_back(0);
	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);

	Cell * testLinkedList = convertToList(test1);

	cout << "Elements in testLinkedList:" << endl;
	printList(testLinkedList);

	cout << "Sum of the elements in testLinkedList:" << endl;
	cout << sumList(testLinkedList) << endl;

	return 0;
}