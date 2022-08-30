#include <iostream>
using namespace std;

template<typename T>
class Node
{
private:
	int m_idx;
	T m_elem;
	Node* m_prev;
	Node* m_next;

public:
	Node(T _e = 0, int _idx = -1) : m_elem(_e), m_idx(_idx)
	{ 
		m_prev = m_next = nullptr;
	}
	~Node() {}

	template <typename ListType> friend class DList;
};


template <typename T>
class DList
{
private:
	int m_size;
	Node<T>* m_header;
	Node<T>* m_trailer;

public:
	DList()
	{
		m_header = new Node<T>();
		m_trailer = new Node<T>();

		m_header->m_next = m_trailer;
		m_trailer->m_prev = m_header;

		m_size = 0;
	}
	~DList()
	{
		Node<T>* curNode = m_header;
		while (curNode != nullptr)
		{
			Node<T>* delTarget = curNode;
			curNode = curNode->m_next;
			delete delTarget;
			
		}
	}

	int size() { return m_size; }
	bool isEmpty() { return !m_size; }

	T elemAtRank(int _r)
	{
		Node<T>* curNode = m_header->m_next;
		while (curNode != nullptr)
		{
			if (curNode->m_idx == _r)
			{
				return curNode->m_elem;
			}
			curNode = curNode->m_next;
		}

		return NULL;
	}

	void replaceAtRank(int _r, T _e)
	{
		Node<T>* curNode = m_header->m_next;
		while (curNode != nullptr)
		{
			if (curNode->m_idx == _r)
			{
				curNode->m_elem = _e;
				return;
			}
			curNode = curNode->m_next;
		}

		cerr << "Can't Find\n";
	}

	void insertAtRank(int _r, T _e)
	{
		if (_r > m_size || _r < 0) return;

		Node<T>* newNode = new Node<T>(_e);
		Node<T>* curNode = m_header;
		while (curNode->m_next != m_trailer)
		{
			if (curNode->m_next->m_idx == _r)
				break;
			curNode = curNode->m_next;
		}

		newNode->m_prev = curNode;
		newNode->m_next = curNode->m_next;

		curNode->m_next->m_prev = newNode;
		curNode->m_next = newNode;

		newNode->m_idx = _r;
		curNode = newNode->m_next;
		while (curNode->m_next != nullptr)
		{
			curNode->m_idx++;
			curNode = curNode->m_next;
		}

		m_size++;
	}

	void printAll()
	{
		Node<T>* curNode = m_header->m_next;
		while (curNode != m_trailer)
		{
			cout << curNode->m_idx << ':' << curNode->m_elem << ' ';
			curNode = curNode->m_next;
		}
		cout << '\n';
	}
};


int main()
{
	
	return 0;
}
