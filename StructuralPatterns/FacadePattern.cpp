

class SystemA
{
public:
	virtual void doThing()
	{std::cout << "SystemA doThing" << std::endl;}
};

class SystemB
{
public:
	virtual void doThing()
	{std::cout << "SystemB doThing" << std::endl;}
};

class SystemC
{
public:
	virtual void doThing()
	{std::cout << "SystemC doThing" << std::endl;}
};



class Facade
{
public:
	void doThing()
	{
		a->doThing();
		b->doThing();
		c->doThing();
	}

private:
	SystemA * a;
	SystemB * b;
	SystemC * c;
};
