// CS106B: Programming Abstractions Assignment 1 Problem 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct exam_stats {
    double min;
    double max;
    double average;
};

exam_stats calcExamStats(string filename) {
    exam_stats myStats;
    myStats.min = 101.0;
    myStats.max = -1.0;
    myStats.average = -1.0;
    
    double total = 0.0;
    int numScores = 0;
    
    ifstream examScores(filename.c_str());
    string score;
    while (getline(examScores, score)) {
        cout << "Score: " << score << endl;
        if (stod(score) > myStats.max) myStats.max = stod(score);
        if (stod(score) < myStats.min) myStats.min = stod(score);
        total += stod(score);
        numScores += 1;
    }
    examScores.close();
    
    myStats.average = total / numScores;
    
    return myStats;
}

int main() {
    exam_stats test1 = calcExamStats("exam_scores.txt");
    
    cout << "Highest score: " << test1.max << endl;
    cout << "Lowest score: " << test1.min << endl;
    cout << "Average score: " << test1.average << endl;
    
    return 0;
}
