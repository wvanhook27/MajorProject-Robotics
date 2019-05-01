#include "Matrix.h"
#include "Dstar.h"

Dstar::Dstar(Matrix map)
{
	This.map = map;
	int** grid = map.getGrid();
	int numRow = sizeof(grid)/sizeof(grid[0]);
	int numCol = sizeof(grid[0])/sizeof(arr[0][0]);
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
			nodes.add(node);
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
}
