// CS106B: Programming Abstractions Assignment 3 Problem 1

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// contact list entry type
struct entryT {
    string firstName;
    string lastName;
    string phoneNumber;
};

int main() {
    /* Part A of Problem */
    
    // had trouble with how to use a custom set comparator and looked up on StackOverflow
    auto nameCompare = [] (entryT a, entryT b) {
        if(a.lastName != b.lastName) return a.lastName < b.lastName;
        else return a.firstName < b.firstName;
    };
    set<entryT, decltype(nameCompare)> testContacts(nameCompare);
    
    // initializing test entryTs
    entryT tim;
    tim.firstName = "Tim";
    tim.lastName = "Baker";
    tim.phoneNumber = "123-456-7890";
    entryT sue;
    sue.firstName = "Sue";
    sue.lastName = "Park";
    sue.phoneNumber = "123-456-7891";
    entryT joe;
    joe.firstName = "Joe";
    joe.lastName = "Smith";
    joe.phoneNumber = "123-456-7892";
    entryT todd;
    todd.firstName = "Todd";
    todd.lastName = "Smith";
    todd.phoneNumber = "123-456-7893";
    
    // inserting test entryTs
    testContacts.insert(tim);
    testContacts.insert(sue);
    testContacts.insert(joe);
    testContacts.insert(todd);
    
    // printing testContact entries
    for (entryT person : testContacts) {
        cout << person.firstName << " " << person.lastName << ", " << person.phoneNumber << endl;
    }
    
    
    /* Part B of Problem */
    cout << endl;
    cout << endl;
    
    cout << "Case sensitive set's elements: " << endl;
    set<string> caseSensitive;
    caseSensitive.insert("Tim Baker");
    caseSensitive.insert("tim Baker");
    caseSensitive.insert("tim baker");
    for (string person : caseSensitive) cout << person << endl;
    
    cout << "Case insensitive set's elements: " << endl;
    auto stringCompare = [] (string a, string b) {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a < b;
        
    };

    set<string, decltype(stringCompare)> caseInsensitive(stringCompare);
    caseInsensitive.insert("Tim Baker");
    caseInsensitive.insert("tim Baker");
    caseInsensitive.insert("tim baker");
    for (string person : caseInsensitive) cout << person << endl;

    return 0;
}
