/*
Vector
동적 배열인 벡터를 환형 배열로 구현하라. 이때, 다음과 같은 명령어들을 수행할 수 있어야 한다.
개발자가 벡터를 개발할 때 내부에 생성하는 벡터의 크기(용량)를 N이라고 하고, 사용자가 인식하는 크기를 n이라고 하자.
배열을 확장할 때는 항상 더블링 기법을 활용한다.
배열을 축소할 때는 N이 n/2보다 작거나 같을 경우(단, N이 2보다 작아지지 않는다) 축소한다.
벡터의 첫 용량은 2이다.
1)	at(i): i번째 값을 출력한다. 만약 해당하는 인덱스 값이 없는 경우(비어 있는 경우 포함) -1을 출력한다.
2)	set(i, x): i번째 값을 x로 바꾼다. 이때 해당하는 인덱스 값이 없는 경우(비어 있는 경우 포함) -1을 출력한다.
3)	insert(i, x): i번째 값에 x를 넣는다. i는 [0, n]의 범위에서 주어진다. 이때, 벡터가 비어있는 경우 -1을 출력한다.
4)	remove(i): i번째 값을 삭제한다. 이때 해당하는 인덱스 값이 없는 경우(비어 있는 경우 포함) -1을 출력한다.
5)	push_back(x): 배열의 맨 뒤에 x를 추가한다.
6)	GetSize(): 사용자가 인식하는 배열의 크기 n을 출력한다.
7)	empty(): 동적배열이 비어있는지 확인한다. 비어 있을 경우 1을, 아니면 0을 출력한다.
8)	print(): 배열의 모든 원소를 순차적으로 출력한다. 비어 있을 경우 -1을 출력한다.
* 입력
가장 첫 줄에는 명령어 입력의 수 N이 주어진다. N의 범위는 [0, 10,000]이다.
각 줄마다 명령어가 주어지며, 매개변수가 필요한 경우 공백으로 구분하여 주어진다.
이때, 벡터의 원소로 주어지는 숫자 x는 [0, 1,000] 사이의 정수이다.
*/

#include<iostream>
using namespace std;

class Vector
{
private:
	int* m_arr;
	int m_capacity;
	int m_size;
	int m_fIdx, m_rIdx;	// fIdx: 배열의 첫번째 원소, rIdx: 배열의 마지막 원소의 뒤

public:
	Vector() : m_capacity(2), m_size(0), m_fIdx(0), m_rIdx(0)
	{
		m_arr = new int[2];
	}
	~Vector() { delete[] m_arr; }

	bool empty()
	{
		return !m_size;
	}

	int at(int _idx)
	{
		if (empty() || _idx >= m_size)
			return -1;
		else
			return m_arr[(m_fIdx + _idx) % m_capacity];
	}

	void set(int _idx, int _x)
	{
		if (empty() || _idx >= m_size)
			cout << -1 << '\n';
		else
		{
			m_arr[(m_fIdx + _idx) % m_capacity] = _x;
		}
	}

	void doublingUp()
	{
		int* newArr = new int[m_capacity * 2];
		for (int i = 0; i < m_capacity; i++)
		{
			newArr[i] = m_arr[(m_fIdx + i) % m_capacity];
		}
		m_capacity *= 2;
		m_fIdx = 0;
		m_rIdx = m_size;
		delete[] m_arr;
		m_arr = newArr;
	}

	void doublingDown()
	{
		int* newArr = new int[m_capacity / 2];
		for (int i = 0; i < m_size; i++)
		{
			newArr[i] = m_arr[(m_fIdx + i) % m_capacity];
		}

		m_capacity /= 2;
		m_fIdx = 0;
		m_rIdx = m_size;
		delete[] m_arr;
		m_arr = newArr;
	}

	void insert(int _idx, int _x)
	{
		if (m_size == m_capacity)
			this->doublingUp();
		for (int i = m_size; i > _idx; i--)
		{
			m_arr[(m_fIdx + i) % m_capacity] = m_arr[(m_fIdx + i - 1) % m_capacity];
		}
		m_arr[(m_fIdx + _idx) % m_capacity] = _x;
		m_size++;
		m_rIdx = (m_rIdx + 1) % m_capacity;
	}

	void remove(int _idx)
	{
		if (empty() || _idx >= m_size)
			cout << -1 << '\n';
		else
		{
			cout << m_arr[(m_fIdx + _idx) % m_capacity] << '\n';

			for (int i = _idx; i < m_size - 1; i++)
			{
				m_arr[(m_fIdx + i) % m_capacity] = m_arr[(m_fIdx + i + 1) % m_capacity];
			}
			m_size--;
			if (m_rIdx == 0) m_rIdx = m_capacity;
			m_rIdx = (m_rIdx - 1) % m_capacity;

			if (m_size <= m_capacity / 2 && m_capacity > 2)
				this->doublingDown();
		}
	}

	void push_back(int _x)
	{
		if (m_size == m_capacity)
			this->doublingUp();
		m_arr[(m_rIdx++) % m_capacity] = _x;
		m_size++;
	}

	int getSize() { return m_size; }
	void print()
	{
		if (empty())
		{
			cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < m_size; i++)
		{
			cout << m_arr[(m_fIdx + i) % m_capacity] << ' ';
		}
		cout << '\n';
	}
};

int main()
{
	int N;
	cin >> N;

	Vector vec;
	for (int n = 0; n < N; n++)
	{
		string command;
		cin >> command;
		if (command == "at")
		{
			int param;
			cin >> param;
			cout << vec.at(param) << '\n';
		}
		else if (command == "set")
		{
			int param1, param2;
			cin >> param1 >> param2;
			vec.set(param1, param2);
		}
		else if (command == "insert")
		{
			int param1, param2;
			cin >> param1 >> param2;
			vec.insert(param1, param2);
		}
		else if (command == "remove")
		{
			int param;
			cin >> param;
			vec.remove(param);
		}
		else if (command == "push_back")
		{
			int param;
			cin >> param;
			vec.push_back(param);
		}
		else if (command == "getSize")
		{
			cout << vec.getSize() << '\n';
		}
		else if (command == "empty")
		{
			cout << vec.empty() << '\n';
		}
		else if (command == "print")
		{
			vec.print();
		}
	}
	return 0;
}