

class Element
{
public:
	virtual void Accept(Visitor& visitor) = 0;
};


class ConcreteElementA : public Element
{
public:
	void Accept(Visitor& visitor)
	{
		visitor.visitConcreteElementA(this);
	}
};


class ConcreteElementB : public Element
{
public:
	void Accept(Visitor& visitor)
	{
		visitor.visitConcreteElementB(this);
	}
};

class Visitor
{
public:
	virtual void visitConcreteElementA(ConcreteElementA&);
	virtual void visitConcreteElementB(ConcreteElementB&);
};

class ConcreteVisitA
{
public:
	virtual void visitConcreteElementA(ConcreteElementA&)
	{
		cout << "Concrete A visit ElementA " << endl;
	}
	virtual void visitConcreteElementB(ConcreteElementB&)
	{
		cout << "Concrete A visit ElementB " << endl;
	}
};

class ConcreteVisitB
{
public:
	virtual void visitConcreteElementA(ConcreteElementA&)
	{
		cout << "Concrete B visit ElementA " << endl;
	}
	virtual void visitConcreteElementB(ConcreteElementB&)
	{
		cout << "Concrete B visit ElementA " << endl;
	}
};

class Object
{
public:
	void Attach(Element* element)
	{
		elements.push_back(element);
	}

	void Detach(Element* element)
	{
		elements.remove(element);
	}

	void Accept(Visitor& visitor)
	{
		for(auto ele : elements)
		{
			ele->Accept(visitor);
		}
	}
private:
	std::list<Element*>  elements;
};

void Test()
{
	Object  object;
	ConcreteElementA concreteElementA;
	ConcreteElementB concreteElementB;
	object.Attach(&concreteElementA);
	object.Attach(&concreteElementB);

	ConcreteVisitA v1;
	ConcreteVisitA v2;
	object.Accept(v1);
	object.Accept(v2);
}
