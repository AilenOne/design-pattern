class IBill 
{
public：
    virtual void accept(AccountBookViewer viewer);
};

class AccountBookVisitor
{
public:
    virtual void view(OutlayBill bill);
    virtual void view(IncomeBill bill);
};


//支出
class OutlayBill : public Bill
{
public:
	
     ConsumeBill(double amount, string& name) 
     {
        itsAmount = amount;
        itsName = name;
    }

    void accept(AccountBookVisitor visitor) 
    {
        visitor.view(this);
    }

    double getAmount() {
        return itsAmount;
    }

    string getName() 
    {
        return itsName;
    }
private:
   double itsAmount;
   string itsName;
};

//收入
class IncomeBill : public  Bill
{
public:
    IncomeBill(double amount, string& name) 
    {
        itsAmount = amount;
        itsName = name;
    }

    void accept(AccountBookVisitor visitor) {
        visitor.view(this);
    }

    double getAmount() {
        return itsAmount;
    }

    string getName() {
        return itsName;
    }
private:
   double itsAmount;
   string itsName;
};


class Boss : public AccountBookVisitor
{
public:
    void view(OutlayBill& bill) {
        totalOutlay+= bill.getAmount();
    }

    void view(IncomeBill& bill) {
        totalIncome += bill.getAmount();
    }

    double getTotalIncome() 
    {
        return totalIncome;
    }

    double getTotalOutlay()
    {
        return totalOutlay;
    }
private:
   double totalIncome;
   double totalOutlay;
};

//财务
class Finance : public  AccountBookVisitor
{
public:
    void view(OutlayBill bill) 
    {
        if (bill.getName() = "工资") 
	{
            cout << "注会查看工资是否交个人所得税。" << endl;
        }
    }
    
    void view(IncomeBill bill) 
    {
        cout << "注会查看收入交税了没。" << endl;
    }
};

//账本类
class AccountBook {
public:	
    void addBill(Bill* bill)
    {
        billList.add(bill);
    }

    void accept(AccountBookVisitor& visitor)
    {
        for (auto bill : billList) {
            bill->accept(visitor);
        }
    }
private:
    std::List<Bill*> billList;
}

int test()
{
	AccountBook accountBook;
	
	//收入
	accountBook.addBill(new IncomeBill(10000, "卖商品"));
	accountBook.addBill(new IncomeBill(12000, "卖广告位"));
	
	//支出
	accountBook.addBill(new OutlayBill(1000, "工资"));
	accountBook.addBill(new OutlayBill(2000, "材料费"));

	AccountBookVisitor boss;
	AccountBookVisitor finance;

	//两个访问者分别访问账本
	accountBook.accept(boss);
	accountBook.accept(finance);
}

//////////////////////////////////////////////////////////////////////
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
