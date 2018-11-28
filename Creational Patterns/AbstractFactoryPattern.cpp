
class IMobile
{
public:
	virtual const std::string getProductName() = 0;
};

class HUAWEMobile : public IMobile
{
public:
	HUAWEMobile()
	{cout << "create HUAWEMobile!" << endl; }

	const std::string getProductName()
	{
		return "HUAWEMobile";
	}
};

class XIAOMMobile : public IMobile
{
public:
	XIAOMMobile()
	{cout << "create XIAOMMobile!" << endl; }

	const std::string getProductName()
	{
		return "XIAOMMobile";
	}
};

class IBangle
{
public:
	virtual const int cost() = 0;
};

class HUAWEBangle : public IBangle
{
public:
	HUAWEIBangle()
	{cout << "create HUAWEIBangle!" << endl; }

	const std::string cost()
	{
		return 100;
	}
};

class XIAOMBangle : public IBangle
{
public:
	XIAOMBangle()
	{cout << "create XIAOMBangle!" << endl; }

	const std::string cost()
	{
		return 200;
	}
};

/////////////////////////////////////////////////////////
class AbstracetFactory
{
public:
	virtual IMobile* createMobile() = 0;
	virtual IBangle* createBangle() = 0;
};

class FactoryHUAWEI : public AbstracetFactory
{
public:
	IMobile* createMobile()
	{
		return new HUAWEMobile();
	}
	IBangle* createBangle()
	{
		return new HUAWEBangle();
	}
};


class FactoryXIAOMI : public AbstracetFactory
{
public:
	IMobile* createMobile()
	{
		return new XIAOMMobile();
	}
	IBangle* createBangle()
	{
		return new XIAOMBangle();
	}
};



