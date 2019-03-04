// CS106B: Programming Abstractions Assignment 2 Problem 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct eMailMsg {
    string to; // e.g. professor@stanford.edu
    string from; // e.g. student@stanford.edu
    string message; // body of message
    string subject; // subject of message
    int date; // date email was sent
    int time; // time email was sent
};

struct eMailMsg2 {
    vector<string> to; // e.g. professor@stanford.edu, ted@stanford.edu
    string from; // e.g. student@stanford.edu
    string message; // body of message
    string subject; // subject of message
    int date; // date email was sent
    int time; // time email was sent
};

void removeSpam(vector<eMailMsg> & emails) {
    for (int i = 0; i < emails.size(); i++) {
        if (emails[i].subject.find("SPAM") != string::npos) {
            emails.erase(emails.begin() + i);
            i--;
        }
    }
}

int main() {
    vector<eMailMsg> myEmails;
    
    eMailMsg test1;
    test1.to = "bob@lol.com";
    test1.from = "ted@lol.com";
    test1.message = "hi";
    test1.subject = "hi";
    test1.date = 1;
    test1.time = 1;
    
    eMailMsg test2;
    test2.to = "bob@lol.com";
    test2.from = "spammer@spams.org";
    test2.message = "hi";
    test2.subject = "SPAM";
    test2.date = 1;
    test2.time = 1;
    
    myEmails.push_back(test1);
    myEmails.push_back(test2);
    
    cout << "original emails:" << endl;
    for (int i = 0; i < myEmails.size(); i++) {
        cout << myEmails[i].subject << endl;
    }
    
    removeSpam(myEmails);
    
    cout << endl;
    cout << "emails after spam removal:" << endl;
    for (int i = 0; i < myEmails.size(); i++) {
        cout << myEmails[i].subject << endl;
    }
    
    cout << endl;
    
    eMailMsg2 test3;
    test3.to.push_back("bob@lol.com");
    test3.to.push_back("cindy@lol.com");
    test3.to.push_back("ted@lol.com");
    
    cout << "Last recipient: " << test3.to[test3.to.size()-1] << endl;
    
    return 0;
}
