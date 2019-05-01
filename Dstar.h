#include <string>
#include <vector>
#include <map>
#include "Node.h"
#include "Matrix.h"
#include "Point.h"

using namespace std;

#ifndef Dstar_H
#define Dstar_H

class Dstar {
public:
	Dstar(Matrix map);
	std::vector<Node> plan_path();

private:
	std::vector<Node*> nodes;
	double dist_between(Node i, Node j);
	Matrix map;
	bool compFunction(Node i, Node j);
	std::vector<Node> reconstruct_path(std::map<Node*, Node*> cameFrom, Node current);
	int where(std::vector<Node> v, Node node)
	Node start;
	Node goal;
};

#endif
