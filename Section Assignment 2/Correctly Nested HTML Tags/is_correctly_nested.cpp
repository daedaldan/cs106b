// CS106B: Programming Abstractions Assignment 2 Problem 3

#include <iostream>
#include <stack>

using namespace std;

bool isCorrectlyNested (string htmlStr) {
    stack<string> tags;
    cout << htmlStr << endl;
    cout << htmlStr.length() << endl;
    for (int i = 0; i < htmlStr.length(); i++) {
        if (htmlStr[i] == '<') {
            string tag;
            while (htmlStr[i-1] != '>') {
                tag += htmlStr[i];
                i++;
            }
            cout << tag << endl;
        }
    }
    // read through file
        // put opening tags in stack
    // read through file
        // if closing tag matches opening tag on top of stack, pop from stack
        // else, return false
    return true;
}

int main() {
    string test1 = "<html><b><i>CS106 rules!</i></b></html>";
    string test2 = "<html><bleh><b><i>CS106 rulessss?</i></b></html>";
    isCorrectlyNested(test1);
    return 0;
}
