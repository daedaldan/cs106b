// CS106B: Programming Abstractions Assignment 2 Problem 3

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool isCorrectlyNested (string htmlStr) {
    // read the string and put all opening and closing tabs in a vector
    vector<string> tags;
    for (int i = 0; i < htmlStr.length(); i++) {
        if (htmlStr[i] == '<') {
            string tag;
            while (htmlStr[i] != '>') {
                tag += htmlStr[i];
                i++;
            }
            tag += ">";
            tags.push_back(tag);
        }
    }
    
    // put opening tags in stack
    stack<string> openingTags;
    for (int i = 0; i < tags.size(); i++) {
        if (tags[i][1] != '/') openingTags.push(tags[i]);
    }
    
    // put closing tags in queue
    queue<string> closingTags;
    for (int i = 0; i < tags.size(); i++) {
        if (tags[i][1] == '/') closingTags.push(tags[i]);
    }
    
    // return false if opening and closing tags don't match
    while (openingTags.size() != 0) {
        if (openingTags.top() != ('<' + closingTags.front().substr(2))) return false;
        openingTags.pop();
        closingTags.pop();
    }
    
    return true;
}

int main() {
    string test1 = "<html><b><i>CS106 rules!</i></b></html>";
    string test2 = "<html><bleh><b><i>CS106 rulessss?</i></b></html>";
    
    if (isCorrectlyNested(test1))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    if (isCorrectlyNested(test2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    return 0;
}
