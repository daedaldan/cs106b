// CS106B: Programming Abstractions Assignment 7 Problem 6

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

void unstutter(Cell * list) {
    Cell * current = new Cell;
    current->value = list->value;
    current->next = list->next;
    
    while (current->next) {
        if (current->next->value == current->value) {
            Cell * newNext = current->next->next;
            current->next = newNext;
        } else {
            current->value = current->next->value;
            current = current->next;
        }
    }
}

int main() {
    vector<int> test;
    test.push_back(11);
    test.push_back(11);
    test.push_back(5);
    test.push_back(5);
    test.push_back(3);
    test.push_back(21);
    test.push_back(21);
    test.push_back(7);
    test.push_back(7);
    test.push_back(7);
    test.push_back(4);
    test.push_back(7);
    
    Cell * testList = convertToList(test);
    
    cout << "List before unstutter:" << endl;
    printList(testList);
    
    cout << endl;
    unstutter(testList);
    
    cout << "List after unstutter:" << endl;
    printList(testList);
    
    return 0;
}
