// ���� 18258 ť2 (Ʃ�͸���)

#include <iostream>
using namespace std;

template<typename T>				// ������ template�� ��ƴٴ� �п찡 �־ template�� �����غ��ҽ��ϴ�. ���� ���������� T == int�� ���ø� �˴ϴ�.
class Circular_Queue
{
private:
	T* m_arr;
	int m_capacity;
	int m_size;						// size�� ������ �����ϴ� ���� �� ���� ����Դϴ�.
									// Ư��, ȯ��ť������ ť�� �� ������ ���� ������� ���� front_index�� rear_index�� ���� ������
									// ������ �������ִ� ���� ���մϴ�.
									// �׷��� ���� ��쿡�� �ǵ��ߴ� capacity���� 1�� ũ�� �迭�� �����, front ���� ĭ�� ��������� �ξ�� �մϴ�.

	int m_fIdx = 0, m_rIdx = 0;		// Ŭ������ ��� ���� �ʱ�ȭ�� �̿� ���� ������ �� �ֽ��ϴ�.
									// ���� ��Ʈ���� ����������, �ε��� ��Ģ�� �ڱ� ����� �ϵ� ����� ������ �˴ϴ�.
									// �Ϲ����� iterator�� end ������ ������ ����� �ٷ� �ڶ� ���� �׷��� �����ϰ� �մϴ�.

public:
	// �Ϲ������� Ŭ���� �����ڿ��� ��� ������ �ʱ�ȭ�մϴ�.
	Circular_Queue(int _cap) : m_fIdx(0), m_rIdx(0), m_size(0)
	{
		m_arr = new T[_cap];
		m_capacity = _cap;
	}
	~Circular_Queue() { delete[] m_arr; }	// �޸� ����

	bool empty() { return m_size == 0; }

	int size() { return m_size; }

	void push(T _elem)
	{
		if (m_size == m_capacity) return;	// Full Exception
		
		m_arr[m_rIdx] = _elem;
		m_rIdx = (m_rIdx + 1) % m_capacity;
		m_size++;
	}

	T pop()
	{
		if (empty()) return -1;				// Empty Exception
		
		T result = m_arr[m_fIdx];
		m_fIdx = (m_fIdx + 1) % m_capacity;
		m_size--;

		return result;
	}

	T front()
	{
		if (empty()) return -1;				// Empty Exception

		return m_arr[m_fIdx];
	}

	T back()
	{
		if (empty()) return -1;				// Empty Exception

		return m_arr[(m_rIdx - 1 + m_capacity) % m_capacity];	// rear_Index�� 0�� ���� �����ϱ� ���� + m_capacity�� ���ݴϴ�.
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	Circular_Queue<int> queue(N);

	for (int n = 0; n < N; n++)
	{
		string command;
		cin >> command;
		if (command == "push")
		{
			int input;
			cin >> input;
			queue.push(input);
		}
		else if (command == "pop")
		{			
			cout << queue.pop() << '\n';
		}
		else if (command == "size")
		{
			cout << queue.size() << '\n';
		}
		else if (command == "empty")
		{
			cout << queue.empty() << '\n';
		}
		else if (command == "front")
		{
			cout << queue.front() << '\n';
		}
		else
		{
			cout << queue.back() << '\n';
		}
	}
}


/* -------------- ���ϴ� PS�� ------------------ */
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N;
//	cin >> N;
//	int* queue = new int[N] {0};
//	int front = 0, rear = 0;
//	for (int n = 0; n < N; n++)
//	{
//		string command;
//		cin >> command;
//		if (command == "push")
//		{
//			int input;
//			cin >> input;
//			queue[rear++] = input;
//		}
//		else if (command == "pop")
//		{
//			cout << (rear - front == 0 ? -1 : queue[front++]) << '\n';
//		}
//		else if (command == "size")
//		{
//			cout << rear - front << '\n';
//		}
//		else if (command == "empty")
//		{
//			cout << (front == rear) << '\n';
//		}
//		else if (command == "front")
//		{
//			cout << (rear - front == 0 ? -1 : queue[front]) << '\n';
//		}
//		else
//		{
//			cout << (rear - front == 0 ? -1 : queue[rear - 1]) << '\n';
//		}
//	}
//}