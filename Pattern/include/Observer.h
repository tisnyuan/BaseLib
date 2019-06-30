#ifndef OBSERVER_BASE_H
#define OBSERVER_BASE_H

#include "stdio.h"

template<typename T>
class CObserverBase
{
	public:
	CObserverBase()
	{

	}

	~CObserverBase()
	{

	}

	void AttachUser(T* p)
	{
		m_p = p;
	}

	void DetachUser()
	{
		m_p = NULL;
	}
	protected:

	T* m_p;
};


#endif
