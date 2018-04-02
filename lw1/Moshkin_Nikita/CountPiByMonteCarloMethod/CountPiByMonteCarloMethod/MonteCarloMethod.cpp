#include "stdafx.h"
#include "MonteCarloMethod.h"

UINT64 MonteCarloMethod::m_innerCount = 0;
UINT64 MonteCarloMethod::m_currentIterCount = 0;

MonteCarloMethod::MonteCarloMethod(size_t maxIterCount, size_t threadsCount)
{
	m_maxIterCount = maxIterCount;
	m_threadsCount = threadsCount;
	m_result = 0;
}

void MonteCarloMethod::Run() {
	srand(unsigned(time(NULL)));
	ThreadHandler threadHandler;
	threadHandler.PushThread(GeneratePointsInCircle, &m_maxIterCount);
	
	if (m_threadsCount > 1)
	{
		for (size_t i = 1; i < m_threadsCount; ++i) {
			threadHandler.PushThread(GeneratePointsInCircle, &m_maxIterCount);
		}
	}

	threadHandler.JoinAll();
	CountPI();
}

MonteCarloMethod::~MonteCarloMethod()
{
}

void MonteCarloMethod::IncrementInnerCount() 
{
	InterlockedIncrement(&m_innerCount);
}

void MonteCarloMethod::IncrementCurrentIterCount() 
{
	InterlockedIncrement(&m_currentIterCount);
}

DWORD WINAPI GeneratePointsInCircle(LPVOID lpParam) 
{
	CustomRandom random;
	int *maxIterCount = (int*)lpParam;
	const int maxCount = *maxIterCount;

	for (;MonteCarloMethod::GetCurrentIterCount() < maxCount;) 
	{
		Point randomPoint = random.GenerateRandomPoint(CIRCLE_RADIUS);

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
	m_result = ((4. * MonteCarloMethod::GetInnerCount()) / m_maxIterCount);
}

double MonteCarloMethod::GetResult()
{
	return m_result;
}