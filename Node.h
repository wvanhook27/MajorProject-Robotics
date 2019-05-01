#include <string>
#include <iterator>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
public:
	// constructor, pass in a filename(csv) with grid values
	Node(Point p1, Point p2, Point p3, Point p4, int cost);

	list<Node> getNeighbors();
	Node nextPoint;
	void setNextPointAndUpdateCost(Node point);
	void calculateCostVia(Node point);
	double getCost();
	void setMinimumCostToCurrentCost();
	void addNeighbor();
	boolean isNeighbor(Node possibleNeighbor);
	void setBackPointer(Node* backPointer);
	Node* getBackPointer();

private:
	list<Node*> neighbors;
	Node* backPointer;
	Point p1;
	Point p2;
	Point p3;
	Point p4;
	int cost;
	int minCost;
};

#endif
