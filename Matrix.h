#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
	// constructor, pass in a filename(csv) with grid values
	Matrix(string filename);

	// update the orientation
	void updateOrientation(int direction);
	void updateOrientation(char turn);

	// update grid cell with new value
	void updateGrid(int x, int y, int val);

	// update the robot's location
	void updateRobotLoc(int direction);

	// get the orientation
	int getOrientation();

	// get the entire grid
	int** getGrid();

	// get the turtlebots current location
	void getRobotLoc(int& x, int&y);

	// simply returns the value in this cell
	int getValue(int x, int y);

	// display the grid as a visual aid to users
	void displayGrid();

	// functions for finding Cartesian and Manhattan distances
	double cartesian(int x1, int y1, int x2, int y2);
	double manhattan(int x1, int y1, int x2, int y2);

private:
	// matrix the grid/map will be stored in
	int** grid;

	// keep in memory the length and width for easy access
	int gridWidth;
	int gridLength;

	// store the orientation of the turtlebot
	int orientation;

	// helper function to retrieve length & width of map
	void findDim(string filename, int& length, int& width);
};

#endif