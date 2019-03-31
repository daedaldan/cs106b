// CS106B: Programming Abstractions Assignment 7 Problem 5

#include <iostream>
#include <vector>

using namespace std;

struct Cell {
    Cell * next;
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

void stutter(Cell * list) {
    Cell * current = new Cell;
    current->value = list->value;
    current->next = list->next;
    
    list->next = current;
    
    while (current->next) {
        Cell * copy = new Cell;
        copy->value = current->value;
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }
    
    // manually duplicating last cell
    Cell * copy = new Cell;
    copy->value = current->value;
    copy->next = NULL;
    current->next = copy;
    
    // removing duplicate head cell from original linked list
    list->next = list->next->next;
}


int main() {
    vector<int> test;
    test.push_back(11);
    test.push_back(5);
    test.push_back(21);
    test.push_back(7);
    test.push_back(7);
    
    Cell * testList = convertToList(test);
    
    cout << "List before stutter:" << endl;
    printList(testList);
    
    cout << endl;
    stutter(testList);
    
    cout << "List after stutter:" << endl;
    printList(testList);
    
    return 0;
}
