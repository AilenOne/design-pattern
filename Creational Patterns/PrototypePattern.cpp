

class IServer
{
public:
	virtual IServer* Clone() = 0;

};


class ServerA
{
public:
	IServer* Clone()
	{
		return new ServerA(*this);
	}
};


class ServerB
{
public:
	IServer* Clone()
	{
		return new ServerB(*this);
	}
};
