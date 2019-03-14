// CS106B: Programming Abstractions Assignment 3 Problem 5

#include <iostream>
#include <string>

using namespace std;

string iterReverseString(string s) {
    string reverse;
    for (int i = s.size() - 1; i >= 0; i--)
        reverse += s[i];
    
    return reverse;
}

string recurReverseString(string s) {
    if (s.size() == 0 || s.size() == 1)
        return s;
    else
        return s[s.size() - 1] + recurReverseString(s.substr(0, s.size() - 1));
}

int main() {
    string test1 = "Hello there";
    string test2 = "Llamas wear pajamas";
    
    cout << "'" << test1 << "'" << " reversed iteratively is " << "'" << iterReverseString(test1) << "'" << endl;
    cout << "'" << test1 << "'" << " reversed recursively is " << "'" << recurReverseString(test1) << "'" << endl;
    cout << "'" << test2 << "'" << " reversed iteratively is " << "'" << iterReverseString(test2) << "'" << endl;
    cout << "'" << test2 << "'" << " reversed recursively is " << "'" << recurReverseString(test2) << "'" << endl;
    
    return 0;
}
