

class IColleague
{
public:
	IColleague();
	virtual void sendMessage(const IMediator& mediator, const std::string& message) = 0;
	virtual void receiveMessage(const std::string& message, IColleague* colleague) = 0;
};

class ConcrateColleague : public IColleague
{
public:
	ConcrateColleague();
	void sendMessageMessage(const IMediator& mediator, const std::string& message)
	{
		mediator.send(message, this);
	}

	void receiveMessage(const std::string& message, IColleague* colleague)
	{
		std::cout << "receive message:" << message << std::endl;
	}
};

class IMediator
{
public:
	virtual void reigsterColleague(IColleague* colleague)
	{colleagues.emplace_back(colleague);}

	virtual void send(const std::string& message, IColleague* colleague) = 0;

protected:
	std::list<IColleague*>  colleagues;
};

class ConcreteMediator: public IMediator
{
public:
	virtual void send(const std::string& message, IColleague* senderColleague)
	{
		for (auto colleague : colleagues)
		{
			if(colleague != senderColleague)
			{
				colleague->receiveMessage(message, colleague);
			}
		}
	}
};

void Test()
{
	ConcreteMediator mediator;
	ConcrateColleague c1;
	ConcrateColleague c2;


	mediator.reigsterColleague(&c1);
	mediator.reigsterColleague(&c2);

	c1.sendMessage(mediator, "test message");
	c2.sendMessage(mediator, "test message");

}





