#pragma once
#include <Windows.h>
#include "stdafx.h"
#include "ThreadHandler.h"
#include "Point.h"
#include "CustomRandom.h"


DWORD WINAPI GeneratePointsInCircle(LPVOID maxInnerCount);
const int CIRCLE_RADIUS = 1;

class MonteCarloMethod
{
public:
	MonteCarloMethod(int maxInnerCount, int threadsCount);
	void Run();
	~MonteCarloMethod();
	static void IncrementInnerCount();
	static void IncrementCurrentIterCount();
	UINT64 MonteCarloMethod::GetInnerCount();
	static UINT64 GetCurrentIterCount();
	double MonteCarloMethod::GetPI();
private:
	void CountPI();
	int m_maxInnerCount;
	double m_result;
	int m_threadsCount;
};

