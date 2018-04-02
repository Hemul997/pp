#include "stdafx.h" 
#include "MonteCarloMethod.h"

#define CIRCLE_RADIUS 1

using namespace std;

const string helpMessage = "Use <CountPiByMonteCarloMethod.exe> <iterations count> <threads count>";
const string errorMessage = "Error of arguments! Use <CountPiByMonteCarloMethod.exe> --help to find startup parameters";

int main(int argc, char* argv[])
{
	if ((argc == 2 && string(argv[1]) == "--help")) 
	{
		cout << helpMessage << endl;
		return 0;
	}

	if (argc < 3) {
		cout << errorMessage << endl;
		return 1;
	}

	size_t maxIterCount = atoi(argv[1]);
	size_t threadsCount = atoi(argv[2]);

	clock_t startWork = clock();
	MonteCarloMethod monteCarlo = MonteCarloMethod(maxIterCount, threadsCount);
	monteCarlo.Run();
	double PI = monteCarlo.GetResult();

	clock_t endWork = clock();

	float workTime = (float)(endWork - startWork) / CLOCKS_PER_SEC;

	cout << "Number of PI: " << PI << endl;
	cout << "Time of work: " << workTime << endl;
	return 0;
}