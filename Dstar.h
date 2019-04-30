#include <string>
#include "Node.h"
#include "Matrix.h"

using namespace std;

#ifndef Dstar_H
#define Dstar_H

class Dstar {
public:
	Dstar(Matrix map);

private:
	void prepare_repair(Node O, Node L, Node Xc);
	void insert(Node O, Node X, Node hnew);
	void modify_cost(Node O, Node, X, Node Y, int cval);
	void init_plan(Node O, Node L, Node Xc, Node G);
	void repair_replan(Node O, Node L, Node Xc, Node G);
	void process_state();

	Matrix map;
};

#endif
