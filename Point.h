using namespace std;

#ifndef POINT_H
#define POINT_H

class POINT {
public:
	// constructor, pass in a filename(csv) with grid values
	Point(int x, int y, double value);

	getX();
  getY();
  getValue();
  setX(int newX);
  setY(int newY);
  setValue(double newVal);

private:
	int x;
  int y;
  double value;
};

#endif
