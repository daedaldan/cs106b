// CS106B: Programming Abstractions Assignment 3 Problem 8

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void listMnemonicsHelper(string used, string remaining, map<char, vector<string>> key) {
    if (remaining == "") {
        cout << used << endl;
    } else {
        listMnemonicsHelper(used + key[remaining[0]][0], remaining.substr(1), key);
        listMnemonicsHelper(used + key[remaining[0]][1], remaining.substr(1), key);
        listMnemonicsHelper(used + key[remaining[0]][2], remaining.substr(1), key);
    }
}

// only takes a string of integers
// possible optimization: strip the input string of non-integer characters as a preprocessing step
void listMnemonics(string str) {
    map<char, vector<string>> touchTone;

    // manually creating TouchTone telephone dial digit-letter key
    // possible optimization: use for/while loops and ASCII codes of characters to automatically populate the touchTone map
    vector<string> two;
    two.push_back("A");
    two.push_back("B");
    two.push_back("C");
    vector<string> three;
    three.push_back("D");
    three.push_back("E");
    three.push_back("F");
    vector<string> four;
    four.push_back("G");
    four.push_back("H");
    four.push_back("I");
    vector<string> five;
    five.push_back("J");
    five.push_back("K");
    five.push_back("L");
    vector<string> six;
    six.push_back("M");
    six.push_back("N");
    six.push_back("O");
    vector<string> seven;
    seven.push_back("P");
    seven.push_back("R");
    seven.push_back("S");
    vector<string> eight;
    eight.push_back("T");
    eight.push_back("U");
    eight.push_back("V");
    vector<string> nine;
    nine.push_back("W");
    nine.push_back("X");
    nine.push_back("Y");
    touchTone['2'] = two;
    touchTone['3'] = three;
    touchTone['4'] = four;
    touchTone['5'] = five;
    touchTone['6'] = six;
    touchTone['7'] = seven;
    touchTone['8'] = eight;
    touchTone['9'] = nine;
    listMnemonicsHelper("", str, touchTone);
}

int main() {
    listMnemonics("723");
    
    return 0;
}
