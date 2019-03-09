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
                for (int y = i; y <= i + 1; y++) {
                    for (int x = j; x <= j + 1; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if on top right */ else if (i == 0 && (j == counts[i].size() - 1)) {
                for (int y = i; y <= i + 1; y++) {
                    for (int x = j - 1; x <= j; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if on bottom left */ else if ((i == counts.size() - 1) && j == 0) {
                for (int y = i - 1; y <= i; y++) {
                    for (int x = j; x <= j + 1; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if on bottom right */ else if ((i == counts.size() - 1) && (j == counts.size() - 1)) {
                for (int y = i - 1; y <= i; y++) {
                    for (int x = j - 1; x <= j; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if on top */ else if (i == 0) {
                for (int y = i; y <= i + 1; y++) {
                    for (int x = j - 1; x <= j + 1; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if on bottom */ else if (i == counts.size() - 1) {
                for (int y = i - 1; y <= i; y++) {
                    for (int x = j - 1; x <= j + 1; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if on left */ else if (j == 0) {
                for (int y = i - 1; y <= i + 1; y++) {
                    for (int x = j; x <= j + 1; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if on right */ else if (j == counts.size() - 1) {
                for (int y = i - 1; y <= i + 1; y++) {
                    for (int x = j - 1; x <= j; x++) {
                        if (bombLocations[y][x]) bombs += 1;
                    }
                }
            } /* if in middle */ else {
                for (int y = i - 1; y <= i + 1; y++) {
                    for (int x = j - 1; x <= j + 1; x++) {
                        if (bombLocations[y][x]) bombs += 1;
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
    testMinesweeper[0][0] = false;
    // printing Minesweeper grid
    cout << "Minesweeper Grid: " << endl;
    for (int i = 0; i < testMinesweeper.size(); i++) {
        for (int j = 0; j < testMinesweeper[i].size(); j++) {
            if (testMinesweeper[i][j]) cout << "True  ";
            else cout << "False ";
        }
        cout << endl;
    }
    cout << endl;
    
    // printing grid of counts
    vector<vector<int>> testCounts = makeGridOfCounts(testMinesweeper);
    cout << "Grid of Counts: " << endl;
    for (int i = 0; i < testCounts.size(); i++) {
        for (int j = 0; j < testCounts[i].size(); j++) {
            cout << testCounts[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
