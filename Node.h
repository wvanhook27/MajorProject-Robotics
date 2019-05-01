#include <string>
#include <iterator>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
public:
	// constructor, pass in a filename(csv) with grid values
	Node(Point p1, Point p2, Point p3, Point p4, int cost);

	vector<Node*> getNeighbors();
	void setNextPointAndUpdateCost(Node node);
	void calculateCostVia(Node node);
	int getCost();
	int getMinCost();
	void setMinimumCostToCurrentCost();
	void addNeighbor(Node* node);
	boolean isNeighbor(Node possibleNeighbor);
	Node* getBackPointer();
	void setBackPointer(Node* backPointer);
	bool operator==(const Node &other) const;
	Point avgPoint();

private:
	vector<Node*> neighbors;
	Node* back;
	Node* next;
	Point p1;
	Point p2;
	Point p3;
	Point p4;
	int cost;
	int minCost;
};

#endif
