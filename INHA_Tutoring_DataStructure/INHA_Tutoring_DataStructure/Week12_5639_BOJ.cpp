/* ���� 5639�� ���� Ž�� Ʈ��
*
* Input: ���� Ž�� Ʈ���� ���� ��ȸ�� ����� ���ٿ� �ϳ��� ����Ѵ�.
*		 ��忡 ����ִ� Ű ���� 10^6���� ���� ���� �����̸� �ߺ����� �ʴ´�. ����� ���� 10,000�� �����̴�.
*
* Output: ���� Ž�� Ʈ���� ���� ��ȸ�� ����� ���ٿ� �ϳ��� ����Ѵ�.
* 
* ���� Ž�� Ʈ���� Ű ���� �Է� ���� ���� �� ���°� �޶�����.
* ���� ��ȸ�� ��Ʈ�� ���� ����ϹǷ� ����� ������ �Էµ��� �� �� �ִ�.
* �׷��Ƿ� �Էµ� ������ ���� Ž�� Ʈ���� ������ �� ���� ��ȸ�� �ϸ� �ȴ�.
* 
* ���⼭ �߿��� ���� BST�� ���̸� �������� �ʴ´ٴ� ���̴�.
* ���� ��� ���ʷ� �Էµ� ���� 1000�̶�� �����غ���.
* 1000���� 1�� �����ϸ鼭 �Է��� �ϴ� ���
* ���̴� 1000�� �ȴ�. ����� ���� �ִ� 10,000���̹Ƿ�
* �迭�� ������ ��� �־��� ��� 2^10000���� �ȴ�.
*/

#include <iostream>
using namespace std;

class Node
{
	int m_key = 0;
	Node* m_par = nullptr;
	Node* m_left = nullptr;
	Node* m_right = nullptr;
public:
	Node(int _k) : m_key(_k) {}

	int getKey() { return m_key; }
	Node* getLeft() { return m_left; }
	void setLeft(Node* _l) { m_left = _l; }
	Node* getRight() { return m_right; }
	void setRight(Node* _r) { m_right = _r; }
	Node* getParent() { return m_par; }
	void setParent(Node* _p) { m_par = _p; }
};

class BST
{
private:
	Node* m_root;
	int m_size;

public:
	BST()
	{
		m_root = nullptr;
		m_size = 0;
	}
	~BST()
	{
		Node* curNode = m_root;
		while (curNode->getParent() != nullptr)
		{
			if (curNode->getLeft() != nullptr)
			{
				curNode = curNode->getLeft();
			}
			else if (curNode->getRight() != nullptr)
			{
				curNode = curNode->getRight();
			}
			else
			{
				Node* tmp = curNode;
				curNode = curNode->getParent();
				if (curNode->getLeft() == tmp) curNode->setLeft(nullptr);
				else curNode->setRight(nullptr);
				delete tmp;
			}
		}
		delete m_root;
	}

	Node* getRoot() { return m_root; }

	void insert(int _k)
	{
		Node* newNode = new Node(_k);

		if (m_size == 0)
		{
			m_root = newNode;
			m_size++;
			return;
		}

		Node* curNode = m_root;
		while (1)
		{
			if (curNode->getKey() < _k)
			{
				if (curNode->getRight() == nullptr)
				{
					newNode->setParent(curNode);
					curNode->setRight(newNode);
					m_size++;
					return;
				}
				else
				{
					curNode = curNode->getRight();
				}
			}
			else if (curNode->getKey() > _k)
			{
				if (curNode->getLeft() == nullptr)
				{
					newNode->setParent(curNode);
					curNode->setLeft(newNode);
					m_size++;
					return;
				}
				else
				{
					curNode = curNode->getLeft();
				}
			}
		}
	}

	void printPostOrder(Node* _root)
	{
		if (_root->getLeft() != nullptr)
		{
			printPostOrder(_root->getLeft());
		}
		if (_root->getRight() != nullptr)
		{
			printPostOrder(_root->getRight());
		}
		cout << _root->getKey() << '\n';
	}

	
};

struct A
{
	int a;
	int b;
	string str;
	int c;
};

class C
{
public:
	int a;
	int b;
	string str;
	int c;
	
};

#include <time.h>

int main()
{
	BST bst;
	int input;
	while (cin >> input)
	{
		bst.insert(input);
	}
	bst.printPostOrder(bst.getRoot());
}