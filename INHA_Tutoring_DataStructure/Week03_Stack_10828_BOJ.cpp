// 10828¹ø ½ºÅÃ

#include <iostream>
using namespace std;

class Stack
{
private:
	int* m_arr;
	int m_capacity;
	int m_top;

public:
	Stack(int _n = 0) : m_capacity(_n), m_top(-1)
	{
		m_arr = new int[_n];
	}
	~Stack() { delete[] m_arr; }

	void push(int _e)
	{
		if (m_top == m_capacity - 1) return; // Full Exception
		m_arr[++m_top] = _e;
	}

	int pop()
	{
		if (m_top < 0) return -1;	// Empty Exception
		return m_arr[m_top--];
	}

	int size() { return m_top + 1; }	// top_index + 1 == size

	bool empty() { return m_top == -1; }

	int top()
	{
		if (m_top < 0) return -1;	// Empty Exception
		return m_arr[m_top];
	}
};

int main()
{
	int N;
	cin >> N;
	Stack stack(N);
	for (int n = 0; n < N; n++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int param = 0;
			cin >> param;
			stack.push(param);
		}
		else if (cmd == "pop")
		{
			cout << stack.pop() << '\n';
		}
		else if (cmd == "size")
		{
			cout << stack.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << stack.empty() << '\n';
		}
		else if (cmd == "top")
		{
			cout << stack.top() << '\n';
		}
	}

	return 0;
}