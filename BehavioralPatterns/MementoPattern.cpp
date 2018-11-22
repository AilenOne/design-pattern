


class Memento
{
public:
	Memento(int state):itsState(state)
	{}

	int getState()
	{ return itsState; }

private:
	int itsState;
};


class Originator
{
public:
	Originator(int state):itsState(state)
	{}

	int getState()
	{ return itsState; }

	void setState(int state)
	{  itsState = state; }

	Memento saveState()
	{
		return std::move(Memento(itsState));
	}

	void getStateFromMemento(Memento& memento)
	{
		itsState = memento.getState();
	}

private:
	int itsState;
};

class CareTaker
{
public:
	void add(Memento& memento)
	{
		mementos.push_back(memento);
	}

	Memento& getMemento(int index)
	{
		mementos.at(index);
	}

private:
	std::vector<Memento> mementos;
};

void test()
{
	 Originator originator;
	 CareTaker careTaker;

	 originator.setState(1);
	 originator.setState(2);

	 careTaker.add(originator.saveState());

	 originator.setState(3);

	 careTaker.add(originator.saveState());

	 originator.setState(4);

	  std::cout << "Current State: " + originator.getState()<< std::endl;
	  originator.getStateFromMemento(careTaker.getMemento(0));

	  std::cout << "First saved State: " + originator.getState()<< std::endl;

	  originator.getStateFromMemento(careTaker.getMemento(1));

	  std::cout << "Second saved State: " + originator.getState() << std::endl;
}


