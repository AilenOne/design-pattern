

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
	IClient* createClient();
	IService* createService();
};

class FactoryB : public AbstracetFactory
{
public:
	IService* createClient();
	IService* createService();
};


