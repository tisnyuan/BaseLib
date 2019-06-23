#include <mutex>

//simple mutex
class CBaseMutex
{
	public:
		CBaseMutex()
		{
			m_mux.lock();
		}
		~CBaseMutex()
		{
			m_mux.unlock();
		}

	private:
		std::mutex m_mux;
};

class CBaseTimedMutex
{
	public:
		CBaseTimedMutex()
		{
			m_mux.lock();
		}
		~CBaseTimedMutex()
		{
			m_mux.unlock();
		}

	private:
		std::timed_mutex m_mux;
};


#define MUX_GUARD \
	CBaseMutex mux;

#define MUX_TIMED_GUARD \
	CBaseTimedMutex mux;
