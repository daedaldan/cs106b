// CS106B: Programming Abstractions Assignment 7 Problem 1

#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
class Stack {
    public:
        Stack();
        ~Stack();
    
        void push(Type elem);
        Type pop();
    
        bool isEmpty();
    
        void reverse(Stack<Type> & s);
    private:
        vector<Type> elems;
}

void Stack::Stack();

void Stack::reverse(Stack<Type> & s) {
    vector<Type> originalElems = s.elems;
    vector<Type> reversedElems;
    for (int i = originalElems.size() - 1; i >= 0; i--)
        reversedElems.push_back(originalElems[i]);
    
    s.elems = reversedElems;
}
