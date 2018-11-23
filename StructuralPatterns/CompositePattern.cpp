
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

class File : public Node
{
public:
	File(const string& name):Node(name)

	void display()
	{
			std::cout <<"Name:" << nodeName << std::end;
	}
private:
	void addNode(Node& node);
	void removeNode(Node& node);
};

class Dir : public Node
{
public:
	Dir(const string& name):Node(name)

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
	Node* root = new Dir("c:/");
	Node* file1 = new File("TEST.txt");
	root->addNode(file);
	Noder* dir = new Dir("SRC");
	Noder* filea = new File("a.cpp");
	Noder* fileb = new File("b.cpp");
	dir->addNode(filea);
	dir->addNode(fileb);

	root->addNode(file1);
	root->addNode(dir);
}

