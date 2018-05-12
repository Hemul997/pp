#include "stdafx.h"
#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

bool Point::inCircle(int circleRadius)
{
	return((pow(x, 2) + pow(y, 2)) < pow(circleRadius, 2));
}


Point::~Point()
{
}

