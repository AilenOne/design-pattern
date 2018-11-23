

class IClient
{
public:
	virtual const std::string getClientName() = 0;
};

class ClientA : public IClient
{
public:
	ClientA()
	{cout << "create ClientA!" << endl; }

	const std::string getClientName()
	{
		return "ClientA";
	}
};

class ClientB : public IClient
{
public:
	ClientB()
	{cout << "create ClientB!" << endl; }

	const std::string getClientName()
	{
		return "ClientB";
	}
};
///////////////////////////////////////////////////////////////////
class SimpleFactory
{
public:
	IClient* createProduct(Type type)
	{
		IClient* clinet = nullptr;
		if (type == A）
		{
			clinet = new ClientA();
		}
		else(type == B)
		{
			clinet = new  ClientB();  
		}
		return clinet;
	}
}




/////////////////////////////////////////////////////////
class AbstracetFactory
{
public:
	virtual IClient* createProduct() = 0;
};

class FactoryA : public AbstracetFactory
{
public:
	IClient* createProduct()
	{
		return new ClientA;
	}
};


class FactoryB : public AbstracetFactory
{
public:
	IClient* createProduct()
	{
		return new ClientB;
	}
};


int test() {
	AbstracetFactory* FactoryA = new  FactoryA();
	IClient* clientA =  FactoryA->createProduct();
  clientA->getClientName();
  
  
  AbstracetFactory* FactoryB = new  FactoryB();
	IClient* clientB =  FactoryB->createProduct();
	clientB->getClientName();
	return 0;
}
