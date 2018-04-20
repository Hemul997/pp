#pragma once
#include <Windows.h>

DWORD WINAPI GeneratePointsInCircle(LPVOID maxInnerCount);

class MonteCarloMethod
{
public:
	MonteCarloMethod(size_t maxInnerCount, size_t threadsCount);
	void Run();
	~MonteCarloMethod();
	static void IncrementInnerCount();
	static void IncrementCurrentIterCount();
	static UINT64 MonteCarloMethod::GetInnerCount();
	static UINT64 GetCurrentIterCount();
	double MonteCarloMethod::GetResult();
private:
	void CountPI();
	static UINT64 m_innerCount;
	static UINT64 m_currentIterCount;
	size_t m_maxIterCount;
	double m_result;
	size_t m_threadsCount;
};

