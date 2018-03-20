#pragma once
class Point
{
public:
	Point();
	Point(double x, double y);
	~Point();
	double getX();
	double getY();
	bool inCircle(int circleRadius);
private:
	double x;
	double y;
};

