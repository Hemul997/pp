#include "stdafx.h" 
#include "Point.h"
#include "CustomRandom.h"
#include "MonteCarloMethod.h"

#define CIRCLE_RADIUS 1

using namespace std;

int main(int argc, char* argv[])
{
	double PI;
	
	if (argc < 3) {
		cout << "Error of arguments count" << endl;
		return 1;
	}

	int maxInnerCount = atoi(argv[1]);
	int threadsCount = atoi(argv[2]);

	clock_t startWork = clock();
	MonteCarloMethod monteCarlo = MonteCarloMethod(maxInnerCount, 4);
	monteCarlo.Run();
	PI = monteCarlo.GetPI();

	clock_t endWork = clock();

	float workTime = (float)(endWork - startWork) / CLOCKS_PER_SEC;

	cout << "Number of PI: " << PI << endl;
	cout << "Time of work: " << workTime << endl;
	return 0;
}