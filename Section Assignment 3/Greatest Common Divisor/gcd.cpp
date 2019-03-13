// CS106B: Programming Abstractions Assignment 3 Problem 6

#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

int main() {
    
    cout << "The greatest common divisor of " << 3 << " and " << 2 << " is " << gcd(3, 2) << endl;
    cout << "The greatest common divisor of " << 18 << " and " << 12 << " is " << gcd(18, 12) << endl;
    cout << "The greatest common divisor of " << 72 << " and " << 64 << " is " << gcd(72, 64) << endl;
    
    return 0;
}
