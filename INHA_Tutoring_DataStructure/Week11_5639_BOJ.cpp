/* 백준 5639번 이진 탐색 트리
*
* Input: 이진 탐색 트리를 전위 순회한 결과를 한줄에 하나씩 출력한다.
*		 노드에 들어있는 키 값은 10^6보다 작은 양의 정수이며 중복되지 않는다. 노드의 수는 10,000개 이하이다.
*
* Output: 이진 탐색 트리를 후위 순회한 결과를 한줄에 하나씩 출력한다.
* 
* 이진 탐색 트리는 키 값의 입력 순에 따라 그 형태가 달라진다.
* 전위 순회는 루트를 먼저 출력하므로 출력한 순으로 입력됨을 알 수 있다.
* 그러므로 입력된 순으로 이진 탐색 트리에 삽입한 후 후위 순회를 하면 된다.
* 
* 여기서 중요한 점은 BST는 높이를 보장하지 않는다는 것이다.
* 예를 들어 최초로 입력된 수가 1000이라고 생각해보자.
* 1000부터 1씩 감소하면서 입력을 하는 경우
* 높이는 1000이 된다. 노드의 수가 최대 10,000개이므로
* 배열로 구현할 경우 최악의 경우 2^10000개가 된다.
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