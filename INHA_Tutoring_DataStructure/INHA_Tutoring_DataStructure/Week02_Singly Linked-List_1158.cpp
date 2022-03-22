// 백준 1158번 요세푸스 문제

// input: 사람의 수 N, 제거 간격 K (1 <= K <= N <= 5,000)
// 
// condition: K순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들도 이루어진 원을 따라 계속
//			  모두 죽을 때까지 계속하고, 죽은 순서대로 출력

// using Singly Linked List
// 단일 연결 리스트를 이해하는 목적이므로 환형 리스트로 구현하지는 않았습니다.
// 근데 환형 리스트 쓰면 아주 조금 더 직관적이고 편합니다.

#include<iostream>
using namespace std;

class Node
{
	int e;
	Node* next;

public:
	Node(int _e = 0) : e(_e), next(nullptr) {}
	~Node() {}


	// 객체지향의 캡슐화를 훼손하므로 추천하는 접근 권한 부여 방식은 아님.
	// 다만, 지금은 그게 중요한게 아니기 때문에 사용.
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