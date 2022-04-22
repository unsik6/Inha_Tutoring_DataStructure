// 백준 2346번 풍선 터뜨리기

// input: 풍선의 수 N (1 <= N <= 1,000)
//		  각 풍선 안의 종이에 쓰여 있는 값 x (-N <= x <= N, x != 0)
// 
// condition: 처음에는 1번 풍선을 터뜨린다. 이후 풍선 안의 종이에 쓰여 있는 값 만큼 이동 하고 터뜨린다.

#include <iostream>
using namespace std;

class Node
{
	int num, x;
	Node* prev;
	Node* next;

public:
	Node(int _n = 0, int _x = 0) : num(_n), x(_x)
	{
		prev = next = nullptr;
	}
	~Node() {}

	friend class DLinkedList;
};

class DLinkedList
{
	Node* header;
	Node* trailer;

public:
	DLinkedList()
	{
		header = new Node();
		trailer = new Node();
		header->next = trailer;
		trailer->prev = header;
	}
	~DLinkedList()
	{
		Node* cur = header;
		while (cur != nullptr)
		{
			Node* tmp = cur;
			cur = cur->next;

			delete tmp;
		}
	}

	bool isEmpty() { return header->next == trailer; }

	void pushBack(int _n, int _x)
	{
		Node* newNode = new Node(_n, _x);

		newNode->prev = trailer->prev;
		newNode->next = trailer;
		trailer->prev->next = newNode;
		trailer->prev = newNode;
	}

	void remove(Node* _node)
	{
		_node->prev->next = _node->next;
		_node->next->prev = _node->prev;
		delete _node;
	}

	Node* move(Node* _offset, int _d)
	{
		Node* cur = _offset;
		if (_d < 0)
		{
			for (int i = _d; i < 0; i++)
			{
				if (cur->prev == header) cur = trailer->prev;
				else cur = cur->prev;
			}
		}
		else
		{
			for (int i = 0; i < _d; i++)
			{
				if (cur->next == trailer) cur = header->next;
				else cur = cur->next;
			}
		}

		return cur;
	}

	void balloon()
	{
		Node* cur = header->next;
		while (!this->isEmpty())
		{
			cout << cur->num << ' ';
			Node* tmp = cur;
			cur = this->move(cur, cur->x);
			remove(tmp);
		}
	}

	// for test
	void printAll()
	{
		Node* cur = header;
		while (cur != nullptr)
		{
			cout << cur->num << ' ' << cur->x << endl;
			cur = cur->next;
		}
	}
};

int main()
{
	int N, input;
	cin >> N;
	DLinkedList list;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> input;
		list.pushBack(i, input);
	}
	list.balloon();
}
