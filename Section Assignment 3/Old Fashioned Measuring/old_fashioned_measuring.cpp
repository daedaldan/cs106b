// CS106B: Programming Abstractions Assignment 3 Problem 7

#include <iostream>
#include <vector>

using namespace std;

bool isMeasurableHelper(int target, vector<int> weights, int left, int right) {
    if (left == right)
        return true;
    
    for (int i = 0; i < weights.size(); i++) {
        for (int j = 0; j < 2; j++) {
            vector<int>::iterator it = find(weights.begin(), weights.end(), weights[i]);
            int currentNum = weights[i];
            if (j == 0) {
                continue;
            } else if (j == 1) {
                left += weights[i];
            } else if (j == 2) {
                right += weights[i];
            }
            weights.erase(it);
            bool c = isMeasurableHelper(target, weights, left, right);
            if (c)
                return true;
            else
                weights.insert(it, currentNum);
        }
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
    
    if (isMeasurable(3, test1))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    return 0;
}

