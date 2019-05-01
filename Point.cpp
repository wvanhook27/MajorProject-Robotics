#include "Point.h"

Node::Node(int x, int y, double value)
{
	This.x = x;
  This.y = y;
  This.value = value;
}

Node::setX(int newX)
{
  This.x = newX;
}

Node::setY(int newY)
{
  This.y = newY;
}

Node::setValue(double newValue)
{
  This.value = newValue;
}

Node::getX()
{
  return x;
}

Node::getY()
{
  return y;
}

Node::getValue()
{
  return value;
}
