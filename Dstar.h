#include <string>
#include "Node.h"
#include "Matrix.h"

using namespace std;

#ifndef Dstar_H
#define Dstar_H

class Dstar {
public:
	Dstar(Matrix map);
	update();

private:
	void expand(Node currentPoint);
	boolean isRaise(Node point);
	vector<Node*> openSet;
	vector<Node*> closedSet;
	vector<Node*> nodes;
	double dist_between(Node i, Node j);
	Matrix map;
	bool compFunction(Node i, Node j);
};

#endif
