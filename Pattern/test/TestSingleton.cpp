#include "../include/Singleton.h"

class CTestUnmanedSingleton
{
	public:
	BASE_DECLARE_UNMANAGED_SINGLETON(CTestUnmanedSingleton)

	CTestUnmanedSingleton()
	{

	}

	~CTestUnmanedSingleton()
	{

	}
};

BASE_IMPLEMENTE_UNMANAGED_SINGLETON(CTestUnmanedSingleton)

int main()
{
	CTestUnmanedSingleton test;
	CTestUnmanedSingleton* pInstance = test.GetInstance();

	return 0;
}
