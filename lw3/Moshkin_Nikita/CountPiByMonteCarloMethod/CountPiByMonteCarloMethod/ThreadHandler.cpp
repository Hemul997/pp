#include "stdafx.h"
#include "ThreadHandler.h"

ThreadHandler::ThreadHandler()
{
}

ThreadHandler::~ThreadHandler()
{
	for (auto &thread : m_threads) 
	{
		CloseHandle(thread);
	}
}

void ThreadHandler::JoinAll()
{
	WaitForMultipleObjects((DWORD)m_threads.size(), m_threads.data(), true, INFINITE);
}

void ThreadHandler::PushThread(LPTHREAD_START_ROUTINE functionPointer, LPVOID lpParam)
{
	m_threads.push_back(CreateThread(NULL, 0, functionPointer, lpParam, 0, 0));
}
