//Singleton Declare

#define BASE_DECLARE_UNMANAGED_SINGLETON(ClassName) \
	static ClassName* GetInstance();


//Singleton Defination

#define BASE_IMPLEMENTE_UNMANAGED_SINGLETON(ClassName)	\
	ClassName* ClassName::GetInstance() \
	{ \
		static ClassName instance; \
		return &instance; \
	}
