
class Computer
{
public:
	void setCPU(const string& cpu);
	{
		cpu_ = cpu;
	}
	void setRAM(const string& ram)
	{
		ram_ = ram;
	}
private:
	string cpu_;
	string ram_;
};

class IBuilder 
{
    virtual void buildCpu();
    virtual void buildRam();
    virtual Computer getComputer();
};


class IBMComputerBuilder : public Builder 
{
public:
   void buildCpu() {
   	computer.setCPU(string("IBMComputerBuilder CPU"));
    }

    void buildRam() {
         computer.setCPU(string("IBMComputerBuilder RAM" ));
    }
    
    Computer getComputer()
    {
    	return computer;
    }
    
private:
    Computer  computer;
};


class DELLComputerBuilder : public Builder 
{
public:
   void buildCpu() {
       computer.setCPU(string("DELLComputerBuilder CPU"));
    }

    void buildRam() {
        computer.setCPU(string("DELLComputerBuilder RAM" ));
    }
    
    Computer getComputer()
    {
    	return computer;
    }
    
private:
    Computer  computer;
};

class Idirector
{
public:
	virtual void setBuilder(IBuilder& builder)
	{
		itsBuilder = &builder;
	}

	virtual void construct() = 0;
};


class Director : public Idirector
{
public:
    void construct()
    {
	itsBuilder->buildCpu();
	itsBuilder->buildRam();
    }
};	
	

int test()
{
	Builder* builder =  new IBMComputerBuilder();
	Director  director;
	director->setBuilder(*builder);
	Director->construct();
	
	Computer computer = builder->getComputer();
	
}


