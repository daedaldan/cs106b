// CS106B: Programming Abstractions Assignment 1 Problem 3

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void CountLetters(string filename) {
    ifstream input(filename.c_str());
    vector<int> alphaCount(0, 26);
    // for char in file
    // if char is in alphabet
    // alphaCount[char #] += 1
    
    // for i in alphaCount
    // cout << letter << ": " << alphaCount[i] << endl;
}

int main() {
    CountLetters("text.txt");
    
    return 0;
}
