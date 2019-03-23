// CS106B: Programming Abstractions Assignment 4 Problem 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum pixelStateT { White, Black };

struct pointT {
	int row, col;
};

void fillRegion(pointT pt, vector<vector<pixelStateT> & screen) {
	if (screen[pt.row][pt.col] != Black) {
		screen[pt.row][pt.col] = Black;
		fillRegion(pt.row = +1, screen);
		fillRegion(pt.row = -1, screen);
		fillRegion(pt.col = +1, screen);
		fillRegion(pt.col = -1, screen);
	}
}

// displays a "screen" (2D vector of pixels) by printing to console
void printScreen(vector<vector<pixelStateT>> & screen) {
	for (int i = 0; i < screen.size(); i++) {
		for (int j = 0; j < screen[i].size(); j++) {
			if (screen[i][j] == Black)
				cout << "0";
			else
				cout << " ";
		}
		cout << endl;
	}
}

int main() {
	// initializing the testScreens with an image of a house
	vector<vector<pixelStateT> testScreen1;
	vector < vector<pixelStateT> testScreen2;

	// displaying the initial testScreen1
	printScreen(testScreen1);

	// filling in the door region of testScreen1
	pointT door;
	door.row = 5;
	door.col = 6;

	fillRegion(door, testScreen1);

	// displaying the testScreen1 with door region filled in
	printScreen(testScreen1);


	// displaying the initial testScreen2
	printScreen(testScreen2);

	// filling in the wall region of testScreen2
	pointT wall;
	wall.row = 12;
	wall.col = 7;

	fillRegion(wall, testScreen2);

	// displaying the testScreen2 with wall region filled in
	printScreen(testScreen2);
		
	return 0;
}