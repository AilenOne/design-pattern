

class IObserver
{
public:
	virtual void update(string state) = 0;
};

class ConcreteObserver : public IObserver
{
public:
    void Update(string state) {
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

class WeatherSubject : public ISubject
{
public:
	WeatherSubject(string state):itsState(state)
	{}

	void setState(string state)
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
	string itsState;
};

void Test()
{
	 WeatherSubject subject("sun");
	 IObserver *pObserver1 = new ConcreteObserver();
	 IObserver *pObserver2 = new ConcreteObserver();

	 subject.Attach(pObserver1);
	 subject.Attach(pObserver2);

	 subject.setState("rain");
	 subject.Notify();

	 subject.Detach(pObserver2);

	 subject.setState("cloudy");
	 subject.Notify();
}


