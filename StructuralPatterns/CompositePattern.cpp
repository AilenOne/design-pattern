
/***********************file system********************************/


class Node
{
public:
	Node(const string& name):nodeName(name)
	{}

	virtual void addNode(Node& node) = 0;
	virtual void removeNode(Node& node) = 0;
	virtual void display() = 0;

protected:
	std::string nodeName;
};

class Filer : public Node
{
public:
	Filer(const string& name):Node(name)

	void display()
	{
			std::cout <<"Name:" << nodeName << std::end;
	}
private:
	void addNode(Node& node);
	void removeNode(Node& node);
};

class Noder : public Node
{
public:
	Noder(const string& name):Node(name)

	void addNode(Node& node)
	{
		nodeList.instert(node);
	}
	void removeNode(Node& node)
	{
		nodeList.erase(node);
	}
	void display()
	{
		for (auto node& : nodeList)
		{
			node->display();
		}
	}

private:
	std::list<Node*>  nodeList;
};


void test()
{
	Node* root = new Noder("c:/");
	Node* file1 = new Filer("TEST.txt");
	root->addNode(file);
	Noder* dir = new Noder("SRC");
	Noder* filea = new Noder("a.cpp");
	Noder* fileb = new Noder("b.cpp");
	dir->addNode(filea);
	dir->addNode(fileb);

	root->addNode(file);
	root->addNode(dir);
}

