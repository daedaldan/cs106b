// CS106B: Programming Abstractions Assignment 4 Problem 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum pixelStateT { White, Black };

struct pointT {
	int row, col;
};

// draws a house on the "screen" (2D vector of pixels) passed in
void drawHouse(vector<vector<pixelStateT>> & screen) {
	// wipes the vector passed in, creating a "blank canvas"
	pixelStateT whitePixel = White;
	vector<pixelStateT> emptyRow(19, whitePixel);
	vector<vector<pixelStateT>> emptyScreen(24, emptyRow);
	screen.clear();
	screen = emptyScreen;
	// drawing base
	for (int i = 0; i < 19; i++)
		screen[23][i] = Black;
	// drawing left wall
	for (int i = 23; i > 8; i--)
		screen[i][0] = Black;
	// drawing right wall
	for (int i = 23; i > 8; i--)
		screen[i][18] = Black;
	// drawing left side of door
	for (int i = 23; i > 15; i--)
		screen[i][7] = Black;
	// drawing right side of door
	for (int i = 23; i > 15; i--)
		screen[i][11] = Black;
	// drawing top of door
	for (int i = 7; i < 12; i++)
		screen[16][i] = Black;
	// drawing left side of roof
	int row = 8;
	int col = 1;
	while (row > -1 && col < 10) {
		screen[row][col] = Black;
		row -= 1;
		col += 1;
	}
	row = 8;
	col = 18;
	while (row > -1 && col > 9) {
		screen[row][col] = Black;
		row -= 1;
		col -= 1;
	}
}

// displays a "screen" (2D vector of pixels) by printing to console
void printScreen(vector<vector<pixelStateT>> & screen) {
	for (int i = 0; i < screen.size(); i++) {
		for (int j = 0; j < screen[i].size(); j++) {
			if (screen[i][j] == Black)
				cout << "0  ";
			else
				cout << "   ";
		}
		cout << endl;
	}
}

void fillRegion(pointT pt, vector<vector<pixelStateT>> & screen) {
	cout << "At " << pt.row << ", " << pt.col << endl;
	if (screen[pt.row][pt.col] != Black) {
		screen[pt.row][pt.col] = Black;
		pointT upPt;
		upPt.row = pt.row + 1;
		upPt.col = pt.col;
		fillRegion(upPt, screen);
		pointT downPt;
		downPt.row = pt.row - 1;
		downPt.col = pt.col;
		fillRegion(downPt, screen);
		pointT rightPt;
		rightPt.row = pt.row;
		rightPt.col = pt.col + 1;
		fillRegion(rightPt, screen);
		pointT leftPt;
		leftPt.row = pt.row;
		leftPt.row = pt.col - 1;
		fillRegion(leftPt, screen);
	}
}

int main() {
	// initializing the testScreens with an image of a house
	vector<vector<pixelStateT>> testScreen1;
	drawHouse(testScreen1);
	vector<vector<pixelStateT>> testScreen2;
	drawHouse(testScreen2);
	// displaying the initial testScreen1
	printScreen(testScreen1);
	cout << 1 << endl;

	// filling in the door region of testScreen1
	pointT door;
	door.row = 20;
	door.col = 8;

	fillRegion(door, testScreen1);

	// displaying the testScreen1 with door region filled in
	printScreen(testScreen1);
	cout << 2 << endl;

	// displaying the initial testScreen2
	printScreen(testScreen2);
	cout << 3 << endl;
	// filling in the wall region of testScreen2
	pointT wall;
	wall.row = 12;
	wall.col = 7;

	// fillRegion(wall, testScreen2);

	// // displaying the testScreen2 with wall region filled in
	// printScreen(testScreen2);
		
	return 0;
}