#include "../include/BaseTimer.h"
#include <iostream>
#include "stdio.h"

class CTestTimer:
	public CBaseTimer
{
	public:
	CTestTimer()
	{

	}

	~CTestTimer()
	{

	}

	virtual void OnTimer()
	{
		std::cout<<"Timer Running!"<<std::endl;
	}
};

int main()
{
	CTestTimer Timer;
	Timer.SetTimer(1);
	for(int i = 0; i < 10;i++)
	{
		std::cout<<i<<std::endl;
	}
	Timer.StopTimer();
	return 0;
}
