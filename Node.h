#include <string>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
public:
	// constructor, pass in a filename(csv) with grid values
	Node(string tag);

	string getTag();


private:
	string tag;
};

#endif
