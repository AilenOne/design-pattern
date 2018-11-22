

class IBeverage
{
public:
	virtual string Name() = 0;
	virtual double Cost() = 0;
};

class HouseBlend : public IBeverage
{
public:
	string Name()
	{  return "HouseBlend";}

	double cost()
	{
		return 3.8;
	}
};

class DarkRoast : public IBeverage
{
public:
	string Name()
	{  return "HouseBlend";}

	double cost()
	{
		return 4.8;
	}
};

/////////////////////////////////////////////////////////////////


class HouseBlendWithMilk : public IBeverage
{
public:
	string Name()
	{  return "HouseBlendWithMilk";}

	double cost()
	{
		return 4.8 + 3.9;
	}
};

/////////////////////////////////////////////////////////////////

class CondimentDecorator : public IBeverage
{
public:
	CondimentDecorator(IBeverage* ibeverage) : iBeverage(ibeverage)
	{}

	string Name()
	{  return iBeverage->Name();}

	double cost()
	{
		return iBeverage->Cost();
	}

private:
	IBeverage*   iBeverage;
};


class Milk : public CondimentDecorator
{
public:
	Milk(IBeverage* ibeverage) : CondimentDecorator(ibeverage)
	{}

	string Name()
	{  return iBeverage->Name() + "Milk";}

	double cost()
	{
		return iBeverage->Cost() + 2.9;
	}

private:
	IBeverage*   iBeverage;
};


class Syrup : public CondimentDecorator
{
public:
	Syrup(IBeverage* ibeverage) : CondimentDecorator(ibeverage)
	{}

	string Name()
	{  return iBeverage->Name() + "Syrup";}

	double cost()
	{
		return iBeverage->Cost() + 2.2;
	}

private:
	IBeverage*   iBeverage;
};


class Mocha : public CondimentDecorator
{
public:
	Mocha(IBeverage* ibeverage) : CondimentDecorator(ibeverage)
	{}

	string Name()
	{  return iBeverage->Name() + "Mocha";}

	double cost()
	{
		return iBeverage->Cost() + 3.9;
	}

private:
	IBeverage*   iBeverage;
};


int test()
{
	 IBeverage *pHouseBlend = new HouseBlend();
	 cout << pHouseBlend->Name() << " : " << pHouseBlend->Cost() << endl;


	 CondimentDecorator *pCream = new Cream(pHouseBlend);
	 cout << pCream->Name() << " : " << pCream->Cost() << endl;

	 CondimentDecorator *pSyrup = new Syrup(pHouseBlend);
	 cout << pSyrup->Name() << " : " << pSyrup->Cost() << endl;

	CondimentDecorator *pMochaAndSyrup = new Mocha(pSyrup);
	cout << pMochaAndSyrup->Name() << " : " << pMochaAndSyrup->Cost() << endl;
}




