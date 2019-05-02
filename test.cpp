#include "Dstar.h"
#include "Matrix.h"
#include "Node.h"
#include "Point.h"

int main()
{
    Matrix matrix = Matrix("grid.csv");
    vector<Point> goal;
    goal.push_back(Point(0,0,0));
    goal.push_back(Point(0,1,0));
    goal.push_back(Point(1,0,0));
    goal.push_back(Point(1,1,0));
    matrix.setGoalLoc(goal);
    vector<Point> loc;
    loc.push_back(Point(10,10,0));
    loc.push_back(Point(10,11,0));
    loc.push_back(Point(11,10,0));
    loc.push_back(Point(11,11,0));
    matrix.setGoalLoc(goal);
    Dstar star = Dstar(&matrix);
    vector<Node> nodes = star.plan_path();
    for(Node node: nodes)
    {
        printf("%d, %d\n", node.getAvgPoint().getX(), node.getAvgPoint().getX());
    }
    
    return 0;
}