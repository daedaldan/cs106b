// CSA06B: Programming Abstractions Assignment A Problem 3

#include <iostream>
#include <set>

using namespace std;

struct pairT {
    string first, second;
};

auto pairCmpFn = [] (pairT a, pairT b) { return a.first < b.first; };

set<pairT, decltype(pairCmpFn)> cartesianProduct(set<string> & one, set<string> & two) {
    set<pairT, decltype(pairCmpFn)> cartesianProducts(pairCmpFn);
    for (string s1 : one) {
        for (string s2 : two) {
            cout << s1 << " " << s2 << endl;
            pairT product;
            product.first = s1;
            product.second = s2;
            cartesianProducts.insert(product);
        }
    }
    
    return cartesianProducts;
}

int main() {
    set<string> testA;
    testA.insert("A");
    testA.insert("B");
    testA.insert("C");
    set<string> testB;
    testB.insert("X");
    testB.insert("Y");
    set<pairT, decltype(pairCmpFn)> testCartesianProducts = cartesianProduct(testA, testB);
    
    cout << "Elements of set A: " << endl;
    for (string s : testA) cout << s << endl;
    cout << endl;
    
    cout << "Elements of set B: " << endl;
    for (string s : testB) cout << s << endl;
    cout << endl;
    
    cout << "Cartesian products of sets A and B: " << endl;
    for (pairT p : testCartesianProducts) cout << "(" << p.first << ", " << p.second << ")" << endl;
    
    return 0;
}
