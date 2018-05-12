#pragma once
#include <Windows.h>

class MonteCarloMethod
{
public:
	MonteCarloMethod(size_t maxInnerCount);
	void Run();
	~MonteCarloMethod();
	double MonteCarloMethod::GetResult();
private:
	void CountPI();
	void IncrementInnerCount();
	size_t MonteCarloMethod::GetInnerCount();
	void GeneratePointsInCircle();
	
	static size_t m_innerCount;
	size_t m_maxIterCount;
	double m_result;
};

