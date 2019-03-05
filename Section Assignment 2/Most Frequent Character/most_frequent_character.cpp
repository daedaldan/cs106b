// CS106B: Programming Abstractions Assignment 2 Problem 4

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

char MostFrequentCharacter(ifstream &input, int &numOccurences) {
    map<char, int> charCount;
    char c;
    while (input.get(c)) {
        if (charCount.find(c) != charCount.end()) {
            charCount[c] += 1;
        } else {
            charCount[c] = 1;
        }
    }
    
    numOccurences = -1;
    char maxChar;
    
    map<char, int>::iterator it = charCount.begin();
    while (it != charCount.end()) {
        if (it->second > numOccurences) {
            numOccurences = it->second;
            maxChar = it->first;
        }
        advance(it, 1);
    }
    
    input.close();
    
    return maxChar;
}

int main() {
    int testOccurences = 0;
    ifstream testInput;
    testInput.open("test.txt");
    cout << "The most frequent character was '" << MostFrequentCharacter(testInput, testOccurences) << "', occuring " << testOccurences << " times." << endl;
    return 0;
}
