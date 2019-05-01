#include <string>
#include "Node.h"
#include "Matrix.h"

using namespace std;

#ifndef Dstar_H
#define Dstar_H

class Dstar {
public:
	Dstar(Matrix map);
	update()

private:
	void expand(Node currentPoint);
	boolean isRaise(Node point);
	list<Node> openList;
	list<Node> nodes;
	Matrix map;
};

#endif
