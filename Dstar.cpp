#include "Dstar.h"

Dstar::Dstar(Matrix map)
{
	This.map = map;
	int** grid = map.getGrid();
	int numRow = sizeof(grid)/sizeof(grid[0]);
	int numCol = sizeof(grid[0])/sizeof(arr[0][0]);
	std::vector<Point> robotLoc = map.getRobotLoc();
	std::vector<Point> goalLoc = map.getgoalLoc();
	start = new Node(robotLoc.at(0), robotLoc.at(1), robotLoc.at(2), robotLoc.at(3));
	goal = new Node(goalLoc.at(0), goalLoc.at(1), goalLoc.at(2), goalLoc.at(3));

	for(int i = 0; i < numRow-1; i++)
	{
		for int j = 0; j < numCol-1; j++)
		{
			int val = 0;
			if(min(grid[i,j], min(grid[i+1,j], min(grid[i,j+1], min(grid[i+1,j+1])))))
			{
				val = 100000;
			}
			Node node = new Node(new Point[i, j, grid[i,j]],
													new Point[i+1, j, grid[i+1,j]],
													new Point[i, j+1, grid[i,j+1]],
													new Point[i+1, j+1, grid[i+1,j+1]],
												val);
			if(node == start)
			{
				nodes.insert(&start);
			}
			else if(node == goal)
			{
				nodes.insert(&goal);
			}
			else
			{
				nodes.insert(&node);
			}
		}
	}
	for(Node* node1 : nodes)
	{
		for(Node* node2 : nodes)
		{
			if(node1.isNeighbor(*node2))
			{
				node1.addNeighbor(node2);
			}
		}
	}
}

int Dstar::where(std::vector<Node> v, Node* node)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(node == v.at(i))
		{
			return i;
		}
	}
	return -1;
}

std::vector<Node> Dstar::reconstruct_path(std::map<Node*, Node*> cameFrom, Node* current)
{
	std::vector<Node> total_path = new std::vector<Node>;
	total_path.insert(*current);
	while(cameFrom.count(current) > 0)
	{
	    current = cameFrom[current];
	    total_path.push_back(*current);
	}
	return total_path;
}

std::vector<Node> Dstar::plan_path()
{
		double distance = -start.getAvgPoint().getX() + goal.getAvgPoint().getX() - start.getAvgPoint().getY() + goal.getAvgPoint().getY();

		std::map<Node*, Node*> cameFrom;

		std::map<Node*, double> gScore;
		gScore[&start] = 0;

		std::map<Node*, double> fScore;
		fScore[&start] = distance;

		std::vector<Node*> openSet = new std::vector<Node*>;
		openSet.insert(&start);

		std::vector<Node*> closedSet = new std::vector<Node*> v;

		while(openSet.size() > 0)
		{
			Node* current = lowest(openSet);
			if(current == goal)
			{
				return reconstruct_path(cameFrom, current);
			}
			openSet.erase(where(openSet, current));
			closedSet.insert(current);

			for(neighbor : current.getNeighbors)
			{
				 if(where(closedSet, neighbor))
				 {
						 break;		// Ignore the neighbor which is already evaluated.
				 }

				 // The distance from start to a neighbor
				 double tentative_gScore = gScore[current] + dist_between(current, neighbor) + (*neighbor).getCost();

				 if(!where(openSet, neighbor))	// Discover a new node
				 {
						 openSet.push_back(neighbor);
				 }
				 else if (tentative_gScore >= gScore[neighbor])
				 {
					 break;
				 }

				 // This path is the best until now. Record it!
				 cameFrom[neighbor] = current;
				 gScore[neighbor] = tentative_gScore;
				 fScore[neighbor] = gScore[neighbor] + dist_between(neighbor, goal);
			 }
		}
}

Node* lowest(std::vector<Node*> openSet, std::map<Node*, double> fScore)
{
	int lowestVal = 100000;
	Node* lowest = openSet.at(0);
	for(Node* node: openSet)
	{
		if (fScore[node] < fScore[lowest]) {
			lowest = node;
		}
	}
	return lowest;
}

double dist_between(Node* node1, Node* node2)
{
	Point point1 = (*node1).getAvgPoint();
	Point point2 = (*node2).getAvgPoint();
	return abs(point1.getX() - point2.getX()) + abs(point1.getY() - point2.getY());
}
