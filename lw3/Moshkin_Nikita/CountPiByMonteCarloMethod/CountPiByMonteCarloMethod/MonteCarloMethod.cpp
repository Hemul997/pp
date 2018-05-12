#include "stdafx.h"
#include "Point.h"
#include "CustomRandom.h"
#include "MonteCarloMethod.h"

const int CIRCLE_RADIUS = 1;

size_t MonteCarloMethod::m_innerCount = 0;

MonteCarloMethod::MonteCarloMethod(size_t maxIterCount)
{
	m_maxIterCount = maxIterCount;
	m_result = 0;
}

void MonteCarloMethod::Run() {
	srand(unsigned(time(NULL)));
	GeneratePointsInCircle();
	CountPI();
}

MonteCarloMethod::~MonteCarloMethod()
{
}

void MonteCarloMethod::IncrementInnerCount() 
{
	InterlockedIncrement(&m_innerCount);
}


size_t MonteCarloMethod::GetInnerCount()
{
	return m_innerCount;
}

void MonteCarloMethod::CountPI()
{
	m_result = ((4. * MonteCarloMethod::GetInnerCount()) / m_maxIterCount);
}

void MonteCarloMethod::GeneratePointsInCircle()
{
	CustomRandom random;
	
	#pragma omp parallel for
	for (int i = 0; i < m_maxIterCount; ++i)
	{
		Point randomPoint = random.GenerateRandomPoint(CIRCLE_RADIUS);

		if (randomPoint.inCircle(CIRCLE_RADIUS))
		{
			MonteCarloMethod::IncrementInnerCount();
		}

	}
}

double MonteCarloMethod::GetResult()
{
	return m_result;
}