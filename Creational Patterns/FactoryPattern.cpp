

class IProduce
{
public:
	virtual const std::string getProductName() = 0;
};

class HUAWEIMobile : public IProduce
{
public:
	HUAWEIMobile()
	{cout << "create HUAWEIMobile!" << endl; }

	const std::string getProductName()
	{
		return "HUAWEIMobile";
	}
};

class XIAOMIMobile : public IProduce
{
public:
	XIAOMIMobile()
	{cout << "create XIAOMIMobile!" << endl; }

	const std::string getProductName()
	{
		return "XIAOMIMobile";
	}
};
///////////////////////////////////////////////////////////////////
class SimpleFactory
{
public:
	IProduce* createProduct(Type type)
	{
		IProduce* product = nullptr;
		if (type == "HUAWEI"）
		{
			product = new HUAWEIMobile();
		}
		else(type == "XIAOMI")
		{
			product = new XIAOMIMobile();  
		}
		return product;
	}
}




/////////////////////////////////////////////////////////
class AbstracetFactory
{
public:
	virtual IProduce* createProduct() = 0;
};

class FactoryHUAWEI : public AbstracetFactory
{
public:
	IProduce* createProduct()
	{
		return new HUAWEIMobile();
	}
};


class FactoryXIAOMI : public AbstracetFactory
{
public:
	IProduce* createProduct()
	{
		return new XIAOMIMobile();
	}
};


int test() {
	AbstracetFactory* Factoryhuawei = new  FactoryHUAWEI();
	IProduce* huawei =  Factoryhuawei->createProduct();
        huawei->getProductName();
  
  
        AbstracetFactory* Factoryxiaomi = new  FactoryXIAOMI();
	IProduce* xiaomi =  Factoryxiaomi->createProduct();
	xiaomi->getProductName();
	return 0;
}
