// CS106B: Programming Abstractions Assignment 7 Problem 1

#include <iostream>
#include "stack_class.cpp"

using namespace std;

template <typename Type>
void reverseStack(Stack<Type> & s) {
    Stack<Type> reverse;
    while (!s.isEmpty()) {
        reverse.push(s.pop());
    }
    
    s = reverse;
}

int main() {
    Stack<int> test;
    test.push(0);
    test.push(1);
    test.push(2);
    test.push(3);
    
    // printing initial stack values
    Stack<int> copy = test;
    while (!copy.isEmpty())
        cout << test.pop() << endl;
    
    reverseStack(test);
    // printing reversed stack values
    copy = test;
    while (!copy.isEmpty())
        cout << test.pop() << endl;
    
    return 0;
}
