using namespace std;

#ifndef POINT_H
#define POINT_H

class POINT {
public:
	// constructor, pass in a filename(csv) with grid values
	Point(double x, double y, double value);

	getX();
  getY();
  getValue();
  setX(double newX);
  setY(double newY);
  setValue(double newVal);

private:
	double x;
  double y;
  double value;
};

#endif
