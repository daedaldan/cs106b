// CS106B: Programming Abstractions Assignment 1 Problem 1

#include <iostream>
#include <string>

using namespace std;

string CensorString1(string input, string remove) {
    int i = 0;
    
    while (i < input.length()) {
        if (remove.find(input[i]) != string::npos) {
            input.erase(i, 1);
        } else {
            i++;
        }
    }
    
    return input;
}

void CensorString2(string & input, string remove) {
    int i = 0;
    
    while (i < input.length()) {
        if (remove.find(input[i]) != string::npos) {
            input.erase(i, 1);
        } else {
            i++;
        }
    }
}

int main() {
    string test1 = "Stanford University";
    string test2 = "Llamas like to laugh";
    
    cout << CensorString1(test1, "nt") << endl;
    cout << CensorString1(test2, "la") << endl;
    
    cout << test1 << endl;
    cout << test2 << endl;
    
    CensorString2(test1, "nt");
    CensorString2(test2, "la");
    
    cout << test1 << endl;
    cout << test2 << endl;
    
    return 0;
}
