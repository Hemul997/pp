#include "stdafx.h" 
#include "MonteCarloMethod.h"


using namespace std;

const string helpMessage = "Use <CountPiByMonteCarloMethod.exe> <iterations count>";
const string errorMessage = "Error of arguments! Use <CountPiByMonteCarloMethod.exe> --help to find startup parameters";

int main(int argc, char* argv[])
{

	if (argc != 2) {
		cout << errorMessage << endl;
		return 1;
	} else
		if (string(argv[1]) == "--help") {
			cout << helpMessage << endl;
			return 0;
		}

	size_t maxIterCount = atoi(argv[1]);

	clock_t startWork = clock();
	MonteCarloMethod monteCarlo = MonteCarloMethod(maxIterCount);
	monteCarlo.Run();
	double PI = monteCarlo.GetResult();

	clock_t endWork = clock();

	float workTime = (float)(endWork - startWork) / CLOCKS_PER_SEC;

	cout << "Number of PI: " << PI << endl;
	cout << "Time of work: " << workTime << endl;
	return 0;
}