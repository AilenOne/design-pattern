

class ICustomer
{
public:
	ICustomer();
	virtual void sendMessage(const IMediator& mediator, const std::string& message) = 0;
	virtual void receiveMessage(const std::string& message, ICustomer* customer) = 0;
};

class ConcrateCustomer : public ICustomer
{
public:
	ConcrateCustomer();
	void sendMessageMessage(const IMediator& mediator, const std::string& message)
	{
		mediator.send(message, this);
	}

	void receiveMessage(const std::string& message, ICustomer* customer)
	{
		std::cout << "receive message:" << message << std::endl;
	}
};

class IMediator
{
public:
	virtual void reigsterCustomer(ICustomer* customer)
	{customers.emplace_back(customer);}

	virtual void send(const std::string& message, ICustomer* customer) = 0;

protected:
	std::list<ICustomer*>  customers;
};

class ConcreteMediator: public IMediator
{
public:
	virtual void send(const std::string& message, ICustomer* sendercustomer)
	{
		for (auto customer : customers)
		{
			if(customer != sendercustomer)
			{
				customer->receiveMessage(message, sendercustomer);
			}
		}
	}
};

void Test()
{
	ConcreteMediator mediator;
	ConcrateCustomer c1;
	ConcrateCustomer c2;


	mediator.reigsterCustomer(&c1);
	mediator.reigsterCustomer(&c2);

	c1.sendMessage(mediator, "test message");
	c2.sendMessage(mediator, "test message");

}





