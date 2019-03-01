// CS106B: Programming Abstractions Assignment 1 Problem 3

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void CountLetters(string filename) {
    ifstream input(filename.c_str());
    vector<int> alphaCount(26, 0);
    
    // reading chars from the file while updating alphaCount
    if (input.is_open()) {
        char c;
        while (input.get(c)) {
            c = tolower(c);
            if (c >= 97 && c <= 122) {
                alphaCount[c-97] += 1;
            }
        }
    }
    
    // iterate through alphaCount and print results
    for (int i = 0; i <= 25; i++) {
        cout << static_cast<char>(i + 97) << ": " << alphaCount[i] << endl;
    }
}

int main() {
    CountLetters("text.txt");
    
    return 0;
}
