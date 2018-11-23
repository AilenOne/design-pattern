
//饮料
class IBeverage
{
public:
	virtual string Name() = 0;
	virtual double Cost() = 0;
};

// 黑咖啡，属于混合咖啡
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

// 深度烘培咖啡豆
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

//黑咖啡 + 奶油
class HouseBlendWithCream : public IBeverage
{
public:
	string Name()
	{  return "HouseBlendWithCream";}

	double cost()
	{
		return 4.8 + 3.9;
	}
};

/////////////////////////////////////////////////////////////////
// 调味品
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

/********** 具体的饮料（调味品）**********/

// 奶油
class Cream  : public CondimentDecorator
{
public:
	Cream (IBeverage* ibeverage) : CondimentDecorator(ibeverage)
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

// 糖浆
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

// 摩卡
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




