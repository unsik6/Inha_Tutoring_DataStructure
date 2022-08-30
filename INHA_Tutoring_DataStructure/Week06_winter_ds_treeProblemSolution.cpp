#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
	int elem;
	Node* par;
	vector<Node*> chi;

public:
	Node(int e = 0)
	{
		this->elem = e;
		this->par = nullptr;
	}
	~Node() {}

	friend class Tree;
};

class Tree
{
private:
	Node* root;
	vector<Node*> node_list;

public:
	Tree(Node* r = nullptr) { this->root = r; }
	Tree(int data)
	{
		root = new Node(data);
		node_list.push_back(root);
	}
	~Tree() {}

	void insert(int p, int c)
	{
		Node* parent = nullptr;
		for (Node* v : node_list)
		{
			if (v->elem == p)
			{
				parent = v;
				break;
			}
		}
		if (parent == nullptr)
			cout << -1 << endl;
		else
		{
			Node* newNode = new Node(c);
			parent->chi.push_back(newNode);
			newNode->par = parent;
			node_list.push_back(newNode);
		}
	}

	void printChild(int x)
	{
		for (Node* v : node_list)
		{
			if (v->elem == x)
			{
				if (v->chi.size() == 0)
				{
					cout << 0 << endl;
					return;
				}
				for (Node* v2 : v->chi)
					cout << v2->elem << ' ';
				cout << endl;
				return;
			}
		}
		cout << -1 << endl;
	}

	void printDepth(int X)
	{
		Node* target = nullptr;
		for (Node* v : node_list)
		{
			if (v->elem == X)
			{
				target = v;
				break;
			}
		}

		int depth = 0;
		if (target == nullptr)
		{
			cout << -1 << endl;
			return;
		}
		while (target != this->root)
		{
			depth++;
			target = target->par;
		}

		cout << depth << endl;
	}
};

int main()
{
}
