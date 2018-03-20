#include "stdafx.h" 
#include "Point.h"
#include "CustomRandom.h"

#define MAX_INNER_COUNT 1E6
#define CIRCLE_RADIUS 1

using namespace std;

double countPI(double innerCount, double maxInnerCount);
double monteCarloMethod(int maxInnerCount);

int main(int argc, char* argv[])
{
	double PI;
	if (argc < 2) {
		cout << "Error of arguments count" << endl;
		return 1;
	}

	int maxInnerCount = atoi(argv[1]);

	clock_t startWork = clock();

	PI = monteCarloMethod(maxInnerCount);

	clock_t endWork = clock();

	float workTime = (float)(endWork - startWork) / CLOCKS_PER_SEC;

	cout << "Number of PI: " << PI << endl;
	cout << "Time of work: " << workTime << endl;
	return 0;
}

double countPI(double innerCount, double maxInnerCount) {
	return (4 * innerCount) / maxInnerCount;
}

double monteCarloMethod(int maxInnerCount) {
	CustomRandom random;
	Point randomPoint = Point();
	srand(unsigned(time(NULL)));
	
	int innerCount = 0;
	for (int i = 0; i < maxInnerCount; ++i) {
		randomPoint = random.GenerateRandomPoint(CIRCLE_RADIUS);
		if (randomPoint.inCircle(CIRCLE_RADIUS)) {
			++innerCount;
		}
	}
	return(countPI(innerCount, maxInnerCount));

}