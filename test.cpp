#include "Dstar.h"
#include "Matrix.h"
#include "Node.h"
#include "Point.h"

int main()
{
    Matrix matrix = Matrix("grid.csv");
    vector<Point> goal;
    goal.push_back(Point(6,1,0));
    goal.push_back(Point(7,1,0));
    goal.push_back(Point(6,2,0));
    goal.push_back(Point(7,2,0));
    matrix.setGoalLoc(goal);
    vector<Point> loc;
    loc.push_back(Point(22,1,0));
    loc.push_back(Point(23,1,0));
    loc.push_back(Point(22,2,0));
    loc.push_back(Point(23,2,0));
    matrix.setRobotLoc(loc);
    Dstar star = Dstar(&matrix);
    vector<Node> nodes = star.plan_path();
    for(Node node: nodes)
    {
        printf("%lf, %lf\n", node.getAvgPoint().getX(), node.getAvgPoint().getY());
		matrix.updateGrid(node.getP1().getX(), node.getP1().getY(), 1);
		matrix.updateGrid(node.getP2().getX(), node.getP2().getY(), 1);
		matrix.updateGrid(node.getP3().getX(), node.getP3().getY(), 1);
		matrix.updateGrid(node.getP4().getX(), node.getP4().getY(), 1);
    }
	matrix.displayGrid();
    
    return 0;
}