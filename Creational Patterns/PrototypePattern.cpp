

class IService
{
public:
	virtual IService* Clone() = 0;

};


class ServiceA
{
public:
	IService* Clone()
	{
		return new ServiceA(*this);
	}
};


class ServiceB
{
public:
	IService* Clone()
	{
		return new ServiceB(*this);
	}
};
