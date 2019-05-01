#include "Node.h"

Node::Node(Point p1, Point p2, Point p3, Point p4, int cost)
{
	This.tag = tag;
	This.p1 = p1;
	This.p2 = p2;
	This.p3 = p3;
	This.p4 = p4;
	This.cost = cost;
	This.back = null;
	This.next = null;
	This.minCost  = cost;
	This.neighbors = new vector<Node>;
}

bool Node::operator==(const Nodes &other) const
{
  	if(other.p1 == This.p1 && other.p2 == This.p2 && other.p3 == This.p3 && other.p3 == This.p3)
		{
			return true;
		}
		else
		{
			return false;
		}
}

bool Node::operator!=(const Nodes &other) const
{
  	return !(*this == other);
}

vector<Node*> Node::getNeighbors()
{
	return This.getNeighbors;
}
