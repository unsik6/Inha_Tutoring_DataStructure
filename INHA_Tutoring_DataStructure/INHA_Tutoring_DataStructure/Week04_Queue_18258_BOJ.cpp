// 백준 18258 큐2 (튜터링용)

#include <iostream>
using namespace std;

template<typename T>				// 저번에 template가 어렵다는 학우가 있어서 template로 구현해보았습니다. 실제 문제에서는 T == int로 보시면 됩니다.
class Circular_Queue
{
private:
	T* m_arr;
	int m_capacity;
	int m_size;						// size를 별도로 관리하는 것은 꽤 편한 방법입니다.
									// 특히, 환형큐에서는 큐가 꽉 차있을 때와 비어있을 때의 front_index와 rear_index가 같기 때문에
									// 별도로 관리해주는 것이 편합니다.
									// 그렇지 않을 경우에는 의도했던 capacity보다 1개 크게 배열을 만들고, front 앞의 칸을 완충지대로 두어야 합니다.

	int m_fIdx = 0, m_rIdx = 0;		// 클래스의 멤버 변수 초기화는 이와 같이 진행할 수 있습니다.
									// 강의 노트에도 나오겠지만, 인덱스 규칙은 자기 맘대로 하되 결과만 같으면 됩니다.
									// 일반적인 iterator의 end 지점은 마지막 요소의 바로 뒤라서 저는 그렇게 구현하곤 합니다.

public:
	// 일반적으로 클래스 생성자에서 멤버 변수를 초기화합니다.
	Circular_Queue(int _cap) : m_fIdx(0), m_rIdx(0), m_size(0)
	{
		m_arr = new T[_cap];
		m_capacity = _cap;
	}
	~Circular_Queue() { delete[] m_arr; }	// 메모리 관리

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

		return m_arr[(m_rIdx - 1 + m_capacity) % m_capacity];	// rear_Index가 0일 때를 방지하기 위해 + m_capacity를 해줍니다.
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


/* -------------- 이하는 PS용 ------------------ */
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