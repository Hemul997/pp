#include "stdafx.h"
#include "CustomRandom.h"


double CustomRandom::GenerateRandomNumber(double maxValue, double minValue)
{
	double random = (double)rand() / RAND_MAX * maxValue - minValue;
	return random;
}

Point CustomRandom::GenerateRandomPoint(int radius)
{
	int squireSize = radius * 2;
	Point point = Point(GenerateRandomNumber(squireSize, radius), GenerateRandomNumber(squireSize, radius));
	return point;
}
