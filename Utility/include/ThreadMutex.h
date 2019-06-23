#include <mutex>

typedef enum _eMuxType
{
	E_MUX,
	E_TIMED_MUX,
	E_RECURSIVE_MUX,
	E_RECURSIVE_TIMED_MUTEX
}eMuxType;

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

#define GUARD(eMuxType) \
	CBaseMutex mux;
