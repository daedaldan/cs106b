// CS106B: Programming Abstractions Assignment 4 Problem 6

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

Cell * deepCopyList(Cell * list) {
	Cell * head = new Cell;
	head->value = 1;
	head->next = NULL;
	return head;
}

// appends the second list onto the first
void appendList(Cell *l1, Cell *l2) {
	if (l2->next == NULL) {
		// do nothing
	} else if (l1->next == NULL) {
		l1->next = deepCopyList(l2);
	} else {
		appendList(l1->next, l2);
	}
}

int main() {
	vector<int> test1;
	test1.push_back(1);
	test1.push_back(4);
	test1.push_back(6);
	vector<int> test2;
	test2.push_back(3);
	test2.push_back(19);
	test2.push_back(2);

	Cell * testList1 = convertToList(test1);
	Cell * testList2 = convertToList(test2);

	cout << "List 1:" << endl;
	printList(testList1);
	cout << "List 2:" << endl;
	printList(testList2);

	appendList(testList1, testList2);
	cout << "List 2 appended onto List 1" << endl;
	printList(testList1);

	return 0;
}