// CS: 106B Programming Abstractions Assignment 2 Problem 2

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> & q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> test;
    // initializing test queue
    for (int i = 1; i <= 20; i++)
        test.push(i);
    
    cout << "Queue values before reversal: " << endl;
    while (!test.empty()) {
        cout << test.front() << endl;;
        test.pop();
    }
    
    // reinitializing test queue
    for (int i = 1; i <= 20; i++)
        test.push(i);
    
    reverseQueue(test);
    
    cout << "Queue values after reversal: " << endl;
    while (!test.empty()) {
        cout << test.front() << endl;
        test.pop();
    }
    
    return 0;
}
