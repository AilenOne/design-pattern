

class IClient
{
};

class ClientA : public IClient
{
};

class ClientB : public IClient
{
};


class IService
{
};

class ServiceA : public IService
{
};

class ServiceB : public IService
{
};

class AbstracetFactory
{
public:
	virtual IClient* createClient() = 0;
	virtual IService* createService() = 0;
};

class FactoryA : public AbstracetFactory
{
public:
	IClient* createClient()
	{
		return new ClientA();
	}
	IService* createService()
	{
		return new ServiceA();
	}
};

class FactoryB : public AbstracetFactory
{
public:
	IService* createClient()
	{
		return new ClientB();
	}
	IService* createService()
	{
		return new ServiceB();
	}
};


