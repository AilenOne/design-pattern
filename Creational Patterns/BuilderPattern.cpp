




class IBuilder
{
	virtual void builderPart1();
	virtual void builderPart2();
	virtual void builderPart3();
};

class Idirector
{
public:
	virtual void setBuilder(IBuilder& builder)
	{
		itsBuilder = &builder;
	}

	virtual void construct() = 0;

protected:
	IBuilder* itsBuilder;
};

class Director : public Idirector
{
public:
	void construct()
	{
		itsBuilder->builderPart1();
		itsBuilder->builderPart2();
		itsBuilder->builderPart2();
		itsBuilder->builderPart3();
	}
};


class OrderBuilder : public IBuilder
{
	void builderPart1()
	{std::cout << "OrderBuilder OrderBuilder"  << std::endl;}
	void builderPart2();
	void builderPart3();
};


class OrderBuilder2 : public IBuilder
{
	void builderPart1()
	{std::cout << "OrderBuilder2 OrderBuilder"  << std::endl;}
	void builderPart2();
	void builderPart3();
};


int test()
{
	OrderBuilder builder;
	Director director;
	director.setBuilder(builder);
	director.construct();
}


