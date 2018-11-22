
/********************switch and electrical equipment*********************************/



class IElectricalEquipment
{
public:
	virtual ~IElectricalEquipment();

	virtual void PowerOn() = 0;

	virtual void PowerOff() = 0;
};


class Light : public IElectricalEquipment
{
public:

	virtual void PowerOn() override
	{
		std::cout << "Light on." << std::endl;
	}

	virtual void PowerOff() override
	{
		std::cout << "Light off." << std::endl;
	}
};

class Fan : public IElectricalEquipment
{
public:

	virtual void PowerOn() override
	{
		std::cout << "Fan on." << std::endl;
	}

	virtual void PowerOff() override
	{
		std::cout << "Fan off." << std::endl;
	}
};

class ISwitch
{
public:
	ISwitch(std::shared<IElectricalEquipment> euqipment): ;
	virtual void On() = 0;
	virtual void Off() = 0;

protected:
	std::shared<IElectricalEquipment> euqipment;
};

class KeySwitch : public ISwitch
{
public:
	void On() override
	{
		std::cout << " KeySwitch on"<<std::endl;
		euqipment->PowerOn();
	};

	void Off() override
	{
		std::cout << " KeySwitch Off"<<std::endl;
		euqipment->PowerOff();
	};
};

class TwoPositionSwithc: public ISwitch
{
public:
	void On() override
	{
		std::cout << " TwoPositionSwithc on"<<std::endl;
		euqipment->PowerOn();
	};

	void Off() override
	{
		std::cout << " TwoPositionSwithc Off"<<std::endl;
		euqipment->PowerOff();
	};
};

class TestDemo
{
public:
	void run()
	{
		std::shared<ISwitch>  keyswitch(new KeySwitch(new Light()));
		keyswitch->On();
		keyswitch->Off();
	}
};



