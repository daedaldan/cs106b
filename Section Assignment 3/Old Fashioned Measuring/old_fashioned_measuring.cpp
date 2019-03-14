// CS106B: Programming Abstractions Assignment 3 Problem 7

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMeasurableHelper(int target, vector<int> weights, int left, int right) {
    if (left == right)
        return true;
    
    for (int i = 0; i < weights.size(); i++) {
        int currentWeight = weights[i];
        vector<int>::iterator it = find(weights.begin(), weights.end(), weights[i]);
        weights.erase(it);
        if (isMeasurableHelper(target, weights, left, right)) return true;
        if (isMeasurableHelper(target, weights, left + currentWeight, right)) return true;
        if (isMeasurableHelper(target, weights, left, right + currentWeight)) return true;
        weights.insert(it, currentWeight);
        }
    
    return false;
}

bool isMeasurable(int target, vector<int> & weights) {
    return isMeasurableHelper(target, weights, target, 0);
}

int main() {
    vector<int> testWeights;
    testWeights.push_back(1);
    testWeights.push_back(3);
    
    // printing results of test 1
    int testNum1 = 2;
    if (isMeasurable(testNum1, testWeights))
        cout << testNum1 << " can be measured with the weights: " << endl;
    else
        cout << testNum1 << " cannot be measured with the weights: " << endl;
    
    for (int i = 0; i < testWeights.size(); i++) {
        cout << testWeights[i] << endl;
    }
    
    cout << endl;
    
    // printing results of test 2
    int testNum2 = 5;
    if (isMeasurable(testNum2, testWeights))
        cout << testNum2 << " can be measured with the weights: " << endl;
    else
        cout << testNum2 << " cannot be measured with the weights: " << endl;
    
    for (int i = 0; i < testWeights.size(); i++) {
        cout << testWeights[i] << endl;
    }
    
    return 0;
}

