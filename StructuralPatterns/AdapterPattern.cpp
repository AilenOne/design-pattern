



class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual void next() = 0;
	virtual void remove() = 0;
};

class Vector
{
public:
	bool hasMoreElement();
	void nextElement();
	void removeElement();
};

class VectorIterator :public Iterator
{
public:
	virtual bool hasNext()
	{
		itsVector.hasMoreElement();
	}
	virtual void next()
	{ itsVector.nextElement(); }
	virtual void remove()
	{ itsVector.removeElement(); }
private:
	Vector  itsVector;
};

class VectorIterator :public Iterator, public Vector
{
public:
	virtual bool hasNext()
	{
		hasMoreElement();
	}
	virtual void next()
	{ nextElement(); }
	virtual void remove()
	{ removeElement(); }
};



