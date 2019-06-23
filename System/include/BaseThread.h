#pragma once

#include <pthread.h>

//implement thread by POSIX

class CBaseThreadUser;

typedef void* (CBaseThreadUser::*pMemFunc)(void *);


class CBaseThreadUser
{
	public:
	CBaseThreadUser()
	{

	}

	CBaseThreadUser(const CBaseThreadUser& c)
	{
		
	}

	virtual ~CBaseThreadUser()
	{

	}


	static void* ProxyFunc(void* arg)
	{
		CBaseThreadUser* pThread = static_cast<CBaseThreadUser*>(arg);
		pThread->OnRunTask();
		return NULL;
	}
	
	//thread run func, need to be implemented
	virtual void OnRunTask()
	{

	}
};

class CBaseThread
{
	public:
		CBaseThread()
		{

		}

		~CBaseThread()
		{

		}

		bool AttachUser(CBaseThreadUser* pUser)
		{
			if(NULL == pUser)
				return false;

			m_pUser = pUser;
			return true;	
		}

		void DetachUser()
		{
			m_pUser = NULL;
		}
		
		//start thread
		int Start()
		{
			int nRet;
			if(NULL == m_pUser)
				return -1;
			nRet = pthread_create(&m_pId,NULL,CBaseThreadUser::ProxyFunc,m_pUser);
			return 0;
		}
		
		//wait thread to quit
		void Wait()
		{
			pthread_exit(NULL);
		}

	private:
		CBaseThreadUser* m_pUser;	//thread observer
		pthread_t m_pId;	//thread id
};
