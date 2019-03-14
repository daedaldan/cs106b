// CS106B: Programming Abstractions Assignment 3 Problem 7

#include <iostream>
#include <vector>

using namespace std;

bool isMeasurableHelper(int target, vector<int> weights, int left, int right) {
    cout << left << ", " << right << endl;
    if (left == right)
        return true;
    
    for (int i = 0; i < weights.size(); i++) {
        int currentWeight = weights[i];
        cout << "Current weight is: " << currentWeight << endl;
        vector<int>::iterator it = find(weights.begin(), weights.end(), weights[i]);
        weights.erase(it);
        if (isMeasurableHelper(target, weights, left, right)) return true;
        if (isMeasurableHelper(target, weights, left += currentWeight, right)) return true;
        if (isMeasurableHelper(target, weights, left, right += currentWeight)) return true;
        weights.insert(it, currentWeight);
        }
    
    return false;
}

bool isMeasurable(int target, vector<int> & weights) {
    return isMeasurableHelper(target, weights, target, 0);
}

int main() {
    vector<int> test1;
    test1.push_back(1);
    test1.push_back(3);
    
    if (isMeasurable(2, test1))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    return 0;
}

