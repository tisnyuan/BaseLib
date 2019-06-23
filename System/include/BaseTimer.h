#pragma once

#include "BaseThread.h"
#include "unistd.h"
#include <iostream>

class CBaseTimer:
	public CBaseThreadUser
{
	public:
		CBaseTimer()
		{
			m_Thread.AttachUser(this);
		}

		~CBaseTimer()
		{
			m_Thread.DetachUser();
		}

		virtual void OnTimer() = 0;

		virtual void OnRunTask()
		{
			while(!m_bIsQuit)
			{
				OnTimer();
				sleep(m_nTimeInterval);
			}
		}

		void SetTimer(int nTimeInterval)
		{
			m_nTimeInterval = nTimeInterval;
			m_bIsQuit = false;
			m_Thread.Start();
		}

		void StopTimer()
		{
			m_bIsQuit = true;
			m_Thread.Wait();
		}

	private:
		CBaseThread m_Thread;
		bool m_bIsQuit;
		int  m_nTimeInterval;
};
