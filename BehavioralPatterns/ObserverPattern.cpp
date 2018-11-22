

class IObserver
{
public:
	virtual void update(int state) = 0;
};

class ConcreteObserver : public IObserver
{
public:
    void Update(int state) {
        std::cout <<"update state: " << state << "\n" << std::endl;
    }
};


class ISubject
{
public:
	virtual void Attach(IObserver*) = 0;
	virtual void Detach(IObserver*) = 0;
	virtual void Notify() = 0;
};

class ConcreteSubject : public ISubject
{
public:
	ConcreteSubject(int state):itsState(state)
	{}

	void setState(int state)
	{ itsState = state;}

	void Attach(IObserver *observer) {
		observers.push_back(observer);
	}

	void Detach(IObserver *observer) {
		observers.remove(observer);
	}

	void Notify() {
		for (auto observer : observers)
		{
			observer->update(itsState);
		}
	}

private:
	list<IObserver *> observers;
	int itsState;
};

void Test()
{
	 ConcreteSubject subject(2);
	 IObserver *pObserver1 = new ConcreteObserver();
	 IObserver *pObserver2 = new ConcreteObserver();

	 subject.Attach(pObserver1);
	 subject.Attach(pObserver2);

	 subject.setState(5);
	 subject.Notify();

	 subject.Detach(pObserver2);

	 subject.setState(15);
	 subject.Notify();
}


