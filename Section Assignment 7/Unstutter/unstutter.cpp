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

// helper function for unstutter
void removeLastCell(Cell * list) {
    if (list->next->next == NULL) {
        list->next = NULL;
    } else {
        list->value = list->next->value;
        list = list->next;
        removeLastCell(list);
    }
}

void unstutter(Cell * list) {
    Cell * current = new Cell;
    current->next = list->next;
    current->value = list->value;

    list->next = current;
    
    while (current->next) {
        if (current->next->value == current->value) {
            current->next = current->next->next;
        } else {
            current->value = current->next->value;
            current = current->next;
        }
    }
    
    // manually removing duplicate cell at end (not sure why it appears)
    Cell * copy = new Cell;
    Cell * previous = new Cell;
    copy = list;
    
    while (copy->next) {
        previous = copy;
        copy->value = copy->next->value;
        copy = copy->next;
    }
    
    previous->next = NULL;
}

int main() {
    vector<int> test1;
    test1.push_back(11);
    test1.push_back(11);
    test1.push_back(5);
    test1.push_back(5);
    test1.push_back(3);
    test1.push_back(21);
    test1.push_back(21);
    test1.push_back(7);
    test1.push_back(7);
    test1.push_back(7);
    test1.push_back(4);
    test1.push_back(7);
    
    Cell * testList1 = convertToList(test1);
    
    cout << "List before unstutter:" << endl;
    printList(testList1);
    
    cout << endl;
    unstutter(testList1);
    
    cout << "List after unstutter:" << endl;
    printList(testList1);
    cout << endl;
    
    
    vector<int> test2;
    test2.push_back(0);
    
    Cell * testList2 = convertToList(test2);
    
    cout << "List before unstutter:" << endl;
    printList(testList2);
    
    cout << endl;
    unstutter(testList2);
    
    cout << "List after unstutter:" << endl;
    printList(testList2);
    
    return 0;
}
