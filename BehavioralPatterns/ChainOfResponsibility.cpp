

class Manager
{
public:
	Manager(Manager*  manager, std::string& name): itsManager(manager),itsName(name)
	{}
	virtual void request(int num) = 0;
protected:
	Manager*  itsManager;
	std::string itsName;
};


class CommonManager : public  Manager
{
public:
	CommonManager(Manager*  manager, std::string& name) : Manager(manager, name)
	{}

	void request(int num)
	{
		if (num < 100)
		{
			std::cout << itsName <<" request is" << num << std::endl;
		}
		else
		{
			itsManager->request(num);
		}
	}
};

class MajorManager : public  Manager
{
public:
	MajorManager(Manager*  manager, std::string& name) : Manager(manager, name)
	{}

	void request(int num)
	{
		if (num < 1000)
		{
			std::cout << itsName <<" request is" << num << std::endl;
		}
		else
		{
			itsManager->request(num);
		}
	}
};


class GeneralManager : public  Manager
{
public:
	GeneralManager(Manager*  manager, std::string& name) : Manager(manager, name)
	{}

	void request(int num)
	{
		std::cout << itsName <<" request is" << num << std::endl;
	}
};


int test()
{
	Manager *general = new GeneralManager(nullptr, "general");
	Manager *major= new MajorManager(general, "major");
	Manager *common = new CommonManager(major, "common");
	common->request(50);
	common->request(600);
	common->request(1000);

	delete general;
	delete major;
	delete common;

	return 0;
}


