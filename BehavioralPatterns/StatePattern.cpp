

class IState
{
public:
    virtual void Handle(TrafficLights*  pContext) = 0;
};


class TrafficLights
{
public:
    TrafficLights();
    void SetState(IState* state) { itsState = state; }
    void Request() { itsState->Handle(this); }

private:
    std::shared_ptr<IState> itsState;
};

class RedLight : public IState
{
public:
    virtual void Handle(TrafficLights*  pContext) override
    {
		std::cout << "Red Light" << std::endl;
		pContext->SetState(new YellowLight());
	}
};

class GreenLight : public IState
{
public:
    virtual void Handle(TrafficLights*  pContext) override
    {
        std::cout << "Green Light" << std::endl;
        pContext->SetState(new RedLight());
    }
};

class YellowLight : public IState
{
public:
    virtual void Handle(TrafficLights*  pContext) override
    {
        std::cout << "Yellow Light" << std::endl;
        pContext->SetState(new GreenLight());
    }
};


int test()
{
    TrafficLights tl;
    tl.SetState(new RedLight());
    tl.Request();
    tl.Request();
    tl.Request();
    tl.Request();

    return 0;
}
