#pragma once

#include <windows.h>
#include <vector>

class ThreadHandler
{
public:
	ThreadHandler();
	~ThreadHandler();
	void PushThread(LPTHREAD_START_ROUTINE functionPointer, LPVOID lpParam);
	void JoinAll();
private:
	std::vector<HANDLE> m_threads;
};

