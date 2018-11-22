

class IClient
{
};

class ClientA : public IClient
{
};

class ClientB : public IClient
{
};


class IServer
{
};

class ServerA : public IServer
{
};

class ServerB : public IServer
{
};

class AbstracetFactory
{
public:
	virtual IClient* createClient() = 0;
	virtual IService* createServer() = 0;
};

class FactoryA : public AbstracetFactory
{
public:
	IClient* createClient();
	IService* createServer();
};

class FactoryB : public AbstracetFactory
{
public:
	IService* createClient();
	IService* createServer();
};


