#include "stdafx.h"
#include "MonteCarloMethod.h"


MonteCarloMethod::MonteCarloMethod(int maxInnerCount, int threadsCount)
{
	m_maxInnerCount = maxInnerCount;
	m_threadsCount = threadsCount;
	m_result = 0;
}

void MonteCarloMethod::Run() {
	ThreadHandler threadHandler;
	threadHandler.PushThread(GeneratePointsInCircle, &m_maxInnerCount);
	srand(unsigned(time(NULL)));
	if (m_threadsCount > 1)
	{
		for (int i = 1; i < m_threadsCount; ++i) {
			threadHandler.PushThread(GeneratePointsInCircle, &m_maxInnerCount);
		}
	}
	
	threadHandler.JoinAll();
	
	CountPI();
}

MonteCarloMethod::~MonteCarloMethod()
{
}
UINT64 m_innerCount = 0;
UINT64 m_currentIterCount = 0;

void MonteCarloMethod::IncrementInnerCount() 
{
	InterlockedIncrement(&m_innerCount);
}

void MonteCarloMethod::IncrementCurrentIterCount() 
{
	InterlockedIncrement(&m_currentIterCount);
}

DWORD WINAPI GeneratePointsInCircle(LPVOID maxInnerCount) 
{
	CustomRandom random;
	int *param = (int*)maxInnerCount;
	const int maxCount = *param;
	Point randomPoint = Point();

	for (;MonteCarloMethod::GetCurrentIterCount() < maxCount;) 
	{
		randomPoint = random.GenerateRandomPoint(CIRCLE_RADIUS);

		if (randomPoint.inCircle(CIRCLE_RADIUS)) 
		{
			MonteCarloMethod::IncrementInnerCount();
		}

		MonteCarloMethod::IncrementCurrentIterCount();
	}
	return 0;
}

UINT64 MonteCarloMethod::GetInnerCount()
{
	return m_innerCount;
}

UINT64 MonteCarloMethod::GetCurrentIterCount()
{
	return m_currentIterCount;
}

void MonteCarloMethod::CountPI()
{
	m_result = (double)((4. * MonteCarloMethod::GetInnerCount()) / m_maxInnerCount);
}

double MonteCarloMethod::GetPI() 
{
	return m_result;
}