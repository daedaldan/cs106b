// CS106B: Programming Abstractions Assignment 7 Problem 2

#include <iostream>
#include <vector>

// original class

class Mob {
    public:
        Mob();
        void enqueue(int newElem);
        int dequeue();
        int size();
    private:
        Vector<int> elems;
};

void Mob::enqueue(int newElem) {
    elems.add(newElem);
}

int Mob::dequeue() {
    int elemNum = RandomInteger(0, elems.size()-1);
    int value = elems[elemNum];
    elems.removeAt(elemNum);
    return value;
}

// templatized version of class

template <typename Type>
class Mob {
    public:
        Mob();
        void enqueue(Type newElem);
        Type dequeue();
        Type size();
    private:
        Vector<Type> elems;
};

template <typename Type>
void Mob::enqueue(Type newElem) {
    elems.add(newElem);
}

template <typename Type>
Type Mob::dequeue() {
    Type elemNum = RandomInteger(0, elems.size()-1);
    Type value = elems[elemNum];
    elems.removeAt(elemNum);
    return value;
}
