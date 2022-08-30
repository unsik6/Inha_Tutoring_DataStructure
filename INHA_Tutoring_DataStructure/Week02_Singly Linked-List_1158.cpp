// ���� 1158�� �似Ǫ�� ����

// input: ����� �� N, ���� ���� K (1 <= K <= N <= 5,000)
// 
// condition: K������� K��° ����� �����Ѵ�. �� ����� ���ŵǸ� ���� ����鵵 �̷���� ���� ���� ���
//			  ��� ���� ������ ����ϰ�, ���� ������� ���

// using Singly Linked List
// ���� ���� ����Ʈ�� �����ϴ� �����̹Ƿ� ȯ�� ����Ʈ�� ���������� �ʾҽ��ϴ�.
// �ٵ� ȯ�� ����Ʈ ���� ���� ���� �� �������̰� ���մϴ�.

#include<iostream>
using namespace std;

class Node
{
	int e;
	Node* next;

public:
	Node(int _e = 0) : e(_e), next(nullptr) {}
	~Node() {}


	// ��ü������ ĸ��ȭ�� �Ѽ��ϹǷ� ��õ�ϴ� ���� ���� �ο� ����� �ƴ�.
	// �ٸ�, ������ �װ� �߿��Ѱ� �ƴϱ� ������ ���.
	friend class SLinkedList;
};

class SLinkedList
{
	Node* head;

public:
	SLinkedList(Node* _h = nullptr) : head(_h) {}
	~SLinkedList()
	{
		Node* cur = head;
		while (cur != nullptr)
		{
			Node* tmp = cur;
			cur = cur->next;

			delete tmp;
		}
	}

	bool isEmpty() { return head == nullptr; }

	void pushBack(int _e)
	{
		Node* newNode = new Node(_e);
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		else
		{
			Node* cur = head;
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = newNode;
		}
	}

	void remove(Node* _node)
	{
		if (_node == head)
		{
			if (head->next != nullptr) head = head->next;
			else head = nullptr;
			delete _node;
			return;
		}
		Node* prev = head;
		while (prev != nullptr)
		{
			if (prev->next == _node)
			{
				break;
			}
			prev = prev->next;
		}
		if (prev != nullptr)
		{
			prev->next = _node->next;
			delete _node;
		}
	}



	void josephPrint(int _k)
	{
		cout << '<';
		Node* cur = head;

		while (!this->isEmpty())
		{
			for (int i = 0; i < _k - 1; i++)
			{
				if (cur->next != nullptr) cur = cur->next;
				else cur = head;
			}
			cout << cur->e;


			Node* tmp = cur;
			if (cur->next != nullptr) cur = cur->next;
			else cur = head;

			remove(tmp);
			if (this->isEmpty()) cout << '>';
			else cout << ", ";
		}
	}

	// for testing
	void printAll()
	{
		Node* cur = head;
		while (cur != nullptr)
		{
			cout << cur->e << ' ';
			cur = cur->next;
		}
		cout << '\n';
	}
};

int main()
{
	int N, K;
	cin >> N >> K;
	SLinkedList list;
	for (int i = 0; i < N; i++)
		list.pushBack(i + 1);
	list.josephPrint(K);

	return 0;
}