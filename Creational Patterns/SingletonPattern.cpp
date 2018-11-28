#include <mutex>

//idler
class Singleton
{
public:
    static Singleton* GetInstance();
	
private:
    Singleton() {}

private:
    static Singleton * m_pSingleton;
};

Singleton *Singleton::m_pSingleton = nullptr;

Singleton *Singleton::GetInstance()
{
    if (m_pSingleton == nullptr)
        m_pSingleton = new Singleton();

    return m_pSingleton;
}

//-------------------------------------------------------------------
//hungry
Singleton *Singleton::m_pSingleton = new Singleton();

Singleton *Singleton::GetInstance()
{
    return m_pSingleton;
}

//-------------------------------------------------------------------
class SingleObjectSimple
{
public:
	static const SingleObjectSimple&  getSignleObjectInstance()
	{
		static SingleObjectSimple instance;
		return instance;
	}

private:
	SingleObjectSimple();
	SingleObjectSimple(const SingleObjectSimple&);
	SingleObjectSimple& operator =(const SingleObjectSimple&);
};

//-------------------------------------------------------------------
//double lock
class SingleObject
{	
public:
	static const SingleObject*  getSignleObject();

private:
	SingleObject();
	static SingleObject* object;
	static std::mutex objectMutex;
};


SingleObject* SingleObject::object=nullptr;

const SingleObject* SingleObject::getSignleObject()
{
    if (nullptr == object)
    {
        std::unique_lock<std::mutex> lock(objectMutex);
	if (nullptr == object)
        {
	   object = new SingleObject();
	}
    }
    return object;
}





