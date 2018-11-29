

class IReceiver
{
public:
     virtual void open()
     virtual void close()
};


class ClientReceiver
{
public:
	void open()
	{
		std::cout << "open clinet" << std::endl;
	}

	void close()
	{
		std::cout << "close clinet" << std::endl;
	}
};

class LogReceiver
{
public:
	void open()
	{
		std::cout << "open log" << std::endl;
	}

	void close()
	{
		std::cout << "close log" << std::endl;
	}
};



class Command
{
public:
	Command(Receiver* receiver) :itsReceiver(receiver)
	{}
	virtual void executeCommand();
protected:
	Receiver* itsReceiver;
};

class CommandOpen : public Command
{
public:
	CommandOpen(Receiver* receiver) :Command(receiver)
	{}
	virtual void executeCommand()
	{
		itsReceiver->open();
	}
};

class CommandClose : public Command
{
public:
	CommandClose(Receiver* receiver) :Command(receiver)
	{}
	virtual void executeCommand()
	{
		itsReceiver->close();
	}
};

class ServerThread
{
public:
	void setCommand(Command* command)
	{
		itsCommands.push_back(command);
	}

	void do()
	{
		for (auto commands: itsCommands)
		{
			commands->executeCommand();
			itsCommands.pop_front();
		}
	}

	void undo(Command* command)
	{
		itsCommands.remove(command);
	}

private:
	std::list<Command*> itsCommands;
};


void test()
{
	ClientReceiver receiver;  
	// LogReceiver receiver;
	Command* open = new CommandOpen(&receiver);
	Command* close = new CommandClose(&receiver);

	ServerThread server;
	server.setCommand(open);
	server.setCommand(close);
	server.do();
}


