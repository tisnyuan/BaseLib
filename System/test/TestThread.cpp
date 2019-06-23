#include "../include/BaseThread.h"
#include <unistd.h>
#include <iostream>

class CTestThread:
	public CBaseThreadUser
{
	public:
	CTestThread()
	{
		m_thread.AttachUser(this);
		m_thread.Start();
	}

	~CTestThread()	
	{
		m_thread.Wait();
	}

	virtual void OnRunTask()
	{
		int i = 0;
		for(; i < 10; i++)
		{
			std::cout<<i<<std::endl;
			sleep(1);
		}
	}

	private:
	CBaseThread m_thread;
};

int main()
{
	CTestThread test;
	for(int j = 0; j < 10; j++)
	{
		std::cout<<j<<std::endl;
		sleep(2);
	}
	return 0;
}
