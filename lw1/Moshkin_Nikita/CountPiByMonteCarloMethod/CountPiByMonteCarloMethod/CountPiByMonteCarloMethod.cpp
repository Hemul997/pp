#include "stdafx.h" 

#define MAX_INNER_COUNT 1E6
#define CIRCLE_RADIUS 1

using namespace std;

bool inCircle(double x, double y);
double countPI(double innerCount);
double generateRandomNumber();

int main(int argc, char* argv[])
{
	double x, y, PI;
	int innerCount = 0;

	srand(unsigned(time(NULL)));

	clock_t startWork = clock();

	for (int i = 0; i < (int)MAX_INNER_COUNT; ++i) {
		x = generateRandomNumber();
		y = generateRandomNumber();
		if (inCircle(x, y)) {
			innerCount++;
		}
	}
	PI = countPI(innerCount);

	clock_t endWork = clock();

	float workTime = (float)(endWork - startWork) / CLOCKS_PER_SEC;

	cout << "Number of PI: " << PI << endl;
	cout << "Time of work: " << workTime << endl;
}

double generateRandomNumber() {
	
	double random = (double)rand() / (RAND_MAX + CIRCLE_RADIUS) * (CIRCLE_RADIUS - 0) + 0;
	return random;
}

bool inCircle(double x, double y) {
	return (pow(x, 2) + pow(y, 2)) < pow(CIRCLE_RADIUS, 2);
}

double countPI(double innerCount) {
	return (4 * innerCount) / MAX_INNER_COUNT;
}