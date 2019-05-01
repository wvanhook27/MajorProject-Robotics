#include "Matrix.h"
#include "Dstar.h"

Dstar::Dstar(Matrix map)
{
	This.map = map;
	int** grid = map.getGrid();
	int numRow = sizeof(grid)/sizeof(grid[0]);
	int numCol = sizeof(grid[0])/sizeof(arr[0][0]);
	Point* robotLoc = map.getRobotLoc();
	Node start = new Node(robotLoc[0], robotLoc[1], robotLoc[2], robotLoc[3], 0);
	Node goal = new Node(goalLoc[0], goalLoc[1], goalLoc[2], goalLoc[3], 0);
	double distance = -start.getAvgPoint().getX() + goal.getAvgPoint().getX() - start.getAvgPoint().getY() + goal.getAvgPoint().getY();

	openSet = new vector<Node>;
	closedSet = new vector<Node>;
	openSet.insert(start);

	Map<Node*, Node*> cameFrom;

	Map<Node*, double> gScore;
	gScore[&start] = 0;

	Map<Node*, double> fScore;
	fScore[&start] = distance;

	for(int i = 0; i < numRow-1; i++)
	{
		for int j = 0; j < numCol-1; j++)
		{
			int val = min(grid[i,j], min(grid[i+1,j], min(grid[i,j+1], grid[i+1,j+1])));
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
	for(Node node1 : nodes)
	{
		for(Node node2 : nodes)
		{
			if(node1.isNeighbor(node2))
			{
				node1.addNeighbor(node2);
			}
		}
	}

	openSet = new vector<Node*>;
	openSet.insert(&start);

	closedSet = new std::vector<Node*> v;

	while(openSet.size() > 0)
	{
		Node* current = openSet.at(0);
		if(current == goal)
		{
			return reconstruct_path(cameFrom, current); //TODO
		}
		openSet.erase(where(openSet, current)); //TODO
		closedSet.insert(current);

		for(neighbor : current.getNeighbors)
		{
			 if(where(closedSet, neighbor))
			 {
					 break;		// Ignore the neighbor which is already evaluated.
			 }

			 // The distance from start to a neighbor
			 double tentative_gScore = gScore[current] + dist_between(current, neighbor);

			 if(!where(openSet, neighbor))	// Discover a new node
			 {
					 openSet.insert(neighbor)
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

bool compFunction(Node i, Node j)
{
	return i.getCost < j.getCost;
}

int where(std::vector<Node> v, Node node)
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
