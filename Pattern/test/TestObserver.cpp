#include "../include/Observer.h"
#include <iostream>

class CTestObserver:
	public	CObserverBase<CTestObserver>
{
	public:
		CTestObserver()
		{

		}

		~CTestObserver()
		{

		}
		

		virtual void Update()
		{
			std::cout<<"Update!"<<std::endl;
		}

		void Notify()
		{
			if(NULL == m_p)
				return;
			m_p->Update();
		}

		void InitObserver()
		{
			AttachUser(this);
		}
};

int main()
{
	CTestObserver user;
	user.InitObserver();
	user.Notify();
	return 0;
}
