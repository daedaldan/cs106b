// CS106B: Programming Abstractions Assignment 2 Problem 5

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> makeGridOfCounts(vector<vector<bool>> & bombLocations) {
    vector<int> row(9, 0);
    vector<vector<int>> counts(9, row);
    
    for (int i = 0; i < counts.size(); i++) {
        for (int j = 0; j < counts[i].size(); j++) {
            int bombs = 0;

            /* if on top left */ if (i == 0 && j == 0) {
                for (int x = i; x <= i + 1; x++) {
                    for (int y = j; y <= j + 1; y++) {
                        if (bombLocations[x][y]) bombs += 1;
                    }
                }
            } /* if on top right */ else if (i == 0 && (j == counts[i].size() - 1)) {
                for (int x = i - 1; x <= i; x++) {
                    for (int y = j; y <= j + 1; y++) {
                        if (bombLocations[x][y]) bombs += 1;
                    }
                }
            } /* if on bottom left */ else if ((i == counts.size() - 1) && j == 0) {
                for (int x = i - 1; x <= i; x++) {
                    for (int y = j; y <= j + 1; y++) {
                        if (bombLocations[x][y]) bombs += 1;
                    }
                }
            } /* if on bottom right */ else if ((i == counts.size() - 1) && (j == counts.size() - 1)) {
                for (int x = i - 1; x <= i; x++) {
                    for (int y = j - 1; y <= j; y++) {
                        if (bombLocations[x][y]) bombs += 1;
                    }
                }
            } /* if in middle */ else {
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (bombLocations[x][y]) bombs += 1;
                    }
                }
            }
            
            counts[i][j] = bombs;
        }
    }
    
    return counts;
}

int main() {
    vector<bool> row(9, true);
    vector<vector<bool>> testMinesweeper(9, row);
    vector<vector<int>> testCounts = makeGridOfCounts(testMinesweeper);
    
    // printing grid of counts
    for (int i = 0; i < testCounts.size(); i++) {
        for (int j = 0; j < testCounts[i].size(); j++) {
            cout << testCounts[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
