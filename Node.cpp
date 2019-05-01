#include "Node.h"

Node::Node(Point* point1, Point* point2, Point* point3, Point* point4, int val)
{
	p1 = point1;
	p2 = point2;
	p3 = point3;
	p4 = point4;
	cost = val;
}

bool Node::operator==(const Node &other) const
{
  	if(other.p1 == p1 && other.p2 == p2 && other.p3 == p3 && other.p3 == p3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Node::addNeighbor(Node* neighbor)
{
	neighbors.push_back(neighbor);
}

bool Node::isNeighbor(Node* possibleNeighbor)
{
	bool p1b = *p1 == (*possibleNeighbor).getP1();
	bool p2b = *p2 == (*possibleNeighbor).getP2();
	bool p3b = *p3 == (*possibleNeighbor).getP3();
	bool p4b = *p4 == (*possibleNeighbor).getP4();
	if(p1b && p2b && p3b && p4b)
	{
		return false;
	}
	else if ((p1b && p2b) || (p1b && p3b) || (p1b && p4b)) {
		return true;
	}
	else if((p2b && p3b) || (p2b && p4b))
	{
		return true;
	}
	else if (p3b && p4b) {
		return true;
	}
	else
	{
		return false;
	}
}

Point Node::getP1()
{
	return *p1;
}

Point Node::getP2()
{
	return *p2;
}

Point Node::getP3()
{
	return *p3;
}

Point Node::getP4()
{
	return *p4;
}

vector<Node*> Node::getNeighbors()
{
		return neighbors;
}

Point Node::getAvgPoint()
{
	double avgX = ((*p1).getX() + (*p2).getX() + (*p3).getX() + (*p4).getX())/4;
	double avgY = ((*p1).getY() + (*p2).getY() + (*p3).getY() + (*p4).getY())/4;
	Point* point = new Point(avgX, avgY, 0);
	return *point;
}

int Node::getCost()
{
	return cost;
}
