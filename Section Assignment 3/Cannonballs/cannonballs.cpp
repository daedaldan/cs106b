// CS106B: Programming Abstractions Assignment 3 Problem 4

#include <iostream>

using namespace std;

int cannonball(int height) {
    if (height < 0)
        return -1;
    if (height == 0)
        return 0;
    if (height == 1)
        return 1;
    else
        return height * height + cannonball(height - 1);
}

int main() {
    cout << "A stack of cannonballs with height " << 0 << " has " << cannonball(0) << " cannonballs." << endl;
    cout << "A stack of cannonballs with height " << 1 << " has " << cannonball(1) << " cannonballs." << endl;
    cout << "A stack of cannonballs with height " << 2 << " has " << cannonball(2) << " cannonballs." << endl;
    cout << "A stack of cannonballs with height " << 4 << " has " << cannonball(4) << " cannonballs." << endl;
    cout << "A stack of cannonballs with height " << 7 << " has " << cannonball(7) << " cannonballs." << endl;

    return 0;
}
